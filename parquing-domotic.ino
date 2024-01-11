#include <Servo.h>

#include "Barrera.h"
#include "Brunzidor.h"
#include "Comandament.h"
#include "EntradaDigital.h"
#include "Pantalla.h"
#include "SortidaDigital.h"
#include "Ultrasons.h"

SortidaDigital vermell(51);
SortidaDigital verd(50);

SortidaAnalogica blau1(11);
SortidaAnalogica blau2(10);

EntradaDigital botoEntrada(34);
EntradaDigital botoSortida(35);

Brunzidor brunzidor(9);

Ultrasons ultrasons(22, 7, &blau1, &blau2);

Barrera barrera(13, &vermell, &verd, &brunzidor);

Pantalla lcd;

Comandament comandament(28);

unsigned int places = 3;

void setup() {
    vermell.begin();
    verd.begin();

    blau1.begin();
    blau2.begin();

    botoEntrada.begin();
    botoSortida.begin();

    brunzidor.begin();
    ultrasons.begin();
    barrera.begin();

    lcd.begin();

    Serial.begin(9600);

    lcd.update("Benvinguts", "Places: " + String(places));
}

void loop() {
    Actions button = comandament.read();

    int sortida = botoSortida.read() || button == EXIT;
    int entrada = botoEntrada.read() || ultrasons.isClose() || button == ENTER;

    if ((sortida != entrada) && !barrera.isOpen) {
        // Algun botó premut o distància propera

        if (entrada && places == 0) {
            // Entrada demanada, no hi ha places
            lcd.update("Parking ple", "No pots passar", 1500);
            brunzidor.tone(200, 400);
        } else {
            barrera.open();

            if (sortida) {
                lcd.update("Fins aviat", "");

                ++places;
            } else {
                lcd.update("Benvinguts", "");

                --places;
            }
        }
    } else {
    }

    // | sol per forçar evaluació d'ambdues expressions
    // amb || es curtcircuiten
    if (barrera.checkTime() | lcd.checkTime()) {
        lcd.update("Benvinguts",
                   places == 0 ? "Parking ple" : "Places: " + String(places));
    }
    delay(50);
}
