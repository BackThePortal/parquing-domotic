#include <IRremote.hpp>

#include "Comandament.h"


Comandament::Comandament(int _pin) : pin(_pin) {  }

void Comandament::begin() {
IrReceiver.begin(this->pin);
}

int Comandament::check() {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.resume();
    return 0;
}
