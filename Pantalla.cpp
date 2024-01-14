#include "Pantalla.h"

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

Pantalla::Pantalla(unsigned int& places)
    : LiquidCrystal_I2C(0x27, 16, 2), t(0), maxT(0), places(places) {}

void Pantalla::begin() {
    this->init();
    this->backlight();
    this->idle();
}

void Pantalla::update(String upperLine, String lowerLine) {
    this->clear();
    this->setCursor(0, 0);
    this->print(upperLine);
    this->setCursor(0, 1);
    this->print(lowerLine);
}

void Pantalla::update(String upperLine, String lowerLine, unsigned long t) {
    if (this->t != 0) return;
    this->t = millis();
    this->maxT = t;
    this->update(upperLine, lowerLine);
}

void Pantalla::idle() {
    this->update("Benvinguts",
                 this->places == 0 ? "Parking ple" : "Places: " + String(this->places));
}

void Pantalla::checkTime() {
    // Hi ha un temporitzador i la diferència entre el moment
    // actual i el començament és major que la durada?
    if (this->t != 0 && millis() - this->t > this->maxT) {
        // Reiniciar instants
        this->t = 0;
        this->maxT = 0;

        // Tornar a missatge per defecte
        this->idle();
    }
}
