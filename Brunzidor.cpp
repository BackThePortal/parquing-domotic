#include "Arduino.h"
#include "Brunzidor.h"

void Brunzidor::tone(unsigned int freq, unsigned long t) {
    // operador :: per agafar l'scope global
    ::tone(this->pin, freq, t);
}
