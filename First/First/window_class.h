#pragma once
#include <chrono>
#include <Windows.h>
#include <iostream>
#include <string.h>
#include "mouse_class.hpp"

class window_class {

private:

	HWND hWnd;

public:

	//BOOL init();
	void win_init();
	HWND getWindow();
	void funcMain();

};

