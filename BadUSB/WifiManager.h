// WifiManager.h

#ifndef _WIFIMANAGER_h
#define _WIFIMANAGER_h

#include "WiFi.h"

class WifiManager
{
public:
	static void init();
	static void run(String filecontent);

	static void setOnExecuteCallback(void (*onExecuteCb)()) { onExecute = onExecuteCb; }

private:

	static WiFiServer server;

	static void (*onExecute)();
};

#endif

