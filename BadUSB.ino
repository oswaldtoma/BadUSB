#include "hidkeyboard.h"
#include "sdusb.h"
#include "Defines.h"

#if CFG_TUD_HID
// SDCard2USB sdUsb; //obiekt koliduje z hidem
HIDkeyboard keyboard;

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

    // if(!sdUsb.initSD(SD_SCK, SD_MISO, SD_MOSI, SD_CS))
    // {
    //     log("Failed to init SD");
    // }

    keyboard.begin();
    
    // if(!sdUsb.begin())
    // {
    //     log("LUN 1 failed");
    // }
}

void loop()
{
    // put your main code here, to run repeatedly:
    delay(200);

    if(isBootButtonClicked())
    {
        keyboard.sendChar('a');
        log("klik!");
        // if(sdUsb.begin())
        // {
        //     log("sd started");
        // }
    }
}
#endif
