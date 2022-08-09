#include "mouse_class.hpp"

// ����� ����� ��������� � ����� ����� �� �����. ����� ������ �������� � ����������� -> ���������� -> �������

 mouse_class::mouse_class( HWND *hWnd ) {

	 _window_handle = *hWnd;

}

 // ���������� ������
void mouse_class::get_mouse_ScreenCoord()
{
	
	while ( 1 ) {
	
		GetCursorPos( &_mouse_pos );
		std::cout << "X: " << _mouse_pos.x << std::endl << "Y: " << _mouse_pos.y << std::endl;
		std::cout << "==============================";
		Sleep( delay_millisec );
		
		
	}

}

//������ ��������� �������� ����
void mouse_class::get_mouse_coordM_wind() {

	while ( 1 ) {

		GetCursorPos( &_mouse_pos );
		ScreenToClient( _window_handle, &_mouse_pos ); // ������� ���� 
		//ScreenToClient( FindWindowEx( _window_handle, NULL, NULL, NULL ), &_mouse_pos ); // ��� ����
		//ScreenToClient( GetForegroundWindow(), &_mouse_pos ); //GetForget - �������� ���������� ��������� ����
		//ScreenToClient( GetWindow( _window_handle, GW_CHILD ), &_mouse_pos ); // ���� �������� ����, �� ����������, �����.
		std::cout << "================== Main Win" << std::endl;
		std::cout << "X: " << _mouse_pos.x << std::endl << "Y: " << _mouse_pos.y << std::endl;
		
		Sleep( 2000 );
		 
	}

}

// ��������� ����
void mouse_class::get_mouse_coordA_wind() {

	while ( 1 ) {
	
		GetCursorPos( &_mouse_pos );
		ScreenToClient( GetForegroundWindow(), &_mouse_pos ); // ��������� ��������� ������� ������������ ��������� ����
		std::cout << "================= Active Wind" << std::endl;
		std::cout << "X: " << _mouse_pos.x << std::endl << "Y: " << _mouse_pos.y << std::endl;
		
		Sleep( 2000 );
	
	}

}

// ���������� ��������� ����
void mouse_class::get_mouse_coordCH_wind() {

	while ( 1 ) {

		GetCursorPos( &_mouse_pos );
		//ScreenToClient( _window_handle, &_mouse_pos );
		//ScreenToClient( FindWindowEx( _window_handle, NULL, NULL, NULL ), &_mouse_pos ); // ��� ����
		//ScreenToClient( GetForegroundWindow(), &_mouse_pos ); //GetForget - �������� ���������� ��������� ����
		std::cout << "================== Child Wind" << std::endl;
		ScreenToClient( GetWindow( _window_handle, GW_CHILD ), &_mouse_pos ); // ���� �������� ����, �� ����������, �����.
		std::cout << "X: " << _mouse_pos.x << std::endl << "Y: " << _mouse_pos.y << std::endl;
		
		Sleep( 2000 );

	}

}

// ����� ��������� ���� 
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


void mouse_class::mouse_test() {

	_mouse_pos = { 29, 49 };


}

// ����� ������������ ����
void mouse_class::mouse_click_relat() {
	
	//���� ����
	_mouse_pos = { 27, 44 };
	ClientToScreen( _window_handle, &_mouse_pos );
	SetCursorPos( _mouse_pos.x, _mouse_pos.y );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, _mouse_pos.x, _mouse_pos.y, 0, 0 );
	Sleep( 3000 );
	//=========

	//��������
	Sleep( 500 );
	_mouse_pos = { 66, 435 };
	ClientToScreen( _window_handle, &_mouse_pos );
	SetCursorPos( _mouse_pos.x, _mouse_pos.y );

	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, _mouse_pos.x, _mouse_pos.y, 0, 0 );
	//=========

	//�� ����������
	Sleep( 500 );
	_mouse_pos = { 845, 655 };
	ClientToScreen( _window_handle, &_mouse_pos );
	//ScreenToClient( FindWindowExA( _window_handle, NULL, NULL, NULL ), &_mouse_pos );
	SetCursorPos( _mouse_pos.x, _mouse_pos.y );
	
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, _mouse_pos.x, _mouse_pos.y, 0, 0 );
	//=========

	//��
	Sleep( 500 );
	_mouse_pos = { 955, 662 };
	ClientToScreen( _window_handle, &_mouse_pos );
	//ScreenToClient( FindWindowExA( _window_handle, NULL, NULL, NULL ), &_mouse_pos );
	SetCursorPos( _mouse_pos.x, _mouse_pos.y );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, _mouse_pos.x, _mouse_pos.y, 0, 0 );
	//=========

	//����
	Sleep( 500 );
	_mouse_pos = { 537, 70 };
	SetCursorPos( _mouse_pos.x, _mouse_pos.y );
	ClientToScreen( _window_handle, &_mouse_pos );
	Sleep( 100 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, _mouse_pos.x, _mouse_pos.y, 0, 0 );

	//=========������
	_mouse_pos = { 425, 307 };
	SetCursorPos( _mouse_pos.x, _mouse_pos.y );
	ClientToScreen( _window_handle, &_mouse_pos );
	mouse_event( MOUSEEVENTF_LEFTDOWN, _mouse_pos.x, _mouse_pos.y, 0, 0 );

	//=========���������
	_mouse_pos = { 635, 517 };
	ClientToScreen( _window_handle, &_mouse_pos );
	SetCursorPos( _mouse_pos.x, _mouse_pos.y );
	mouse_event( MOUSEEVENTF_LEFTUP, _mouse_pos.x, _mouse_pos.y, 0, 0 );
	Sleep( 200 );

	//========= ������� ����
	_mouse_pos = { 956, 70 };
	ClientToScreen( _window_handle, &_mouse_pos );
	SetCursorPos( _mouse_pos.x, _mouse_pos.y );
	mouse_event( MOUSEEVENTF_LEFTDOWN, _mouse_pos.x, _mouse_pos.y, 0, 0 );
	mouse_event( MOUSEEVENTF_LEFTUP, _mouse_pos.x, _mouse_pos.y, 0, 0 );


}