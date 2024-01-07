#include "EntradaAnalogica.h"
#include "Arduino.h"

EntradaAnalogica::EntradaAnalogica(int pin) {}

int EntradaAnalogica::read() { return 0; }

// Preprocessar un valor
int EntradaAnalogica::preMap(int valor, int min, int max) {
    // :: sol perquè agafem la funció map del scope superior
    return map(constrain(valor, min, max), 0,)
}
