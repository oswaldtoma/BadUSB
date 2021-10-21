#include "ScriptManager.h"
#include "ScriptLang.h"
#include "Helper.h"

IKeyboard* ScriptManager::m_keyboard = nullptr;

void ScriptManager::init(IKeyboard* keyboard)
{
    m_keyboard = keyboard;
}

void ScriptManager::executeScript(uint8_t* rawBytes, uint16_t size)
{
    Row rows[50] = { { 0 }, 0 };
    getRows(rawBytes, size, rows, 50);
}

uint16_t ScriptManager::getRowCount(uint8_t* buffer, uint16_t buffSize)
{
    uint16_t rowCount = 0;

    for (uint16_t i = 0; i < buffSize; i++)
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

void ScriptManager::getRows(uint8_t* rawBytesArr, uint16_t rawBytesArrSize, Row* rowArray, uint16_t rowArrSize)
{
    uint16_t nextEmptyRow = 0;

    char buffer[50] = { '\0' };
    uint16_t bufferIndex = 0;

    for (uint16_t i = 0; i <= rawBytesArrSize; i++)
    {
        bool windowsLineBreak = rawBytesArr[i] == '\r' && rawBytesArr[i + 1] == '\n';
        bool unixLineBreak = rawBytesArr[i] == '\n';

        bool endOfFile = i == rawBytesArrSize;
        bool endOfLine = windowsLineBreak || unixLineBreak || endOfFile;

        if (endOfLine)
        {          
            Helper::copyArray(rowArray[nextEmptyRow].rowArray, (uint8_t*)buffer, bufferIndex);
            rowArray[nextEmptyRow].rowLength = bufferIndex;

            Helper::fillArrayWithValue((uint8_t*)buffer, (uint8_t)50, (uint8_t)0);
            bufferIndex = 0;
            nextEmptyRow++;

            if (windowsLineBreak)
            {
                i++; //skip \r
            }

            continue; //begin processing next row
        }

        buffer[bufferIndex] = rawBytesArr[i];
        bufferIndex++;
    }
}