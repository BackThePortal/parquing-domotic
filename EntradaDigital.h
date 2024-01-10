#ifndef EntradaDigital_h
#define EntradaDigital_h

#include <Arduino.h>
class EntradaDigital {
   public:
    EntradaDigital(int pin);
    int read();
   protected:
    const int pin;
};

#endif