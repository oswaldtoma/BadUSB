#include "ScriptManager.h"

fs::FS* ScriptManager::m_filesystem = nullptr;

void ScriptManager::init(fs::FS* filesystem)
{
    m_filesystem = filesystem;
}

