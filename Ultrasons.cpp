#include "Ultrasons.h"

#include "Arduino.h"

Ultrasons::Ultrasons(int pinTrig, int pinEcho) {
    pinMode(pinTrig, OUTPUT);
    pinMode(pinEcho, INPUT);
}

unsigned long Ultrasons::polsar() {
    digitalWrite(this->pinTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->pinTrig, LOW);

    return pulseIn(this->pinEcho, HIGH) / 59;

}