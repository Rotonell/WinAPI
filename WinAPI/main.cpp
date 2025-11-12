#include<Windows.h>
#include"resource.h"

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hIstance, HINSTANCE hPrevINST, LPSTR lpCMdLine, INT nCmdShow)
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

	DialogBoxParam(hIstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);

	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
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