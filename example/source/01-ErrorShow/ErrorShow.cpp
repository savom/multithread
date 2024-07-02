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
      // ���� �ڵ� ȹ��(����Ʈ ��Ʈ�ѷκ��� �����ڵ带 ���ڷ� ������)
      DWORD dwError = GetDlgItemInt(hwnd, IDC_ERRORCODE, NULL, FALSE);

      HLOCAL hlocal = NULL;   // ���� �޽��� �ؽ�Ʈ�� �����ϱ� ���� ����(�޸� ���� ����ų �ڵ��� NULL�� �ʱ�ȭ)
      // FormatMessage �Լ��� ���������� �ʿ��� �޸� ����� ���� �Ҵ��ϰ� �̸� ����Ű�� �ڵ��� ��ȯ�� �� �ִ�.

      // ������ �޽��� ���ڿ��� ��� ���� �⺻ �ý��� ���� ������ ���.
      // ����: �Ʒ��� MAKELANGID�� 0 ���� ��ȯ�Ѵ�.
      DWORD systemLocale = MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL);

      // ���� �ڵ��� �޽��� �ؽ�Ʈ�� �����´�.
      BOOL fOk = FormatMessage(
         FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS |
         FORMAT_MESSAGE_ALLOCATE_BUFFER, 
         NULL, dwError, systemLocale, 
         (PTSTR) &hlocal, 0, NULL);
      /* FORMAT_MESSAGE_FROM_SYSTEM : ForMatMessage�� ȣ���� �� FORMAT_MESSAGE_FROM_SYSTEM �÷��׸� ������ �� �ְ�,
       �� �÷��״� �ü���� �����ϰ� �ִ� ���� �ڵ�� �����Ǵ� �޽��� �ؽ�Ʈ�� ����� �Ѵٴ� ���� �˸��� ��Ȱ.*/

      /* FORMAT_MESSAGE_ALLOCATE_BUFFER �÷��״� ���� �޽��� �ؽ�Ʈ�� ������ �� �ִ� ����� �޸� ������ �Ҵ��� �� ���� ��û�Ѵ�.
      �Ҵ�� �޸� ����� ����Ű�� �ڵ��� hlocal ������ ���� ��ȯ�ȴ�.*/

      /* FORMAT_MESSAGE_IGNORE_INSERTS�� �޽��� �ؽ�Ʈ�� %�� �����ϴ� �ڸ� ǥ���ڸ� �������� ������ �������� ���� ���� �����ϴ� �÷��״�.
      �ڸ� ǥ���ڴ� ��Ȳ�� �´� �߰� ������ �����ϱ� ���� �ַ� ���ȴ�. 
      �� �÷��׸� ���ڷ� �������� �������� �ڸ� ǥ���ڿ� ��Ÿ�� ������ Arguments �Ű������� ���� �����ؾ� ��.*/

      /*dwError�� ���� �ڵ带 ����.*/

      /*systemLocale�� � ���� ������ �޽��� �ؽ�Ʈ�� ����� �ϴ����� �����ϴ� ��� �ĺ��ڸ� �����ϸ� ��.
      ��� �ĺ��ڴ� �� ���� ��� ���� ������� �����Ǵµ�, ����� �ü���� �⺻ ��� ������ ���� ���� ���� 0�� ������ ���� ����.
      ���� � ����� �ü���� ��ġ�Ǿ� �ִ����� �̸� �� �� ���ٸ� �� ���� Ư�� �� �����ϵ��� hard-coding �ؼ��� �ȵȴ�.*/





      if (!fOk) {
         // ��Ʈ��ũ�� ���õ� �����ΰ�?
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
