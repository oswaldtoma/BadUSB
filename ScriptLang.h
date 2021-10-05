#include "USBHIDKeyboard.h"

class ScriptLang
{
    struct KeyValueDict
    {
        char key[4];
        uint16_t value;
    };

public:
    static void getFinalBytesArray(const char* scriptLine, uint16_t lineLength, uint16_t* outArray);
    static uint16_t getKeyNumValue(const char* keyString);

private:
    static constexpr uint8_t DICTIONARY_ELEMENTS_NUMBER = 19;

    static uint16_t getSpecialKeyNumValue(const char* keyString);

    static KeyValueDict m_dictionary[DICTIONARY_ELEMENTS_NUMBER];
};