#include "SortidaAnalogica.h"

SortidaAnalogica::SortidaAnalogica(int pin) { pinMode(int pin, OUTPUT); }

void SortidaAnalogica::set(int valor) { analogWrite(this->pin, valor); }

void SortidaAnalogica::set(int valor, int min, int max) {
    this->set(map(constrain(valor, min, max), min, max, 0, 1023));
}
