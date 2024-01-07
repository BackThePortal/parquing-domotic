#ifndef Motor_h
#define Motor_h

#include <Arduino.h>
#include <Servo.h>

#include "SortidaDigital.h"

class Motor : Servo {
   public:
    // Utilitzar constructor de classe pare
    Motor(int pin);
};

#endif