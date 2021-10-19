#include "USBHIDKeyboardWrapper.h"

void USBHIDKeyboardWrapper::begin()
{
	m_keyboard.begin();
}

void USBHIDKeyboardWrapper::end()
{
	m_keyboard.end();
}

size_t USBHIDKeyboardWrapper::write(uint8_t k)
{
	return m_keyboard.write(k);
}

size_t USBHIDKeyboardWrapper::write(const uint8_t* buffer, size_t size)
{
	return m_keyboard.write(buffer, size);
}

size_t USBHIDKeyboardWrapper::press(uint8_t k)
{
	return m_keyboard.press(k);
}

size_t USBHIDKeyboardWrapper::release(uint8_t k)
{
	return m_keyboard.release(k);
}

void USBHIDKeyboardWrapper::releaseAll(void)
{
	m_keyboard.releaseAll();
}

size_t USBHIDKeyboardWrapper::pressRaw(uint8_t k)
{
	return m_keyboard.pressRaw(k);
}

size_t USBHIDKeyboardWrapper::releaseRaw(uint8_t k)
{
	return m_keyboard.releaseRaw(k);
}
