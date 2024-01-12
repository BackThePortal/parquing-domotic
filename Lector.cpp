#include "Lector.h"

#include "Arduino.h"

Lector::Lector(int _pinSDA, int _pinRST) : EasyMFRC522(_pinSDA, _pinRST) {}

void Lector::begin() { this->init(); }

bool Lector::detect() { return this->detectTag(); }

bool Lector::detectWait() {
    int t = millis();
    bool detected;
    do {
        detected = this->detect();
        delay(50);
    } while (!detected && millis() - t < 10000);

    return detected;
}

bool Lector::write(String label, String data) {
    char stringBuffer[100];
    strcpy(stringBuffer, data.c_str());

    int stringSize = strlen(stringBuffer);

    int r = this->writeFile(1, data, (byte*)stringBuffer, stringSize + 1);

    return r >= 0;
}

int Lector::read(String label) {
    char stringBuffer[100];

    int r = this->readFile(1, label, (byte*)stringBuffer, 100);

    return r >= 0 ? stringBuffer[0] - '0' : r;
}
