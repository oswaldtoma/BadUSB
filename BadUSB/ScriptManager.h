#include "IKeyboard.h"
#include "FS.h"

class ScriptManager
{
public:
    typedef struct
    {
        uint8_t rowArray[100];
        uint16_t rowLength;
    } Row;

    static void init(fs::FS* filesystem, IKeyboard* keyboard);
    static void executeScript();

private:
    static fs::FS* m_filesystem;
    static IKeyboard* m_keyboard;

    static uint16_t getRowCount(uint8_t* buffer, uint16_t buffSize);
    static void getRows(Row* rowArray, uint16_t arrSize);
    static Row getRow(uint8_t* buffer, uint16_t buffSize);
};