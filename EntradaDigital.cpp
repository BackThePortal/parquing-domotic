#include "EntradaDigital.h"
#include "Arduino.h"


EntradaDigital::EntradaDigital(int _pin) : pin(_pin) { }

void EntradaDigital::begin() {
    pinMode(pin, INPUT);
}

int EntradaDigital::read() { return digitalRead(this->pin); }

unsigned long EntradaDigital::pulseIn() { return ::pulseIn(this->pin, HIGH); }
