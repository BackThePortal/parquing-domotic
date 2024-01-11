#ifndef EntradaDigital_h
#define EntradaDigital_h

#include <Arduino.h>
class EntradaDigital {
   public:
    EntradaDigital(int pin);
    void begin();
    int read();
    /*
    Equivalent a la funció integrada corresponent amb un
    interval de 10 microsegons.
    */
    unsigned long pulseIn();
   protected:
    const int pin;
};

#endif