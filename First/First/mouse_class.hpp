#pragma once
#include <chrono>
#include <Windows.h>
#include <iostream>
#include "window_class.h"

class mouse_class {

public:

	void get_mouse_ScreenCoord();
	void get_mouse_coordA_wind();
	void get_mouse_coordM_wind();
	void get_mouse_coordCH_wind();
	void mouse_click();
	void mouse_click_relat();
	void mouse_test();
	mouse_class( HWND *hWnd );

private:
	
	int delay_millisec = 300;
	HWND _window_handle;
	POINT _mouse_pos;
	// Я блять не разобался с задержкой потока, пока слищъком сложно. Чуть попозже попробую. Penis.
	//std::chrono::milliseconds _mouse_click_delay;
	

};

