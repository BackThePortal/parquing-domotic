#include "SortidaDigital.h"
#include "Arduino.h"

SortidaDigital::SortidaDigital(int _pin) : pin(_pin) {
}

void SortidaDigital::begin() {
    pinMode(pin, OUTPUT);
}

void SortidaDigital::on() {
    this->set(HIGH);
}

void SortidaDigital::off() {
    this->set(LOW);
}

void SortidaDigital::on(unsigned long t) {
    this->set(HIGH, t);
}

void SortidaDigital::off(unsigned long t) {
    this->set(LOW, t);
}

void SortidaDigital::set(int estat) {
    digitalWrite(this->pin, estat);
    this->estat = estat;
}

void SortidaDigital::set(int estat, unsigned long t) {
    this->set(estat);
    delay(t);
    this->set(!estat);
}

void SortidaDigital::pulseOut() {
    this->on();
    delayMicroseconds(10);
    this->off();
}