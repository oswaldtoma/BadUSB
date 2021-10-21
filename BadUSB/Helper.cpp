#include "Helper.h"

void Helper::copyArray(uint8_t* destination, uint8_t* source, uint16_t size)
{
	for (uint8_t i = 0; i < size; i++)
	{
		destination[i] = source[i];
	}
}

void Helper::fillArrayWithValue(uint8_t* destination, uint16_t size, uint16_t value)
{
	for (uint16_t i = 0; i < size; i++)
	{
		destination[i] = value;
	}
}
