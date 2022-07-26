#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <string>
#include <chrono>
#include "mouse_class.hpp"


VOID PrintModuleList( HANDLE CONST hStdOut, DWORD CONST dwProcessId ) {
	MODULEENTRY32 meModuleEntry;
	TCHAR szBuff[ 1024 ];
	DWORD dwTemp;
	HANDLE CONST hSnapshot = CreateToolhelp32Snapshot(
		TH32CS_SNAPMODULE, dwProcessId );
	if ( INVALID_HANDLE_VALUE == hSnapshot ) {
		return;
	}

	meModuleEntry.dwSize = sizeof( MODULEENTRY32 );
	Module32First( hSnapshot, &meModuleEntry );
	do {
		wsprintf( szBuff, L"  ba: %08X, bs: %08X, %s\r\n",
				  meModuleEntry.modBaseAddr, meModuleEntry.modBaseSize,
				  meModuleEntry.szModule );
		WriteConsole( hStdOut, szBuff, lstrlen( szBuff ), &dwTemp, NULL );
	} while ( Module32Next( hSnapshot, &meModuleEntry ) );

	CloseHandle( hSnapshot );
}

VOID PrintProcessList( HANDLE CONST hStdOut ) {
	PROCESSENTRY32 peProcessEntry;
	TCHAR szBuff[ 1024 ];
	DWORD dwTemp;
	HANDLE CONST hSnapshot = CreateToolhelp32Snapshot(
		TH32CS_SNAPPROCESS, 0 );
	if ( INVALID_HANDLE_VALUE == hSnapshot ) {
		return;
	}

	peProcessEntry.dwSize = sizeof( PROCESSENTRY32 );
	Process32First( hSnapshot, &peProcessEntry );
	do {
		wsprintf( szBuff, L"=== %08X %s ===\r\n",
				  peProcessEntry.th32ProcessID, peProcessEntry.szExeFile );
		WriteConsole( hStdOut, szBuff, lstrlen( szBuff ), &dwTemp, NULL );
		PrintModuleList( hStdOut, peProcessEntry.th32ProcessID );
	} while ( Process32Next( hSnapshot, &peProcessEntry ) );

	CloseHandle( hSnapshot );
}


mouse_class glass;


/*void start(  ) {

	ShellExecuteA( NULL, NULL, "mspaint", NULL, NULL, SW_MAXIMIZE );
	//ShowWindow();

}*/

//Взятие координат мышки 
void mouseCoord() {
	
	POINT pt;
	while ( 1 ) {

		GetCursorPos( &pt );


		std::cout << "X: " << pt.x << "\n" << "Y: " << pt.y << std::endl;
		std::cout << "=========================" << std::endl;

		Sleep( 2000 );


	}

}

//Функция ищет и открывает неоходимое окно. Возвращает 0, если такого окна не существует.
bool findAndOpenWin() {

	HWND hWnd = FindWindow( NULL, TEXT( "Безымянный - Paint" ) );
	bool check;
	if ( hWnd == NULL ) {

		MessageBox( hWnd, TEXT( "Need open Paint" ), TEXT( "Error" ), MB_OK | MB_ICONSTOP );
		check = 0;
	}
	else {
		//Не отображает окно, если оно развернуто -_-
		ShowWindow( hWnd, SW_MAXIMIZE );
		check = 1;
	}

	return check;

}

void mouseClick() {

	SetCursorPos( 30, 33 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 30, 33, 0, 0 );
	//=========
	Sleep( 500 );
	SetCursorPos( 84, 423 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 84, 423, 0, 0 );
	Sleep( 500 );
	//=========
	SetCursorPos( 851, 654 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 851, 654, 0, 0 );
	Sleep( 500 );
	//=========
	SetCursorPos( 993, 658 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 993, 658, 0, 0 );
	//=========
	SetCursorPos( 530, 64 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 530, 64, 0, 0 );
	//=========ЗАЖАТЬ
	SetCursorPos( 316, 331 );
	mouse_event( MOUSEEVENTF_LEFTDOWN, 316, 331, 0, 0 );
	//=========ОТПУСТИТЬ
	SetCursorPos( 526, 449 );
	mouse_event( MOUSEEVENTF_LEFTUP, 30, 33, 0, 0 );
	//=========



}



int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd ) {

	findAndOpenWin();
	mouseClick();

	//start();

	//LPCWSTR WindowsName = ( LPCWSTR)"mspaint";


	//=================================
	/*HWND h = FindWindowA( NULL, "Калькулятор" ); // Ищем HWND окна по имени


	if ( h == NULL )
		MessageBox( h, TEXT( "Необходимо открыть \"Калькулятор\"" ), TEXT( "Ошибка!!!" ), MB_OK | MB_ICONSTOP );*/




		//SetCursorPos( 30, 33 );
		//mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 30, 33, 0, 0 );


		//==========================================
		//SetCursorPos(15, 15 );
		/*POINT pt, pt2, buff;
		while (1) {

			GetCursorPos( &pt );
			pt2 = pt;

			std::cout << "X: " << pt.x << "\n" << "Y: " << pt.y << std::endl;
			std::cout << "=========================" << std::endl;

			Sleep( 2000 );


		}*/

		//================================

		/*HANDLE CONST hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
		PrintProcessList( hStdOut );
		ExitProcess( 0 )*/;
	return 0;
}



/*int main() {

	mouseCoord();

}*/



/*void start( std::string qwe ) {

	ShellExecuteA( NULL, NULL, qwe.c_str(), NULL, NULL, SW_MAXIMIZE );

}

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd ) {


	//std::cout << "Start programm" << std::endl;

	start( "mspaint" );


	return 0;


}*/




//int main() {
//
//	
//
//	
//	return 0;
//
//}

