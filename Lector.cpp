#include "Lector.h"

#include "Arduino.h"
#include "Servo.h"

Lector::Lector(int _pinSDA, int _pinRST) : MFRC522(_pinSDA, _pinRST) {}

void Lector::begin() {
    this->PCD_Init();
    SPI.begin();
}

bool Lector::detect() {
    if ((this->t == 0 || millis() - this->t > 3000) &&
        this->PICC_IsNewCardPresent()) {
        Serial.println("targeta");
        this->t = millis();
        return true;
    }
    return false;
}

// Funció utilitzada per al registre d'usuaris,
// però com el comandament no està disponible
// aquesta funció no està utilitzada.
bool Lector::detectWait() {
    // Temps d'inici
    int t = millis();

    // Esperar fins detectar una targeta o fins
    // que passin 10 segons
    bool detected;
    do {
        detected = this->detect();
        delay(50);
    } while (!detected && millis() - t < 10000);

    return detected;
}

/*
bool Lector::write(String label, String data) {

    // stringBuffer és una llista de caràcters
    // (a efectes pràctics un string)
    char stringBuffer[100];

    // Insereix l'string
    strcpy(stringBuffer, data.c_str());

    // Obtenir la llargada del string, necessari per l'escriptura
    int stringSize = strlen(stringBuffer);

    // Escriure l'stringBuffer com a bytes i obtenir el codi de resultat
    int r = this->writeFile(1, data, (byte*)stringBuffer, stringSize + 1);

    // Si el codi és negatiu hi ha hagut un error
    return r >= 0;
}

int Lector::read(String label) {
    char stringBuffer[100];

    int r = this->readFile(1, label, (byte*)stringBuffer, 100);
    Serial.println(stringBuffer);
    return r >= 0 ? stringBuffer[0] - '0' : r;
}

*/
