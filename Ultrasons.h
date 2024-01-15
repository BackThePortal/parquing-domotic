#ifndef Ultrasons_h
#define Ultrasons_h

#include <Arduino.h>
#include "SortidaAnalogica.h"
#include "SortidaDigital.h"
#include "EntradaDigital.h"

class Ultrasons {
   public:
    Ultrasons(int pinTrig, int pinEcho, SortidaAnalogica* ptrBlue1, SortidaAnalogica* ptrBlue2);
    void begin();
    
    bool isClose();

   private:
    int count;
    SortidaDigital* trig;
    EntradaDigital* echo;
    SortidaAnalogica* blue1;
    SortidaAnalogica* blue2;

    const int lightRanges[3] = {3, 25, 50};

    int dist();

};
#endif