#include <LiquidCrystal_I2C.h>

#include "Pantalla.h"
#include <Arduino.h>

Pantalla::Pantalla()
    : LiquidCrystal_I2C(0x27, 16, 2) {
}

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
