#include "CMotorControls.h"
#include <Arduino.h>

CMotorControls::CMotorControls(CMotor *m1, CMotor *m2, CMotor *m3, CMotor *m4) {
  motors[0] = m1;
  motors[1] = m2;
  motors[2] = m3;
  motors[3] = m4;
}

void CMotorControls::move(ECarDirection dir) {
    switch (dir) {
    case ECarDirection::FORWARD:
        motors[0]->rotate(EDirection::FORWARD);
        Serial.println("Motor1 Vorwärts");
        motors[1]->rotate(EDirection::FORWARD);
        Serial.println("Motor2 Vorwärts");
        motors[2]->rotate(EDirection::FORWARD);
        Serial.println("Motor3 Vorwärts");
        motors[3]->rotate(EDirection::FORWARD);
        Serial.println("Motor4 Vorwärts");
        break;
    case ECarDirection::BACKWARD:
        motors[0]->rotate(EDirection::BACKWARD);
        Serial.println("Motor1 Rückwärts");
        motors[1]->rotate(EDirection::BACKWARD);
        Serial.println("Motor2 Rückwärts");
        motors[2]->rotate(EDirection::BACKWARD);
        Serial.println("Motor3 Rückwärts");
        motors[3]->rotate(EDirection::BACKWARD);
        Serial.println("Motor4 Rückwärts");
        break;
    case ECarDirection::RIGHT:
        motors[0]->rotate(EDirection::BACKWARD);
        Serial.println("Motor1 Rückwärts");
        motors[1]->rotate(EDirection::BACKWARD);
        Serial.println("Motor2 Rückwärts");
        motors[2]->rotate(EDirection::FORWARD);
        Serial.println("Motor3 Vorwärts");
        motors[3]->rotate(EDirection::FORWARD);
        Serial.println("Motor4 Vorwärts");
        break;
    case ECarDirection::LEFT:
        motors[0]->rotate(EDirection::FORWARD);
        Serial.println("Motor1 Vorwärts");
        motors[1]->rotate(EDirection::FORWARD);
        Serial.println("Motor2 Vorwärts");
        motors[2]->rotate(EDirection::BACKWARD);
        Serial.println("Motor3 Rückwärts");
        motors[3]->rotate(EDirection::BACKWARD);
        Serial.println("Motor4 Rückwärts");

        break;
    case ECarDirection::NONE: {
        motors[0]->rotate(EDirection::NONE);
        motors[1]->rotate(EDirection::NONE);
        motors[2]->rotate(EDirection::NONE);
        motors[3]->rotate(EDirection::NONE);
        break;
    }
}
}
