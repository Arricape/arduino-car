#ifndef CMOTORCONTROLS_H
#define CMOTORCONTROLS_H

#include "CMotor.h"

// Enum Klasse für richtungen
enum class ECarDirection {
    FORWARD,    
    BACKWARD,   
    LEFT,       
    RIGHT,     
    NONE        
};

class CMotorControls {
private:
    CMotor* motors[4];  //Array speichert die motor pointer

public:
    // Konstruktor für Motoren
    CMotorControls(CMotor *m1, CMotor *m2, CMotor *m3, CMotor *m4);

    // Movement Methode
    void move(ECarDirection dir);
};

#endif 
