#include "DevicesManager.h"
#include "Defines.h"

SDCard2USB DevicesManager::m_sd;
HIDkeyboard DevicesManager::m_keyboard;

bool DevicesManager::beginKeyboard()
{
    return m_keyboard.begin();
}

bool DevicesManager::beginSD()
{
    bool init = m_sd.initSD(SD_SCK, SD_MISO, SD_MOSI, SD_CS);
    if(init)
    {
        m_sd.begin();
    }

    return init;
}