#include "sdusb.h"
#include "hidkeyboard.h"

class DevicesManager
{
public:
    static void beginKeyboard();
    static void beginSD();

    static HIDkeyboard* getKeyboard() { return &m_keyboard; }

private:
    static SDCard2USB m_sd;
    static HIDkeyboard m_keyboard;
};