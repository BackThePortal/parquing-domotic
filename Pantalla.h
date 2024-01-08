#ifndef Pantalla_h
#define Pantalla_h

#include <Arduino.h>
#include <Estat.h>

#include "LiquidCrystal_I2C/LiquidCrystal_I2C.h"

/*
Herència privada perquè tot allò public dins de LiquidCrystal_I2C
es converteixi en privat i no s'hi pugui accedir.
*/
class Pantalla : private LiquidCrystal_I2C {
   private:
    Estat* status;

   public:
    // Cridar constructor de classe superior
    using LiquidCrystal_I2C::clear;

    Pantalla(Estat* status_ptr);
   
    void update(String upperLine, String lowerLine);
};

#endif