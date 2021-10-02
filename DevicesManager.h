#include "Defines.h"
#include "USB.h"
#include "USBHIDKeyboard.h"
#include "SD.h"
#include "SPI.h"
#include "USBMSC.h"

class DevicesManager
{
public:
    static bool beginKeyboard();
    static bool beginSD();
    static void allDevicesReady();

    static USBHIDKeyboard* getKeyboard() { return &m_keyboard; }

private:
    static int32_t onWrite(uint32_t lba, uint32_t offset, uint8_t* buffer, uint32_t bufsize);
    static int32_t onRead(uint32_t lba, uint32_t offset, void* buffer, uint32_t bufsize);
    static bool onStartStop(uint8_t power_condition, bool start, bool load_eject);

    static USBHIDKeyboard m_keyboard;
    static USBMSC m_msc;
    static SPIClass m_spi;
};