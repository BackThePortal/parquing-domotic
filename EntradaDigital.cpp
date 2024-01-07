#include "EntradaDigital.h"

EntradaDigital::EntradaDigital(int pin) {
    this->pin = pin;
    pinMode(pin, INPUT);
}

int EntradaDigital::read() {
    return digitalRead(this->pin);
}

