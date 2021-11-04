#include "Timer.h"
#include "ITimer.h"
#include "Timer.h"
#include "Helper.h"
#include "Defines.h"
#include "DevicesManager.h"
#include "ScriptManager.h"
#include "SD.h"
#include "ScriptLang.h"
#include "WiFi.h"

const char* ssid = "yourAP";
const char* password = "yourPassword";

WiFiServer server(80);

Timer timer;

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

    delay(5000);
    // ---------------------------------

    WiFi.softAP(ssid, password);
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);
    server.begin();

    Serial.println("Server started");
}                          

void loop()
{
    WiFiClient client = server.available();   // listen for incoming clients

    if (client) {                             // if you get a client,
        Serial.println("New Client.");           // print a message out the serial port
        String currentLine = "";                // make a String to hold incoming data from the client
        while (client.connected()) {            // loop while the client's connected
            if (timer.isZero())
            {
                Serial.printf("Millis: %d; Free: %d\tMaxAlloc: %d\t PSFree: %d\n", millis(), ESP.getFreeHeap(), ESP.getMaxAllocHeap(), ESP.getFreePsram());
                timer.start(500);
            }
            if (client.available()) {             // if there's bytes to read from the client,
                char c = client.read();             // read a byte, then
                Serial.write(c);                    // print it out the serial monitor
                if (c == '\n') {                    // if the byte is a newline character

                  // if the current line is blank, you got two newline characters in a row.
                  // that's the end of the client HTTP request, so send a response:
                    if (currentLine.length() == 0) {
                        // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
                        // and a content-type so the client knows what's coming, then a blank line:
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-type:text/html");
                        client.println();

                        // the content of the HTTP response follows the header:
                        client.print("Click <a href=\"/H\">here</a> to turn ON the LED.<br>");
                        client.print("Click <a href=\"/L\">here</a> to turn OFF the LED.<br>");

                        // The HTTP response ends with another blank line:
                        client.println();
                        // break out of the while loop:
                        break;
                    }
                    else {    // if you got a newline, then clear currentLine:
                        currentLine = "";
                    }
                }
                else if (c != '\r') {  // if you got anything else but a carriage return character,
                    currentLine += c;      // add it to the end of the currentLine
                }
            }
        }
        // close the connection:
        client.stop();
        Serial.println("Client Disconnected.");
    } 
    //----------
    static bool firstRun = false;
    
    //testing
    static bool test = false;
    static uint8_t fileData[500] = { '\0' };

    if((isBootButtonClicked() || firstRun) && !test)
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
        firstRun = false;
        test = true;
    }

    if (!isBootButtonClicked())
    {
        test = false;
        //DevicesManager::getKeyboard()->releaseAll();
    }

    if(timer.isZero())
    {
        Serial.printf("aFree: %d\tMaxAlloc: %d\t PSFree: %d\n", ESP.getFreeHeap(), ESP.getMaxAllocHeap(), ESP.getFreePsram());
        timer.start(500);
    }
}
