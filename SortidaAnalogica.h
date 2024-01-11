#ifndef SortidaAnalogica_h
#define SortidaAnalogica_h

#include <Arduino.h>

class SortidaAnalogica {
   protected:
    const int pin;

   public:
    SortidaAnalogica(int pin);
    void begin();
    void set(int valor);
    void set(int valor, int min, int max);

    int value;
};

#endif