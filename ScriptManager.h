#include "FS.h"
#include "hidkeyboard.h"

class ScriptManager
{
public:
    static void init(fs::FS* filesystem, HIDkeyboard* keyboard);
    static void executeScript();

private:
    static fs::FS* m_filesystem;
    static HIDkeyboard* m_keyboard;
};