#ifndef Barrera_h
#define Barrera_h

#include <Arduino.h>
#include <Servo.h>

#include "SortidaDigital.h"
#include "Brunzidor.h"

class Barrera : Servo {
   private:
    static const int angleClosed = 125;
    static const int angleOpen = 20;
    const int pin;
    SortidaDigital* lightClosed;
    SortidaDigital* lightOpen;

    void set(int angle);

   public:
    // Utilitzar constructor de classe pare
    using Servo::Servo;
    Barrera(int pin, SortidaDigital* ptrLightClosed, SortidaDigital* ptrLightOpen, Brunzidor* ptrBuzzer);

    void open();
    void open(unsigned long t);
    void close();
    void close(unsigned long t);

    bool isOpen;
};

#endif