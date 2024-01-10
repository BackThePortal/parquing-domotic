#include "SortidaAnalogica.h"

SortidaAnalogica::SortidaAnalogica(int _pin) : pin(_pin) { pinMode(pin, OUTPUT); }

void SortidaAnalogica::set(int value) {
    analogWrite(this->pin, value);
    this->value = value;
}

void SortidaAnalogica::set(int value, int min, int max) {
    this->set(map(constrain(value, min, max), min, max, 0, 1023));
}
