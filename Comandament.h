#ifndef Comandament_h
#define Comandament_h

#include <Arduino.h>

class Comandament {
   protected:
    int pin;

   public:
    Comandament(int _pin);
    int check();
};

#endif