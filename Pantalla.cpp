#include "Pantalla.h"
#include <Arduino.h>

Pantalla::Pantalla(Estat* status_ptr)
    : status(status_ptr), LiquidCrystal_I2C(0x27, 16, 2) {
    this->init();
    this->backlight();
    this->print("Benvinguts");
}

void Pantalla::update(String upperLine, String lowerLine) {
    this->clear();
    this->setCursor(0, 0);
    this->print(upperLine);
    this->print(lowerLine);
}
