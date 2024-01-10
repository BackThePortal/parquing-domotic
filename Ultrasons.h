#ifndef Brunzidor_h
#define Brunzidor_h

#include <Arduino.h>

class Ultrasons {
   public:
    Ultrasons(int pinTrig, int pinEcho);
    unsigned long polsar();

   private:
    int pinTrig;
    int pinEcho;
    int rangs[3];

};
#endif