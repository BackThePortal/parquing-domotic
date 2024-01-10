#ifndef Brunzidor_h
#define Brunzidor_h

#include <Arduino.h>
#include "SortidaAnalogica.h"

class Brunzidor : SortidaAnalogica {
   public:
    using SortidaAnalogica::SortidaAnalogica;
    void tone(unsigned int freq, unsigned long t);
};
#endif