#include "Helper.h"
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
 
    ScriptManager::init(DevicesManager::getKeyboard());
}                          

void loop()
{
    delay(200);

    //testing
    static bool test = false;

    if(isBootButtonClicked() && !test)
    {
        // DevicesManager::getKeyboard()->press('a');                
        // DevicesManager::getKeyboard()->press(KEY_TAB);                
        log("klik!");
        //if (SD.exists("/script.txt"))
        //{
        //    File file = SD.open("/script.txt");
        //    uint8_t fileData[50] = { '\0' };
        //    file.readBytes((char*)fileData, 50);
        //    ScriptManager::executeScript(fileData, 50);
        //    log("executed!");
        //}

        DevicesManager::getKeyboard()->press(0x83);
        delay(100);
        DevicesManager::getKeyboard()->press('r');
        delay(100);
        DevicesManager::getKeyboard()->releaseAll();
        //DevicesManager::getKeyboard()->releaseRaw(0xe3);
        test = true;
    }

    if (!isBootButtonClicked())
    {
        test = false;
    }
}
