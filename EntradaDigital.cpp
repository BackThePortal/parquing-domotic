#include "EntradaDigital.h"

EntradaDigital::EntradaDigital(int _pin) : pin(_pin) {
    pinMode(pin, INPUT);
}

int EntradaDigital::read() {
    return digitalRead(this->pin);
}

