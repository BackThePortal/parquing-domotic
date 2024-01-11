#include "Barrera.h"
// #include "Servo.h"

Barrera::Barrera(int _pin, SortidaDigital* ptrLightClosed,
                 SortidaDigital* ptrLightOpen, Brunzidor* ptrBuzzer)
    : Servo::Servo(),
      pin(_pin),
      lightClosed(ptrLightClosed),
      lightOpen(ptrLightOpen),
      buzzer(ptrBuzzer) {}

void Barrera::begin() {
    this->attach(this->pin);
    this->close();
}

void Barrera::open() {
    if (this->isOpen) return;

    this->isOpen = true;
    this->t = millis();
    this->write(angleOpen);
    this->buzzer->tone(3000, 700);
    this->lightClosed->off();
    this->lightOpen->on();
}

void Barrera::close() {
    if (!this->isOpen) return;

    this->isOpen = false;
    this->t = 0;
    this->write(angleClosed);
    this->buzzer->tone(4000, 700);
    this->lightClosed->on();
    this->lightOpen->off();
}

bool Barrera::checkTime() {
    if (this->t != 0 && millis() - this->t > 3000) {
        this->close();
        this->t = 0;
        return true;
    }
    return false;
}

// Funcions no utilitzades
void Barrera::open(unsigned long t) {
    if (this->isOpen) return;

    this->open();
    delay(t);
    this->close();
}

void Barrera::close(unsigned long t) {
    if (!this->isOpen) return;

    this->close();
    delay(t);
    this->open();
}
