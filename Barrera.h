#ifndef Barrera_h
#define Barrera_h

#include <Arduino.h>
#include <Servo.h>

#include "Brunzidor.h"
#include "SortidaDigital.h"

class Barrera : private Servo {
   private:
    static const int angleClosed = 125;
    static const int angleOpen = 20;
    const int pin;

    unsigned long t = 0;

    SortidaDigital* lightClosed;
    SortidaDigital* lightOpen;
    Brunzidor* buzzer;

   public:
    Barrera(int _pin, SortidaDigital* ptrLightClosed,
            SortidaDigital* ptrLightOpen, Brunzidor* ptrBuzzer);

    void open();
    void open(unsigned long t);
    void close();
    void close(unsigned long t);
    bool checkTime();

    bool isOpen;
};

#endif