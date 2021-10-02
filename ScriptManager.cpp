#include "ScriptManager.h"

fs::FS* ScriptManager::m_filesystem = nullptr;
USBHIDKeyboard* ScriptManager::m_keyboard = nullptr;

void ScriptManager::init(fs::FS* filesystem, USBHIDKeyboard* keyboard)
{
    m_filesystem = filesystem;
    m_keyboard = keyboard;
}

void ScriptManager::executeScript()
{
    if(!m_filesystem || !m_filesystem->exists("/script.txt"))
    {
        return;
    }

    File file = m_filesystem->open("/script.txt", FILE_READ);
    
    uint8_t buffer[20];
    file.read(buffer, 20);

    for(uint8_t i = 0; i < 20; i++)
    {
        Serial.printf("byte: %c\n", buffer[i]);
    }
}
