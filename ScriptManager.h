#include "FS.h"
#include "USBHIDKeyboard.h"

class ScriptManager
{
public:
    static void init(fs::FS* filesystem, USBHIDKeyboard* keyboard);
    static void executeScript();

private:
    static fs::FS* m_filesystem;
    static USBHIDKeyboard* m_keyboard;
};