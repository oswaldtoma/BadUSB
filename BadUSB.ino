#include "hidkeyboard.h"
#include "SD.h"
#include "SPI.h"

HIDkeyboard key;
SPIClass spi;

void setup() {
  // put your setup code here, to run once:
  key.begin();
  spi.begin(15,16,17,-1);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
}
