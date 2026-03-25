// CMotor.h
#ifndef CMOTOR_H
#define CMOTOR_H

enum class EDirection {
    FORWARD,
    BACKWARD,
    NONE
};

class CMotor {
private:
    int pin1, pin2;

public:
    CMotor(int p1, int p2);
    void rotate(EDirection dir);
};

#endif  // CMOTOR_H
