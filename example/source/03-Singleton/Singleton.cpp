/******************************************************************************
Module:  Singleton.cpp
Notices: Copyright (c) 2008 Jeffrey Richter & Christophe Nasarre
******************************************************************************/


#include "resource.h"

#include "..\CommonFiles\CmnHdr.h"     /* See Appendix A. */
#include <windowsx.h>
#include <Sddl.h>          // for SID management
#include <tchar.h>
#include <strsafe.h>



///////////////////////////////////////////////////////////////////////////////


// 주 다이얼로그
HWND     g_hDlg;

// 이미 수행되고 있는 인스턴스가 있는지를 확인하기 위한 뮤텍스, 바운더리, 네임스페이스
HANDLE   g_hSingleton = NULL;
HANDLE   g_hBoundary = NULL;
HANDLE   g_hNamespace = NULL;

// 네임스페이스가 생성되었는지 혹은 정리를 이해 오픈되었는지의 여부를 저장
BOOL     g_bNamespaceOpened = FALSE;

// 바운더리 이름과 프라이비트 네임스페이스 이름
PCTSTR   g_szBoundary = TEXT("3-Boundary");
PCTSTR   g_szNamespace = TEXT("3-Namespace");


#define DETAILS_CTRL GetDlgItem(g_hDlg, IDC_EDIT_DETAILS)


///////////////////////////////////////////////////////////////////////////////


// 'Details' 에디트 컨트롤에 문자열 추가
void AddText(PCTSTR pszFormat, ...) {

   va_list argList;
   va_start(argList, pszFormat);

   TCHAR sz[20 * 1024];

   Edit_GetText(DETAILS_CTRL, sz, _countof(sz));
   _vstprintf_s(
      _tcschr(sz, TEXT('\0')), _countof(sz) - _tcslen(sz), 
      pszFormat, argList);
   Edit_SetText(DETAILS_CTRL, sz);
   va_end(argList);
}


///////////////////////////////////////////////////////////////////////////////


void Dlg_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify) {

   switch (id) {
      case IDOK:
      case IDCANCEL:
         // 사용자가 Exit 버튼을 눌렀거나
         // ESCAPE를 눌러 다이럴로그를 취소했음.
         EndDialog(hwnd, id);
         break;
   }
}


///////////////////////////////////////////////////////////////////////////////


