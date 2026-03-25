#include "rfid.h"

RFID::RFID(uint8_t ssPin, uint8_t rstPin) : mfrc522(ssPin, rstPin) {}

void RFID::begin() {
    SPI.begin();
    mfrc522.PCD_Init();
    
    // Initialize standard key (0xFF)
    for (byte i = 0; i < MFRC522::MF_KEY_SIZE; i++) {
        key.keyByte[i] = 0xFF;
    }
}

bool RFID::readColor(char* colorData, size_t maxLen) {
    mfrc522.PCD_Init();
    delay(100);

    // Look for new cards
    if (!mfrc522.PICC_IsNewCardPresent()) return false;
    if (!mfrc522.PICC_ReadCardSerial()) return false;

    // Authenticate using key A
    MFRC522::StatusCode status = mfrc522.PCD_Authenticate(
        MFRC522::PICC_CMD_MF_AUTH_KEY_A,
        trailerBlock,
        &key,
        &(mfrc522.uid)
    );

    if (status != MFRC522::STATUS_OK) {
        Serial.println("Authentication failed");
        mfrc522.PICC_HaltA();
        return false;
    }

    // Block where color data is stored
    uint16_t blockAddress = 4;

    // Read the block
    status = mfrc522.MIFARE_Read(blockAddress, (byte*)colorData, (uint8_t*)&bufferSize);

    if (status == MFRC522::STATUS_OK) {
        colorData[maxLen - 1] = '\0';  // Ensure null termination
        Serial.println("\n-----------------------");
        Serial.println("DETECTED COLOR:");
        Serial.println(colorData);
        Serial.println("-----------------------");

        mfrc522.PICC_HaltA();
        mfrc522.PCD_StopCrypto1();
        return true;
    } else {
        Serial.println("Failed to read color data");
        return false;
    }
}
