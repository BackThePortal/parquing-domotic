#include "Pantalla.h"

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

Pantalla::Pantalla() : LiquidCrystal_I2C(0x27, 16, 2), t(0) {}

void Pantalla::begin() {
    this->init();
    this->backlight();
}

void Pantalla::update(String upperLine, String lowerLine) {
    this->clear();
    this->setCursor(0, 0);
    this->print(upperLine);
    this->print(lowerLine);
}

void Pantalla::update(String upperLine, String lowerLine, unsigned long t) {
    this->t = millis();
    this->maxT = t;
    this->update(upperLine, lowerLine);
}

bool Pantalla::checkTime() {
    if (this->t != 0 && millis() - this->t > this->maxT) {
        this->t == 0;
        this->maxT == 0;
        return true;
    }
    return false;
}
