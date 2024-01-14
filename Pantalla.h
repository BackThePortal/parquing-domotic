#include <LiquidCrystal_I2C.h>

#ifndef Pantalla_h
#define Pantalla_h

#include <Arduino.h>

class Pantalla : LiquidCrystal_I2C {
   private:
    unsigned long t;
    unsigned long maxT;
    unsigned int& places;

   public:
    Pantalla(unsigned int& places);
    void begin();
    void update(String upperLine, String lowerLine);
    /*
    Mostar un missatge per pantalla amb un temporitzador.
    */
    void update(String upperLine, String lowerLine, unsigned long t);
    /*
    Mostrar missatge per defecte.
    */
    void idle();
    /*
    Comprovar temporitzadors i fer tornar la pantalla al missatge
    per defecte si el temps ha passat,
    */
    void checkTime();
};

#endif
