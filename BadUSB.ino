#include "Defines.h"
#include "DevicesManager.h"
#include "ScriptManager.h"
#include "SD.h"

void log(const char* str)
{
    Serial.println(str);
}

bool isBootButtonClicked()
{
    return digitalRead(BOOT_BUTTON) == LOW;
}

void setup()
{
    pinMode(BOOT_BUTTON, INPUT_PULLUP);

    Serial.begin(115200);

    DevicesManager::beginKeyboard();
    DevicesManager::beginSD();
 
    ScriptManager::init(&SD, DevicesManager::getKeyboard());

    ScriptManager::executeScript();
}

void loop()
{
    delay(200);

    if(isBootButtonClicked())
    {
        log("klik!");
    }
}
