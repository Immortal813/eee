#include "window_class.h"


window_class::window_class() {

	// ���������� ���������� ������������ ����
	hWnd = FindWindow( NULL, TEXT( "���������� - Paint" ) );

	// �������� ���������� ������ ���� 
	mouse_class mouse_a( &hWnd );

	if ( hWnd == NULL ) {

		MessageBox( hWnd, TEXT( "Need open Paint" ), TEXT( "Error" ), MB_OK | MB_ICONSTOP );
		

	 }
	else {

		//������������� ����, ���� ��� �������� 
		ShowWindow( hWnd, SW_RESTORE );
		//������� ������ �������� ����������� ����
		SetForegroundWindow( hWnd );
		
	}

	

}

// ����� �������� ���������� ���� 
HWND window_class::getWindow() {

	return hWnd;

}

//
void window_class::funcMain() {

	 

}