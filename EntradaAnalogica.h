#ifndef EntradaAnalogica_h
#define EntradaAnalogica_h

#include <Arduino.h>
class EntradaAnalogica {
   public:
    EntradaAnalogica(int pin);
    int read();

    // static int map(int valor, int min, int max);
   protected:
    const int pin;
};

#endif