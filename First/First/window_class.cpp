#include "window_class.h"


void window_class::win_init() {

	// ���������� ���������� ������������ ����
	hWnd = FindWindow( NULL, TEXT( "���������� - Paint" ) );

	

	if ( hWnd == NULL ) {

		MessageBox( hWnd, TEXT( "Need open Paint" ), TEXT( "Error" ), MB_OK | MB_ICONSTOP );

		// ��������� ����������� ����
		ShellExecuteA( NULL, NULL, "mspaint", NULL, NULL, SW_MAXIMIZE );
		// ������� ����
		hWnd = FindWindow( NULL, TEXT( "���������� - Paint" ) );
		// ������������� ����, ���� ��� �������� 
		ShowWindow( hWnd, SW_RESTORE );
		// ������� ������ �������� ����������� ����
		SetForegroundWindow( hWnd );

	 }

	else {
	
		ShowWindow( hWnd, SW_RESTORE );
		// ������� ������ �������� ����������� ����
		SetForegroundWindow( hWnd );
	
	
	}
		

}

// ����� �������� ���������� ���� 
HWND window_class::getWindow() {

	return hWnd;

}

//
void window_class::funcMain() {

	mouse_class mouse_cl( &hWnd );
	mouse_cl.mouse_click_relat();
	 

}