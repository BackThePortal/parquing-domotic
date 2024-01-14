#ifndef Barrera_h
#define Barrera_h

#include <Arduino.h>
#include <Servo.h>

#include "Brunzidor.h"
#include "SortidaDigital.h"

class Barrera : private Servo {
   private:
    static const int angleClosed = 5;
    static const int angleOpen = 95;
    const int pin;

    unsigned long t = 0;
    unsigned long maxT = 0;

    SortidaDigital* lightClosed;
    SortidaDigital* lightOpen;
    Brunzidor* buzzer;
    void close();

   public:
    Barrera(int _pin, SortidaDigital* ptrLightClosed,
            SortidaDigital* ptrLightOpen, Brunzidor* ptrBuzzer);

    void begin();

    // NO CLOSE FUNCTION? https://imgflip.com/i/8cbjjn
    void open(unsigned long t);
    void checkTime();

    bool isOpen;
};

#endif
