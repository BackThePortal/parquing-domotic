#include "Comandament.h"

#include <IRremote.h>

Comandament::Comandament(int _pin) : pin(_pin) { IrReceiver.begin(this->pin); }

int Comandament::check() {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.resume();
    return 0;
}
