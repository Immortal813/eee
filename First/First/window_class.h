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
	window_class();
	HWND getWindow();
	void funcMain();

};

