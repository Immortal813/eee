#pragma once
#include <cstdint>

class setData_class {

private: 

	char data_arr[ 128 ];

public:

	//Метод передачи данных, возвращает 0 в случае неудачи
	uint8_t setData( ); 

};

