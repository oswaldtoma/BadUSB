// Helper.h

#ifndef _HELPER_h
#define _HELPER_h

#include <cstddef>
#include <cstdint>

class Helper
{
public:
	static void copyArray(uint8_t* destination, uint8_t* source, uint16_t size);
	static void fillArrayWithValue(uint8_t* destination, uint16_t size, uint16_t value);
};

#endif

