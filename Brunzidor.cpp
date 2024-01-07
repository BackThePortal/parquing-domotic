#include "Arduino.h”
#include "Brunzidor.h"

Brunzidor::Brunzidor(int pin) {
    pinMode(pin, OUTPUT);

    this->pin = pin;
}

void Brunzidor::sonar(int f) { tone(this->pin, f, this->t); }