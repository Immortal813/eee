#include "window_class.h"


window_class::window_class() {
	
	
	hWnd = FindWindow( NULL, TEXT( "Безымянный - Paint" ) );

	
	if ( hWnd == NULL ) {

		MessageBox( hWnd, TEXT( "Need open Paint" ), TEXT( "Error" ), MB_OK | MB_ICONSTOP );
		

	}
	else {
		//Разворачивает окно, елси оно свернуто 
		ShowWindow( hWnd, SW_RESTORE );
		//Функция делает активным необходимое окно
		SetForegroundWindow( hWnd );
		

	}

	

}

HWND window_class::getWindow() {

	return hWnd;

}