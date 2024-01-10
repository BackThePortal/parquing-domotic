#include "Barrera.h"
// #include "Servo.h"

void Barrera::set(int angle) {}

Barrera::Barrera(int servoPin, SortidaDigital* ptrLightClosed,
                 SortidaDigital* ptrLightOpen, Brunzidor* ptrBuzzer)
    : lightClosed(ptrLightClosed), lightOpen(ptrLightOpen), pin(servoPin) {
    this->attach(this->pin);
    this->close();
}

void Barrera::open() {
    this->isOpen = true;
    this->write(angleOpen);
    this->lightClosed->off();
    this->lightOpen->on();
}

void Barrera::close() {
    this->isOpen = false;
    this->write(angleClosed);
    this->lightClosed->on();
    this->lightOpen->off();
}

void Barrera::open(unsigned long t) {
    this->open();
    delay(t);
    this->close();
}

void Barrera::close(unsigned long t) {
    this->close();
    delay(t);
    this->open();
}