#include "Defines.h"
#include "DevicesManager.h"
#include "ScriptManager.h"
#include "SD.h"
#include "ScriptLang.h"

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

    DevicesManager::beginSD();
    DevicesManager::beginKeyboard();
    DevicesManager::allDevicesReady();
 
    ScriptManager::init(&SD, DevicesManager::getKeyboard());

    // ScriptManager::executeScript();

    char buff[10];
    sprintf(buff, "%d", ScriptLang::getKeyNumValue("OS"));
    log(buff);

    char buff2[30] = { '\0' };
    ScriptLang::getFinalBytesArray("OS R", buff2);

    for(uint8_t i = 0; i < 13; i++)
    {
        Serial.println(buff2[i], HEX);
    }
}                          

void loop()
{
    delay(200);

    //testing
    if(isBootButtonClicked())
    {
        // DevicesManager::getKeyboard()->press(KEY_LEFT_CTRL);                
        // DevicesManager::getKeyboard()->press(KEY_TAB);                
        log("klik!");
    }
}
