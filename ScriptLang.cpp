#include "ScriptLang.h"
#include "Arduino.h"

ScriptLang::KeyValueDict ScriptLang::m_dictionary[DICTIONARY_ELEMENTS_NUMBER] =
{
    { "OS",  KEY_LEFT_GUI },
    { "UP", KEY_UP_ARROW },
    { "DOW", KEY_DOWN_ARROW },
    { "LEF", KEY_LEFT_ARROW },
    { "RIG", KEY_RIGHT_ARROW },
    { "ESC", KEY_ESC },
    { "CAP", KEY_CAPS_LOCK },
    { "LSH", KEY_LEFT_SHIFT },
    { "RSH", KEY_RIGHT_SHIFT },
    { "LCT", KEY_LEFT_CTRL },
    { "RCT", KEY_RIGHT_CTRL },
    { "BAC", KEY_BACKSPACE },
    { "SPA", (uint16_t)' ' }, //optional
    { "ENT", KEY_RETURN },
    { "INS", KEY_INSERT },
    { "HOM", KEY_HOME },
    { "PUP", KEY_PAGE_UP },
    { "PDO", KEY_PAGE_DOWN },
    { "DEL", KEY_DELETE },
};

void ScriptLang::getFinalBytesArray(const char* scriptLine, char* outArray)
{
    uint8_t lineLength = strlen(scriptLine);

    char* buff = new char[lineLength + 1];
    memset(buff, 0, sizeof(buff));

    uint16_t buffIndex = 0;
    uint16_t outArrayIndex = 0;

    Serial.println(lineLength);

    if (isString(scriptLine))
    {
        strcpy(outArray, scriptLine);
        return;
    }

    for(uint16_t i = 0; i <= lineLength; i++)
    {
        Serial.println(buff);
        if(scriptLine[i] == ' ' || scriptLine[i] == '\0')
        {
            outArray[outArrayIndex] = getKeyNumValue(buff);
            outArrayIndex++; 

            memset(buff, 0, sizeof(buff));
            buffIndex = 0;
        }
        else
        {
            buff[buffIndex] = scriptLine[i];
            buffIndex++;
        }
    }
}

uint16_t ScriptLang::getKeyNumValue(const char* keyString)
{
    if(strcmp(keyString, "COM") == 0)
    {
        return 0;
    }

    if(strlen(keyString) == 1)
    {
        return (uint16_t)keyString[0];
    }

    return getSpecialKeyNumValue(keyString);
}

uint16_t ScriptLang::getSpecialKeyNumValue(const char* keyString)
{
    for(uint8_t i = 0; i < DICTIONARY_ELEMENTS_NUMBER; i++)
    {
        if(strcmp(m_dictionary[i].key, keyString) == 0)
        {
            return m_dictionary[i].value;
        }
    }

    return 0;
}

bool ScriptLang::hasSpaces(const char* string)
{
    for (uint8_t i = 0; i < strlen(string); i++)
    {
        if (string[i] == ' ')
        {
            return true;
        }
    }

    return false;
}

bool ScriptLang::isString(const char* string)
{
    return string[0] == '"' && string[strlen(string) - 1] == '"';
}