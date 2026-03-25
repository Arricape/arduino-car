#include <Arduino.h>
#include <MFRC522.h>
#include <SPI.h>
#include "CMotorControls.h"
#include "laufband.h"
#include "rfid.h"

// Motor Definitions
CMotor *m1 = nullptr;
CMotor *m2 = nullptr;
CMotor *m3 = nullptr;
CMotor *m4 = nullptr;
CMotorControls *motorControls;

// Distance Sensor Pins
const int trigPin = 12;  
const int echoPin = 13;  

// RFID Reader
RFID rfid(10, 9);  // SS_PIN = 10, RST_PIN = 9

// Get Distance Measurement
long getDistance() { 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);  
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH); 
  long distance = (duration * 0.0343) / 2;  

  return distance;
}

void setup() {
  Serial.begin(9600);
  Serial.println("Initialisiere Ports");

  // Motor Initialization
  m1 = new CMotor(8, 9);
  m2 = new CMotor(8, 9);
  m3 = new CMotor(10, 11);
  m4 = new CMotor(10, 11);
  motorControls = new CMotorControls(m1, m2, m3, m4);
  Serial.println("Motor Online");

  // Distance Sensor Setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.println("Ultraschallsensor Online");

  // I2C Initialization
  Wire.begin();
  Serial.println("I2C Scanner Online...");

  // RFID Initialization
  SPI.begin();
  rfid.begin();  
  Serial.println("RFID Color Reader Ready");
  Serial.println("Place your RFID tag on the reader...");
}

void loop() {
  // Distance Measurement
  long distance = getDistance();  
  Serial.print("Distanz: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);

  // RFID Read
  char colorData[16];  
  if (rfid.readColor(colorData, sizeof(colorData))) {
    Serial.print("RFID Color: ");
    Serial.println(colorData);
  }

  // Obstacle Avoidance
  if (distance < 20) {  
    Serial.println("Notbremsung!");
    motorControls->move(ECarDirection::NONE);
    delay(1000);

    Serial.println("Fahre zurück");
    motorControls->move(ECarDirection::BACKWARD); 
    delay(3000);

    Serial.println("Drehe nach links");
    motorControls->move(ECarDirection::LEFT);
    delay(500);

    if (getDistance() > 20) {
      Serial.println("Drehe nach rechts");
      motorControls->move(ECarDirection::RIGHT);
      delay(500);

      Serial.println("Fahre vorwärts");
      motorControls->move(ECarDirection::FORWARD);
      delay(3000);
    } else {
      Serial.println("Noch zu nah, fahre weiter zurück");
      motorControls->move(ECarDirection::BACKWARD);
      delay(3000);
    }
  } else {
    Serial.println("Kein Hindernis erkannt, fahre vorwärts");
    motorControls->move(ECarDirection::FORWARD);
  }
}
