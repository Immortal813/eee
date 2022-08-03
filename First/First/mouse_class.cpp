#include "mouse_class.hpp"

// ����� ����� ��������� � ����� ����� �� �����. ����� ������ �������� � ����������� -> ���������� -> �������

 mouse_class::mouse_class( HWND *hWnd ) {

	 _window_handle = *hWnd;

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

//������ ��������� ������������ ����
void mouse_class::get_mouse_coordWind() {

	while ( 1 ) {

		GetCursorPos( &_mouse_pos );
		ScreenToClient( _window_handle, &_mouse_pos );
		std::cout << "X: " << _mouse_pos.x << std::endl << "Y: " << _mouse_pos.y << std::endl;
		std::cout << "==================" << std::endl;
		Sleep( 2000 );

	}

}


// ����� ��������� ����� 
void mouse_class::mouse_click() {

	SetCursorPos( 27, 44 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 27, 44, 0, 0 );
	//=========
	Sleep( 300 );
	SetCursorPos( 66, 435 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 66, 435, 0, 0 );
	
	//=========
	Sleep( 300 );
	SetCursorPos( 845, 655 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 845, 655, 0, 0 );
	
	//=========
	Sleep( 300 );
	SetCursorPos( 995, 642 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 995, 642, 0, 0 );
	//=========
	Sleep( 300 );
	SetCursorPos( 537, 74 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 537, 74, 0, 0 );
	//=========������
	SetCursorPos( 425, 307 );
	mouse_event( MOUSEEVENTF_LEFTDOWN, 425, 307, 0, 0 );
	//=========���������
	SetCursorPos( 635, 517 );
	mouse_event( MOUSEEVENTF_LEFTUP, 635, 517, 0, 0 );

}

// ����� ������������ ����

void mouse_class::mouse_click_relat() {

	ClientToScreen( _window_handle, &_mouse_pos );

	SetCursorPos( 27, 44 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 27, 44, 0, 0 );
	//=========

	Sleep( 500 );
	SetCursorPos( 66, 435 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 66, 435, 0, 0 );
	//=========

	Sleep( 500 );
	SetCursorPos( 845, 655 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 845, 655, 0, 0 );
	//=========

	Sleep( 500 );
	SetCursorPos( 995, 662 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 995, 662, 0, 0 );
	//=========

	Sleep( 500 );
	SetCursorPos( 537, 70 );
	Sleep( 100 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 537, 70, 0, 0 );

	//=========������
	SetCursorPos( 425, 307 );
	mouse_event( MOUSEEVENTF_LEFTDOWN, 425, 307, 0, 0 );
	//=========���������

	SetCursorPos( 635, 517 );
	mouse_event( MOUSEEVENTF_LEFTUP, 635, 517, 0, 0 );

}