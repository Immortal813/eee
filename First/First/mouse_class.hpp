#pragma once
#include <chrono>
#include <Windows.h>
#include <iostream>
#include "window_class.h"

class mouse_class {

public:

	void get_mouse_coord();
	void get_mouse_coordWind();
	void mouse_click();
	void mouse_click_relat();
	void set_mouseW( HWND *hWnd );

private:
	
	int delay_millisec = 300;
	HWND _window_handle;
	POINT _mouse_pos;
	// � ����� �� ��������� � ��������� ������, ���� �������� ������. ���� ������� ��������. Penis.
	//std::chrono::milliseconds _mouse_click_delay;
	

};

