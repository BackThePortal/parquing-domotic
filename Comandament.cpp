#include "Comandament.h"

#include <IRremote.hpp>

Comandament::Comandament(int _pin) : pin(_pin) {}

void Comandament::begin() { IrReceiver.begin(this->pin); }

Actions Comandament::read() {
    // unsigned long, vegeu codi font de IrReceiver
    unsigned long data = IrReceiver.decodedIRData.decodedRawData;

    // Cercar codi a la llista de botons. ús de punters perquè són guais
    // utilitzaria decomposition declaration però l'arduino està antiquat
    for (auto &&item : this->actions)
        if (item.code == data) return item.action;

    // No s'ha trobat cap botó. Retornar el botó _NULL (amb valor 0)
    return _NULL;
}
