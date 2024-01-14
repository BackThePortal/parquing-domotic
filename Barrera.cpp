#include "HardwareSerial.h"
#include "Barrera.h"
 #include "Servo.h"

Barrera::Barrera(int _pin, SortidaDigital* ptrLightClosed,
                 SortidaDigital* ptrLightOpen, Brunzidor* ptrBuzzer)
    : Servo::Servo(),
      pin(_pin),
      lightClosed(ptrLightClosed),
      lightOpen(ptrLightOpen),
      buzzer(ptrBuzzer) {}

void Barrera::begin() {
    this->attach(this->pin);
    // Temporalment assignar isOpen a true perquè
    // s'executi close()
    this->isOpen = true;
    this->close();
}

void Barrera::open(unsigned long t) {
    if (this->isOpen) return;

    this->isOpen = true;

    // Recordar moment d'obertura
    this->t = millis();
    // Assignar durada
    this->maxT = t;

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

void Barrera::checkTime() {
    // Hi ha un temporitzador i la diferència entre el moment
    // actual i el moment d'obertura és major que la durada?
    if (this->t != 0 && millis() - this->t > this->maxT) {
        this->close();
    }
}


