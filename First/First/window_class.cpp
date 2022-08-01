#include "window_class.h"


window_class::window_class() {

	// Возвращает дескриптор необходимого окна
	hWnd = FindWindow( NULL, TEXT( "Безымянный - Paint" ) );

	// Создание экземпляра класса мыши 
	mouse_class mouse_a( &hWnd );

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

// Метод отправки дескритора окна 
HWND window_class::getWindow() {

	return hWnd;

}

//
void window_class::funcMain() {

	 

}