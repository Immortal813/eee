#include <iostream>
#include "getData_class.h"
#include "setData_class.h"
#include <string>
#include <Windows.h>
#include <shellapi.h>

void start( std::string qwe ) {

	ShellExecuteA ( NULL, NULL, qwe.c_str(), NULL, NULL, SW_MAXIMIZE );

}


int main() {


	std::cout << "Start programm" << std::endl;

	start( "mspaint" );

	return 0;

}

