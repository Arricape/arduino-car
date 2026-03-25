#ifndef RFID_H
#define RFID_H

#include <SPI.h>
#include <MFRC522.h>

class RFID {
public:
    RFID(uint8_t ssPin, uint8_t rstPin);
    void begin();
    bool readColor(char* colorData, size_t maxLen);

private:
    MFRC522 mfrc522;
    MFRC522::MIFARE_Key key;
    const uint8_t trailerBlock = 7;
    const uint8_t bufferSize = 18;
};

#endif