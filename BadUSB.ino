#include "Defines.h"
#include "DevicesManager.h"

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
}

void loop()
{
    // put your main code here, to run repeatedly:
    delay(200);

    static bool started = false;

    if(isBootButtonClicked())
    {
        if(!started)
        {
            DevicesManager::beginSD();
            started = true;
        }

        DevicesManager::getKeyboard()->sendChar('a');
        log("klik!");
    }
}
