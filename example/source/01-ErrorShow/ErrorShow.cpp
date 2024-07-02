/******************************************************************************
Module:  ErrorShow.cpp
Notices: Copyright (c) 2008 Jeffrey Richter & Christophe Nasarre
******************************************************************************/


#include "..\CommonFiles\CmnHdr.h"     /* See Appendix A. */
#include <Windowsx.h>
#include <tchar.h>
#include "Resource.h"


///////////////////////////////////////////////////////////////////////////////


#define ESM_POKECODEANDLOOKUP    (WM_USER + 100)
const TCHAR g_szAppName[] = TEXT("Error Show");


///////////////////////////////////////////////////////////////////////////////


BOOL Dlg_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam) {

   chSETDLGICONS(hwnd, IDI_ERRORSHOW);

   // Don't accept error codes more than 5 digits long
   Edit_LimitText(GetDlgItem(hwnd, IDC_ERRORCODE), 5);

   // Look up the command-line passed error number
   SendMessage(hwnd, ESM_POKECODEANDLOOKUP, lParam, 0);
   return(TRUE);
}


///////////////////////////////////////////////////////////////////////////////


void Dlg_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify) {

   switch (id) {

   case IDCANCEL:
      EndDialog(hwnd, id);
      break;

   case IDC_ALWAYSONTOP:
      SetWindowPos(hwnd, IsDlgButtonChecked(hwnd, IDC_ALWAYSONTOP) 
         ? HWND_TOPMOST : HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
      break;

   case IDC_ERRORCODE: 
      EnableWindow(GetDlgItem(hwnd, IDOK), Edit_GetTextLength(hwndCtl) > 0);
      break;

   case IDOK:
      // 에러 코드 획득(에디트 컨트롤로부터 에러코드를 숫자로 가져옴)
      DWORD dwError = GetDlgItemInt(hwnd, IDC_ERRORCODE, NULL, FALSE);

      HLOCAL hlocal = NULL;   // 에러 메시지 텍스트를 저장하기 위한 버퍼(메모리 블럭을 가리킬 핸들을 NULL로 초기화)
      // FormatMessage 함수는 내부적으로 필요한 메모리 블록을 직접 할당하고 이를 가리키는 핸들을 반환할 수 있다.

      // 윈도우 메시지 문자열을 얻기 위해 기본 시스템 지역 설정을 사용.
      // 주의: 아래의 MAKELANGID는 0 값을 반환한다.
      DWORD systemLocale = MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL);

      // 에러 코드의 메시지 텍스트를 가져온다.
      BOOL fOk = FormatMessage(
         FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS |
         FORMAT_MESSAGE_ALLOCATE_BUFFER, 
         NULL, dwError, systemLocale, 
         (PTSTR) &hlocal, 0, NULL);
      /* FORMAT_MESSAGE_FROM_SYSTEM : ForMatMessage를 호출할 때 FORMAT_MESSAGE_FROM_SYSTEM 플래그를 전달할 수 있고,
       이 플래그는 운영체제가 정의하고 있는 에러 코드와 대응되는 메시지 텍스트를 얻고자 한다는 것을 알리는 역활.*/

      /* FORMAT_MESSAGE_ALLOCATE_BUFFER 플래그는 에러 메시지 텍스트를 저장할 수 있는 충분한 메모리 공간을 할당해 줄 것을 요청한다.
      할당된 메모리 블록을 가리키는 핸들은 hlocal 변수를 통해 반환된다.*/

      /* FORMAT_MESSAGE_IGNORE_INSERTS는 메시지 텍스트에 %로 시작하는 자리 표시자를 실질적인 값으로 변경하지 않을 것을 지정하는 플래그다.
      자리 표시자는 상황에 맞는 추가 정보를 제공하기 위해 주로 사용된다. 
      이 플래그를 인자로 전달하지 않으려면 자리 표시자에 나타날 정보를 Arguments 매개변수를 통해 전달해야 함.*/

      /*dwError는 에러 코드를 전달.*/

      /*systemLocale는 어떤 언어로 구성된 메시지 텍스트를 얻고자 하는지를 지정하는 언어 식별자를 전달하면 됨.
      언어 식별자는 두 가지 상수 값을 기반으로 구성되는데, 수행될 운영체제의 기본 언어 설정을 가져 오기 위해 0을 지정할 수도 있음.
      만약 어떤 언어의 운영체제가 설치되어 있는지를 미리 알 수 없다면 이 값을 특정 언어를 지정하도록 hard-coding 해서는 안된다.*/





      if (!fOk) {
         // 네트워크와 관련된 에러인가?
         HMODULE hDll = LoadLibraryEx(TEXT("netmsg.dll"), NULL, 
            DONT_RESOLVE_DLL_REFERENCES);

         if (hDll != NULL) {
            fOk = FormatMessage(
               FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_IGNORE_INSERTS |
               FORMAT_MESSAGE_ALLOCATE_BUFFER,
               hDll, dwError, systemLocale,
               (PTSTR) &hlocal, 0, NULL);
            FreeLibrary(hDll);
         }
      }

      if (fOk && (hlocal != NULL)) {
         SetDlgItemText(hwnd, IDC_ERRORTEXT, (PCTSTR) LocalLock(hlocal));
         LocalFree(hlocal);
      } else {
         SetDlgItemText(hwnd, IDC_ERRORTEXT, 
            TEXT("No text found for this error number."));
      }

      break;
   }
}


///////////////////////////////////////////////////////////////////////////////


INT_PTR WINAPI Dlg_Proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

   switch (uMsg) {
      chHANDLE_DLGMSG(hwnd, WM_INITDIALOG, Dlg_OnInitDialog);
      chHANDLE_DLGMSG(hwnd, WM_COMMAND,    Dlg_OnCommand);

   case ESM_POKECODEANDLOOKUP:
      SetDlgItemInt(hwnd, IDC_ERRORCODE, (UINT) wParam, FALSE);
      FORWARD_WM_COMMAND(hwnd, IDOK, GetDlgItem(hwnd, IDOK), BN_CLICKED, 
         PostMessage);
      SetForegroundWindow(hwnd);
      break;
   }

   return(FALSE);
}


///////////////////////////////////////////////////////////////////////////////


int WINAPI _tWinMain(HINSTANCE hinstExe, HINSTANCE, PTSTR pszCmdLine, int) {

   HWND hwnd = FindWindow(TEXT("#32770"), TEXT("Error Show"));
   if (IsWindow(hwnd)) {
      // An instance is already running, activate it and send it the new #
      SendMessage(hwnd, ESM_POKECODEANDLOOKUP, _ttoi(pszCmdLine), 0);
   } else {
      DialogBoxParam(hinstExe, MAKEINTRESOURCE(IDD_ERRORSHOW), 
         NULL, Dlg_Proc, _ttoi(pszCmdLine));
   }
   return(0);
}


//////////////////////////////// End of File //////////////////////////////////
