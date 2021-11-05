// WifiManager.h

#ifndef _WIFIMANAGER_h
#define _WIFIMANAGER_h

#include "WiFi.h"

class WifiManager
{
public:
	static void init();
	static void run();

private:

	static WiFiServer server;
};

#endif

