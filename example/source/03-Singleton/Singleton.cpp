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


// �� ���̾�α�
HWND     g_hDlg;

// �̹� ����ǰ� �ִ� �ν��Ͻ��� �ִ����� Ȯ���ϱ� ���� ���ؽ�, �ٿ����, ���ӽ����̽�
HANDLE   g_hSingleton = NULL;
HANDLE   g_hBoundary = NULL;
HANDLE   g_hNamespace = NULL;

// ���ӽ����̽��� �����Ǿ����� Ȥ�� ������ ���� ���µǾ������� ���θ� ����
BOOL     g_bNamespaceOpened = FALSE;

// �ٿ���� �̸��� �����̺�Ʈ ���ӽ����̽� �̸�
PCTSTR   g_szBoundary = TEXT("3-Boundary");
PCTSTR   g_szNamespace = TEXT("3-Namespace");


#define DETAILS_CTRL GetDlgItem(g_hDlg, IDC_EDIT_DETAILS)


///////////////////////////////////////////////////////////////////////////////


// 'Details' ����Ʈ ��Ʈ�ѿ� ���ڿ� �߰�
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
         // ����ڰ� Exit ��ư�� �����ų�
         // ESCAPE�� ���� ���̷��α׸� �������.
         EndDialog(hwnd, id);
         break;
   }
}


///////////////////////////////////////////////////////////////////////////////


void CheckInstances() {

   // �ٿ���� ��ũ���� ����
   g_hBoundary = CreateBoundaryDescriptor(g_szBoundary, 0);

   // ���� ������ �׷�� ������ SID(Security Identifier)�� ����
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
   
   // ���� ������ SID���� �ٿ���� ��ũ���Ϳ� �߰���.
   // --> ���� ������ �������� ���ø����̼��� ����� ��쿡��
   //     ���� ���ӽ����̽� ���� Ŀ�� ������Ʈ�� ������ ������.
   if (!AddSIDToBoundaryDescriptor(&g_hBoundary, pLocalAdminSID)) {
      AddText(TEXT("AddSIDToBoundaryDescriptor failed: %u\r\n"), 
         GetLastError());
      return;
   }

   // ���� �����ڸ��� ���� ���ӽ����̽� ����
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

   // ���� ��ũ���Ͱ� ����� �޸� ������ �����ϴ� ���� �ؾ�� �ȵȴ�.
   LocalFree(sa.lpSecurityDescriptor);


   // �����̺�Ʈ ���ӽ����̽� ���� ��� Ȯ��
   DWORD dwLastError = GetLastError();
   if (g_hNamespace == NULL) {
      // ������ �źεǴ� ��� �ƹ��͵� ���� ����
      // --> �� �ڵ�� ���� ������ ���� �Ͽ��� ����Ǿ�� �Ѵ�.
      if (dwLastError == ERROR_ACCESS_DENIED) {
         AddText(TEXT("Access denied when creating the namespace.\r\n"));
         AddText(TEXT("   You must be running as Administrator.\r\n\r\n"));
         return;
      } else { 
         if (dwLastError == ERROR_ALREADY_EXISTS) {
         // ���� �ٸ� �ν��Ͻ��� ������ ���ӽ����̽��� �̹� �����ߴٸ�,
         // ������ ���ӽ����̽��� �����Ѵ�.
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
   
   // �����̺�Ʈ ���ӽ����̽��� �����
   // ���ؽ� ������Ʈ�� �����Ѵ�.
   TCHAR szMutexName[64];
   StringCchPrintf(szMutexName, _countof(szMutexName), TEXT("%s\\%s"), 
      g_szNamespace, TEXT("Singleton"));

   g_hSingleton = CreateMutex(NULL, FALSE, szMutexName);
   if (GetLastError() == ERROR_ALREADY_EXISTS) {
      // �̹� �̱��� ������Ʈ�� �ν��Ͻ��� �����Ѵ�.
      AddText(TEXT("Another instance of Singleton is running:\r\n"));
      AddText(TEXT("--> Impossible to access application features.\r\n"));
   } else  {
      // �̱��� ������Ʈ�� ���ʷ� ���������.
      AddText(TEXT("First instance of Singleton:\r\n"));
      AddText(TEXT("--> Access application features now.\r\n"));
   }
}


///////////////////////////////////////////////////////////////////////////////


BOOL Dlg_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam) {

   chSETDLGICONS(hwnd, IDI_SINGLETON);

   // �� ���̾�α� ������ �ڵ� ����.
   g_hDlg = hwnd;

   // �ٸ� �ν��Ͻ��� ���� ������ ���θ� Ȯ��
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

   // �� �����츦 ������
   DialogBox(hInstance, MAKEINTRESOURCE(IDD_SINGLETON), NULL, Dlg_Proc);

   // Ŀ�� ���ҽ��� �����ϴ� ���� ��������.
   if (g_hSingleton != NULL) {
      CloseHandle(g_hSingleton);
   }

   if (g_hNamespace != NULL) {
      if (g_bNamespaceOpened) {  // ���ӽ����̽��� �����ߴ°�?
         ClosePrivateNamespace(g_hNamespace, 0);
      } else { // ���ӽ����̽� �����Ͽ��°�>
         ClosePrivateNamespace(g_hNamespace, PRIVATE_NAMESPACE_FLAG_DESTROY);
      }
   }

   if (g_hBoundary != NULL) {
      DeleteBoundaryDescriptor(g_hBoundary);
   }

   return(0);
}


//////////////////////////////// End of File //////////////////////////////////
