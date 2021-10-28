#include "Timer.h"
#include "ITimer.h"
#include "Timer.h"
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

    DevicesManager::getKeyboard()->releaseAll();
}                          

void loop()
{
    delay(200);
    static uint8_t fileData[500] = { '\0' };
    Helper::fillArrayWithValue(fileData, 500, 0);

    //testing
    static bool test = false;


    if(isBootButtonClicked() && !test)
    {       
        log("klik!");
        if (SD.exists("/script.txt"))
        {
            File file = SD.open("/script.txt");
            file.readBytes((char*)fileData, 500);
            ScriptManager::executeScript(fileData, 500);
            log("executed!");
        }

        //DevicesManager::getKeyboard()->press(0x83);
        //DevicesManager::getKeyboard()->press('r');
        //DevicesManager::getKeyboard()->releaseAll();
        //DevicesManager::getKeyboard()->releaseRaw(0xe3);
        test = true;
    }

    if (!isBootButtonClicked())
    {
        test = false;
        DevicesManager::getKeyboard()->releaseAll();
    }
}
