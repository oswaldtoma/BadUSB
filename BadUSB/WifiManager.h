// WifiManager.h

#ifndef _WIFIMANAGER_h
#define _WIFIMANAGER_h

#include "WiFi.h"
#include "AsyncTCP.h"
#include "ESPAsyncWebServer.h"

class WifiManager
{
public:
	static void init();
	static void run(String filecontent);

	static void setOnRequestCb(void (*onRequest)(String bodyContent)) { onRequestCb = onRequest; }

private:

	static AsyncWebServer server;

	static char PROGMEM pageContent[3000];

	static void (*onRequestCb)(String);
};

#endif

