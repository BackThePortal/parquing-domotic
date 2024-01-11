#include "Ultrasons.h"
#include "Arduino.h"

Ultrasons::Ultrasons(int pinTrig, int pinEcho, SortidaAnalogica* ptrBlue1,
                     SortidaAnalogica* ptrBlue2)
    : blue1(ptrBlue1), blue2(ptrBlue2) {
    this->trig = new SortidaDigital(pinTrig);
    this->echo = new EntradaDigital(pinEcho);
}

void Ultrasons::begin() {
    this->trig->begin();
    this->echo->begin();
}

int Ultrasons::dist() {
    this->trig->pulseOut();
    int d = this->echo->pulseIn() / 59;
    
    this->blue1->set(d, lightRanges[0], lightRanges[1]);
    this->blue2->set(d, lightRanges[1], lightRanges[2]);

    Serial.println(d);

    return d;
}

bool Ultrasons::isClose() {
    int d = this->dist();
    return d > 1 && d < 6;
}
