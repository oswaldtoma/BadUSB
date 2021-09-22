#include "FS.h"

class ScriptManager
{
public:
    static void init(fs::FS* filesystem);

private:

    static fs::FS* m_filesystem;
};