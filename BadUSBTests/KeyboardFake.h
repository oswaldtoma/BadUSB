#pragma once

#include "../BadUSB/IKeyboard.h"

class KeyboardFake : public IKeyboard
{
public:
	virtual void begin() override;
	virtual void end() override;
	virtual size_t write(uint8_t k) override;
	virtual size_t write(const uint8_t* buffer, size_t size) override;
	virtual size_t press(uint8_t k) override;
	virtual size_t release(uint8_t k) override;
	virtual void releaseAll(void) override;
	virtual size_t pressRaw(uint8_t k) override;
	virtual size_t releaseRaw(uint8_t k) override;

	virtual uint8_t getPressedKey(uint16_t index) { return pressedButtons[index]; }

private:
	uint8_t pressedButtons[100];
	uint16_t pressIndex = 0;
};

