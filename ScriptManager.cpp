#include "ScriptManager.h"
#include "ScriptLang.h"

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
    
    uint8_t buffer[30];
    file.read(buffer, 30);

    Serial.printf("rowCount: %d\n", getRowCount(buffer, 30));

    for (uint8_t i = 0; i < 30; i++)
    {
        Serial.printf("Byte: %c\n", buffer[i]);
    }
}

uint16_t ScriptManager::getRowCount(uint8_t* buffer, uint16_t buffSize)
{
    uint16_t rowCount = 0;

    for (uint8_t i = 0; i < buffSize; i++)
    {
        bool windowsLineBreak = buffer[i] == '\r' && buffer[i + 1] == '\n';
        bool unixLineBreak = buffer[i] == '\n';

        bool endOfFile = i + 1 == buffSize;
        bool endOfLine = windowsLineBreak || unixLineBreak || endOfFile;

        if (endOfLine)
        {
            if (windowsLineBreak)
            {
                i++;
            }

            rowCount++;
        }          
    }

    return rowCount;
}

void ScriptManager::getRows(Row* rowArray, uint16_t arrSize)
{
    for (uint8_t i = 0; i < arrSize; i++)
    {

    }
}

ScriptManager::Row ScriptManager::getRow(uint8_t* buffer, uint16_t buffSize)
{
    Row row;

    for (uint8_t i = 0; i < buffSize; i++)
    {
        row.rowArray[i]; //todo
    }
}
