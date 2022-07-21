#include <Windows.h>
#include <TlHelp32.h>

#include <iostream>
#include "getData_class.h"
#include "setData_class.h"
#include <string>


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


DWORD dwProcessId = 0x00F900, dwPid = 0;
HWND hWnd;


void start(  ) {

	ShellExecuteA( NULL, NULL, "mspaint", NULL, NULL, SW_MAXIMIZE );
	//ShowWindow();

}



INT main() {

	//start();
	
	HWND hWnd = FindWindow( NULL, "Name..." ); // Ищем HWND окна по имени
	ShowWindow( hWnd,SW_RESTORE );


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



/*int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd ) {





	return 0;


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

