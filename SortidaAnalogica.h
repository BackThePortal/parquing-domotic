#ifndef Motor_h
#define Motor_h

#include <Arduino.h>

class SortidaAnalogica {
   private:
    int pin;

   public:
    SortidaAnalogica(int pin);
    void set(int valor);
    void set(int valor, int min, int max);
};

#endif