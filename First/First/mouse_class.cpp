#include "mouse_class.hpp"

// Метод вязть координат в вывод этого на экран. Нужно будеть поменять в Компановщик -> Подсистема -> Консоль

void mouse_class::set_mouseW( HWND *hWnd ) {



}


void mouse_class::get_mouse_coord()
{
	
	while ( 1 ) {
	
		GetCursorPos( &_mouse_pos );
		std::cout << "X: " << _mouse_pos.x << std::endl << "Y: " << _mouse_pos.y << std::endl;
		std::cout << "==============================";
		Sleep( delay_millisec );
		
		
	}

}

//Взятие координат относительно окна
void mouse_class::get_mouse_coordWind() {

	while ( 1 ) {

		GetCursorPos( &_mouse_pos );
		ScreenToClient( _window_handle, &_mouse_pos );
		std::cout << "X: " << _mouse_pos.x << std::endl << "Y: " << _mouse_pos.y << std::endl;
		std::cout << "==================" << std::endl;
		Sleep( 2000 );

	}

}


// Метод нажимания клвиш 
void mouse_class::mouse_click() {

	SetCursorPos( 27, 44 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 27, 44, 0, 0 );
	//=========
	Sleep( 500 );
	SetCursorPos( 66, 435 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 66, 435, 0, 0 );
	Sleep( 500 );
	//=========
	SetCursorPos( 756, 644 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 756, 644, 0, 0 );
	Sleep( 500 );
	//=========
	SetCursorPos( 905, 642 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 905, 642, 0, 0 );
	//=========
	SetCursorPos( 537, 74 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 537, 74, 0, 0 );
	//=========ЗАЖАТЬ
	SetCursorPos( 425, 307 );
	mouse_event( MOUSEEVENTF_LEFTDOWN, 425, 307, 0, 0 );
	//=========ОТПУСТИТЬ
	SetCursorPos( 635, 517 );
	mouse_event( MOUSEEVENTF_LEFTUP, 635, 517, 0, 0 );

}

// Клики относительно окна

void mouse_class::mouse_click_relat() {

	ClientToScreen( _window_handle, &_mouse_pos );

	SetCursorPos( 27, 44 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 27, 44, 0, 0 );
	//=========
	Sleep( 500 );
	SetCursorPos( 66, 435 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 66, 435, 0, 0 );
	Sleep( 500 );
	//=========
	SetCursorPos( 756, 644 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 756, 644, 0, 0 );
	Sleep( 500 );
	//=========
	SetCursorPos( 905, 642 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 905, 642, 0, 0 );
	//=========
	SetCursorPos( 537, 74 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 537, 74, 0, 0 );
	//=========ЗАЖАТЬ
	SetCursorPos( 425, 307 );
	mouse_event( MOUSEEVENTF_LEFTDOWN, 425, 307, 0, 0 );
	//=========ОТПУСТИТЬ
	SetCursorPos( 635, 517 );
	mouse_event( MOUSEEVENTF_LEFTUP, 635, 517, 0, 0 );

}