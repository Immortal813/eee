#include "window_class.h"


void window_class::win_init() {

	// Возвращает дескриптор необходимого окна
	hWnd = FindWindow( NULL, TEXT( "Безымянный - Paint" ) );

	

	if ( hWnd == NULL ) {

		MessageBox( hWnd, TEXT( "Need open Paint" ), TEXT( "Error" ), MB_OK | MB_ICONSTOP );

		// Открывает необходимое окно
		ShellExecuteA( NULL, NULL, "mspaint", NULL, NULL, SW_MAXIMIZE );
		// Находим окно
		hWnd = FindWindow( NULL, TEXT( "Безымянный - Paint" ) );
		// Разворачивает окно, елси оно свернуто 
		ShowWindow( hWnd, SW_MAXIMIZE );
		// Функция делает активным необходимое окно
		SetForegroundWindow( hWnd );

	 }

	else {
	
		ShowWindow( hWnd, SW_RESTORE );
		// Функция делает активным необходимое окно
		SetForegroundWindow( hWnd );
	
	
	}
		
	Sleep( 3000 );
}

// Метод отправки дескритора окна 
HWND window_class::getWindow() {

	return hWnd;

}

//
void window_class::funcMain() {

	mouse_class mouse_cl( &hWnd );
	//mouse_cl.get_mouse_coordM_wind();
	//mouse_cl.get_mouse_coordCH_wind();
	//mouse_cl.get_mouse_coordA_wind();

	mouse_cl.mouse_test();
	//mouse_cl.mouse_click_relat();
	
	 
}