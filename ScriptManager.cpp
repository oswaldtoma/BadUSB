#include "ScriptManager.h"

fs::FS* ScriptManager::m_filesystem = nullptr;
HIDkeyboard* ScriptManager::m_keyboard = nullptr;

void ScriptManager::init(fs::FS* filesystem, HIDkeyboard* keyboard)
{
    m_filesystem = filesystem;
    m_keyboard = keyboard;
}

void ScriptManager::executeScript()
{
    
}
