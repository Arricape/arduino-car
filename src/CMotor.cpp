#include "CMotor.h"
#include <Arduino.h>

CMotor::CMotor(int p1, int p2) : pin1(p1), pin2(p2) {
    pinMode(pin1, OUTPUT); 
    pinMode(pin2, OUTPUT);
}

void CMotor::rotate(EDirection dir) {
    switch (dir) {

    case EDirection::FORWARD:
        digitalWrite(pin1, LOW);  // Motor rotates forward
        digitalWrite(pin2, HIGH);
        break;

    case EDirection::BACKWARD:
        digitalWrite(pin1, HIGH);   // Motor rotates backward
        digitalWrite(pin2, LOW);
        break;

    case EDirection::NONE:
    Serial.println("Motor gestoppt");
        digitalWrite(pin1, LOW);   // Motor stops (both pins LOW)
        digitalWrite(pin2, LOW);
        break;
    }
}
