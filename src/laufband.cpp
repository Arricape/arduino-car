#include "laufband.h"
#include <Wire.h>  // Sicherstellen, dass Wire hier auch eingebunden wird
#include <Arduino.h>

void scanI2C() {
  Serial.println("Scanne I2C...");
  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("Gefunden: 0x");
      Serial.println(address, HEX);
    }
  }
  delay(5000);
}
