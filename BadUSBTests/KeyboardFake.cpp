#include "KeyboardFake.h"

void KeyboardFake::begin()
{
}

void KeyboardFake::end()
{
}

size_t KeyboardFake::write(uint8_t k)
{
    pressedButtons[pressIndex] = k;
    pressIndex++;
    return k;
}

size_t KeyboardFake::write(const uint8_t* buffer, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        pressedButtons[i] = buffer[i];
    }

    return size;
}

size_t KeyboardFake::press(uint8_t k)
{
    return size_t();
}

size_t KeyboardFake::release(uint8_t k)
{
    return size_t();
}

void KeyboardFake::releaseAll(void)
{
}

size_t KeyboardFake::pressRaw(uint8_t k)
{
    return size_t();
}

size_t KeyboardFake::releaseRaw(uint8_t k)
{
    return size_t();
}