void CheckInstances() {

   // 바운더리 디스크립터 생성
   g_hBoundary = CreateBoundaryDescriptor(g_szBoundary, 0);

   // 로컬 관리자 그룹과 연관된 SID(Security Identifier)값 생성
   BYTE localAdminSID[SECURITY_MAX_SID_SIZE];
   PSID pLocalAdminSID = &localAdminSID;
   DWORD cbSID = sizeof(localAdminSID);
   if (!CreateWellKnownSid(
      WinBuiltinAdministratorsSid, NULL, pLocalAdminSID, &cbSID)
      ) {
      AddText(TEXT("AddSIDToBoundaryDescriptor failed: %u\r\n"), 
         GetLastError());
      return;
   }
   
   // 로컬 관리자 SID값을 바운더리 디스크립터에 추가함.
   // --> 로컬 관리자 권한으로 애플리케이션이 수행될 경우에만
   //     동일 네임스페이스 내의 커널 오브젝트에 접근이 가능함.
   if (!AddSIDToBoundaryDescriptor(&g_hBoundary, pLocalAdminSID)) {
      AddText(TEXT("AddSIDToBoundaryDescriptor failed: %u\r\n"), 
         GetLastError());
      return;
   }

   // 로컬 관리자만을 위한 네임스페이스 생성
   SECURITY_ATTRIBUTES sa;
   sa.nLength = sizeof(sa);
   sa.bInheritHandle = FALSE;
   if (!ConvertStringSecurityDescriptorToSecurityDescriptor(
      TEXT("D:(A;;GA;;;BA)"), 
      SDDL_REVISION_1, &sa.lpSecurityDescriptor, NULL)) {
      AddText(TEXT("Security Descriptor creation failed: %u\r\n"), GetLastError());
      return;
   }

   g_hNamespace = 
      CreatePrivateNamespace(&sa, g_hBoundary, g_szNamespace);

   // 보안 디스크립터가 저장된 메모리 공간을 해제하는 것을 잊어서는 안된다.
   LocalFree(sa.lpSecurityDescriptor);


   // 프리이비트 네임스페이스 생성 결과 확인
   DWORD dwLastError = GetLastError();
   if (g_hNamespace == NULL) {
      // 접근이 거부되는 경우 아무것도 하지 않음
      // --> 이 코드는 로컬 관리자 계정 하에서 수행되어야 한다.
      if (dwLastError == ERROR_ACCESS_DENIED) {
         AddText(TEXT("Access denied when creating the namespace.\r\n"));
         AddText(TEXT("   You must be running as Administrator.\r\n\r\n"));
         return;
      } else { 
         if (dwLastError == ERROR_ALREADY_EXISTS) {
         // 만일 다른 인스턴스가 동일한 네임스페이스를 이미 생성했다면,
         // 생성된 네임스페이스를 오픈한다.
            AddText(TEXT("CreatePrivateNamespace failed: %u\r\n"), dwLastError);
            g_hNamespace = OpenPrivateNamespace(g_hBoundary, g_szNamespace);
            if (g_hNamespace == NULL) {
               AddText(TEXT("   and OpenPrivateNamespace failed: %u\r\n"), 
               dwLastError);
               return;
            } else {
               g_bNamespaceOpened = TRUE;
               AddText(TEXT("   but OpenPrivateNamespace succeeded\r\n\r\n"));
            }
         } else {
            AddText(TEXT("Unexpected error occured: %u\r\n\r\n"),
               dwLastError);
            return;
         }
      }
   }
   
   // 프라이비트 네임스페이스에 기반한
   // 뮤텍스 오브젝트를 생성한다.
   TCHAR szMutexName[64];
   StringCchPrintf(szMutexName, _countof(szMutexName), TEXT("%s\\%s"), 
      g_szNamespace, TEXT("Singleton"));

   g_hSingleton = CreateMutex(NULL, FALSE, szMutexName);
   if (GetLastError() == ERROR_ALREADY_EXISTS) {
      // 이미 싱글톤 오브젝트의 인스턴스가 존재한다.
      AddText(TEXT("Another instance of Singleton is running:\r\n"));
      AddText(TEXT("--> Impossible to access application features.\r\n"));
   } else  {
      // 싱글턴 오브젝트가 최초로 만들어졌다.
      AddText(TEXT("First instance of Singleton:\r\n"));
      AddText(TEXT("--> Access application features now.\r\n"));
   }
}


///////////////////////////////////////////////////////////////////////////////


BOOL Dlg_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam) {

   chSETDLGICONS(hwnd, IDI_SINGLETON);

   // 주 다이얼로그 윈도우 핸들 저장.
   g_hDlg = hwnd;

   // 다른 인스턴스가 수행 중인지 여부를 확인
   CheckInstances();
      
   return(TRUE);
}


///////////////////////////////////////////////////////////////////////////////


INT_PTR WINAPI Dlg_Proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

   switch (uMsg) {
      chHANDLE_DLGMSG(hwnd, WM_COMMAND,    Dlg_OnCommand);
      chHANDLE_DLGMSG(hwnd, WM_INITDIALOG, Dlg_OnInitDialog);
   }

   return(FALSE);
}


///////////////////////////////////////////////////////////////////////////////


int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
   UNREFERENCED_PARAMETER(hPrevInstance);
   UNREFERENCED_PARAMETER(lpCmdLine);

   // 주 윈도우를 보여줌
   DialogBox(hInstance, MAKEINTRESOURCE(IDD_SINGLETON), NULL, Dlg_Proc);

   // 커널 리소스를 삭제하는 것을 잊지마라.
   if (g_hSingleton != NULL) {
      CloseHandle(g_hSingleton);
   }

   if (g_hNamespace != NULL) {
      if (g_bNamespaceOpened) {  // 네임스페이스를 오픈했는가?
         ClosePrivateNamespace(g_hNamespace, 0);
      } else { // 네임스페이스 생성하였는가>
         ClosePrivateNamespace(g_hNamespace, PRIVATE_NAMESPACE_FLAG_DESTROY);
      }
   }

   if (g_hBoundary != NULL) {
      DeleteBoundaryDescriptor(g_hBoundary);
   }

   return(0);
}


//////////////////////////////// End of File //////////////////////////////////
