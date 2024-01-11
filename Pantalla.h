#include <LiquidCrystal_I2C.h>

#ifndef Pantalla_h
#define Pantalla_h

#include <Arduino.h>

/*
Herència privada perquè tot allò public dins de LiquidCrystal_I2C
es converteixi en privat i no s'hi pugui accedir.
*/
class Pantalla : private LiquidCrystal_I2C {
   private:
    unsigned long t;
    unsigned long maxT = 0;

   public:
    using LiquidCrystal_I2C::clear;
    Pantalla();
    void begin();
    void update(String upperLine, String lowerLine);
    void update(String upperLine, String lowerLine, unsigned long t);
    bool checkTime();
};

#endif
