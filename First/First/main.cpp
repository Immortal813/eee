#include <iostream>
#include "getData_class.h"
#include "setData_class.h"
#include <vector>
#include <thread>
#include <string>
#include <mutex>
#include <queue>

std::queue<int> firstQue;
std::mutex m;

int main() {




	return 0;

}


//void run( std::string threadName ) {
//
//	for ( int i = 0; i < 10; i++ ) {
//	
//		std::string out = threadName + std::to_string( i ) + "\n";
//		std::cout << out;
//		
//	}
//
//}
//
//
//int main()
//{
//	
//	std::thread tA( run, "A" );
//	std::thread tB( run, "\tB" );
//	tA.join();
//	tB.join();
//	//setData_class setData;
//	
//	//std::vector <setData_class> setData;
//
//	/*setData_class *qwe = new setData_class[];
//
//	delete[] qwe;*/
//	
//	
//
//	return 0;
//}
