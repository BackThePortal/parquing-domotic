#include "Ultrasons.h"

#include "Arduino.h"
#include "HardwareSerial.h"

Ultrasons::Ultrasons(int pinTrig, int pinEcho, SortidaAnalogica* ptrBlue1,
                     SortidaAnalogica* ptrBlue2)
    : blue1(ptrBlue1), blue2(ptrBlue2), count(0) {
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
    if (d == 0) {
        this->blue1->set(0);
        this->blue2->set(0);
    } else {
        this->blue1->set(d, lightRanges[0], lightRanges[1]);
        this->blue2->set(d, lightRanges[1], lightRanges[2]);
    }

    //Serial.println(String(d));
    return d;
}

bool Ultrasons::isClose() {
    int d = this->dist();

    // Valor proper detectat?
    if (d > 1 && d < 6)
        this->count++;
    else if (d == 0) {
      // Valor nul?
        if (this->count < 1)
            this->count--;
        else
            this->count = -1;
    } else
      // Valor llunyà
        this->count = 0;

    // Avisar si hi ha 4 valors nuls seguits
    // No més per no saturar el serial monitor i només
    // aparèixer una vegada
    if (this->count == -4) Serial.println("Revisar ultrasons");

    // Si s'han detectat 3 o més valors propers
    // seguits, aleshores no és una interferència;
    // retornar true. En cas contrari, false.
    if (this->count >= 3) {
        // també mantenir el comptador a 3 per evitar overflow
        this->count = 3;
        return true;
    } else
        return false;
}
