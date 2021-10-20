#include "IKeyboard.h"
#include "USBHIDKeyboard.h"

class USBHIDKeyboardWrapper : public IKeyboard
{
public:
    void begin();
    void end();

    size_t write(uint8_t k);

    size_t write(const uint8_t* buffer, size_t size);
    size_t press(uint8_t k);
    size_t release(uint8_t k);
    void releaseAll(void);

    size_t pressRaw(uint8_t k);
    size_t releaseRaw(uint8_t k);

private:
    USBHIDKeyboard m_keyboard;
};

