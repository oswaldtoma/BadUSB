#include "WifiManager.h"

WiFiServer WifiManager::server(80);

void WifiManager::init()
{
    WiFi.softAP("ESP32", 0, 10);
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);
    server.begin();
}

void WifiManager::run()
{
    WiFiClient client = server.available();  

    if (client)
    {                             
        Serial.println("New Client.");           
        String currentLine = "";               
        while (client.connected())
        {            
            if (client.available())
            {            
                char c = client.read();             
                if (c == '\n')
                {                    
                    if (currentLine.length() == 0)
                    {
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-type:text/html");
                        client.println();

                        const char* content = "<html> \
                                <head> \
                                </head> \
                                <body> \
                                    <script> \
                                        function scrollToBottom() \
                                        { \
                                            var code = document.getElementById(\"code\"); \
                                            code.scrollTop = code.scrollHeight; \
                                        } \
                                        \
                                        function addString(value) { \
                                            document.getElementById(\"code\").value += \"\\n\" + value + \" \"; \
                                            scrollToBottom(); \
                                        } \
                                        \
                                        function execute() { \
                                        \
                                        } \
                                    </script> \
                                    <div id=\"main\" style=\"display: flex; height: 75%;\"> \
                                        <div id=\"text\" style=\"flex: 3;\"> \
                                            <textarea id=\"code\" placeholder=\"Enter your code here.\" autofocus=\"true\" style=\"resize: none; width: 80%; height: 100%; font-size: 18px;\"></textarea> \
                                        </div> \
                                        <div id = \"buttons\" style = \"flex: 1\"> \
                                            <input type = \"button\" value = \"Comment\" style = \"padding: 50px 54px; font-size: 20px;\" onclick=\"addString(\'COM\')\"><br><br><br><br> \
                                            <input type = \"button\" value = \"Wait\" style = \"padding: 30px 34px; font-size: 20px;\" onclick=\"addString(\'WT\')\"><br><br><br><br> \
                                            <input type = \"button\" value = \"OS\" style = \"padding: 30px 34px; font-size: 20px;\" onclick=\"addString(\'OS\')\"><br><br><br><br> \
                                            <input type = \"button\" value = \"Context menu\" style = \"padding: 30px 34px; font-size: 20px;\" onclick=\"addString(\'CON\')\"><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br> \
                                            <input type = \"button\" value = \"Execute\" style = \"padding: 30px 34px; font-size: 20px;\" onclick=\"execute()\"><br><br><br><br> \
                                        </div> \
                                    </div> \
                                    <script> \
                                        scrollToBottom(); \
                                    </script> \
                                </body> \
                            </html>";

                        client.print(content);
                        client.println();
                       
                        break;
                    }
                    else 
                    {    
                        currentLine = "";
                    }
                }
                else if (c != '\r')
                {  
                    currentLine += c;      
                }
            }
        }

        client.stop();
        Serial.println("Client Disconnected.");
    }
}
