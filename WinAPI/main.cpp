#include<Windows.h>
#include"resource.h"

static char PlaceholderLogin[] = "Введите имя пользователя";
static char PlaceholderPassword[] = "Введите пароль";

static BOOL Login;
static BOOL Password;

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevINST, LPSTR lpCMdLine, INT nCmdShow)
{
	//MessageBox
	//(
	//	NULL,
	//	"HelloWinAPI!",
	//	"MassageBox",
	//	MB_YESNOCANCEL
	//	| MB_ICONERROR
	//	| MB_HELP
	//	| MB_DEFBUTTON3
	//	| MB_SYSTEMMODAL
	//	//| MB_RIGHT
	//);

	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);

	return 0;
}


BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static BOOL LoginFocus = FALSE;
	static BOOL PasswordFocus = FALSE;
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hIcon);
		//SetFocus(GetDlgItem(hwnd, IDC_EDIT_LOGIN));

		HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
		SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)PlaceholderLogin);

		HWND hEditPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);
		SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)PlaceholderPassword);

		Login = TRUE;
		Password = TRUE;

	}
	break;


	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_EDIT_LOGIN:
		{
			HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
			CHAR sz_buffer[256];
			SendMessage(hEditLogin, WM_GETTEXT, 256, (LPARAM)sz_buffer);

			if (HIWORD(wParam) == EN_SETFOCUS)
			{
				if (/*strcmp(sz_buffer, PlaceholderLogin*/ Login)
				{
					SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)"");
					Login = FALSE;
				}
			}
			else if (HIWORD(wParam) == EN_KILLFOCUS)
			{
				if (strlen(sz_buffer) == 0)
				{
					SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)PlaceholderLogin);
					Login = TRUE;
				}
			}
		}
		break;
		case IDC_EDIT_PASSWORD:
		{
			HWND hEditPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);
			CHAR sz_buffer[256];
			SendMessage(hEditPassword, WM_GETTEXT, 256, (LPARAM)sz_buffer);

			if (HIWORD(wParam) == EN_SETFOCUS)
			{
				if (Password)
				{
					SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)"");
					Password = FALSE;
				}
			}
			else if (HIWORD(wParam) == EN_KILLFOCUS)
			{
				if (strlen(sz_buffer) == 0)
				{
					SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)PlaceholderPassword);
					Password = TRUE;
				}
			}
		}
		break;
		case IDC_BUTTON_COPY:
		{
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
			HWND hEditPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);
			SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
		}
		break;
		case IDOK:
			MessageBox(NULL, "Была нажата кнопка 'OK'", "Info", MB_OK | MB_ICONINFORMATION);
			break;
		case IDCANCEL:
			EndDialog(hwnd, 0);
			break;
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
	}
	return FALSE;
}