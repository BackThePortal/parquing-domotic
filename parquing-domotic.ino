#include <Servo.h>

#include "Barrera.h"
#include "Brunzidor.h"
#include "Comandament.h"
#include "EntradaDigital.h"
#include "Lector.h"
#include "Pantalla.h"
#include "SortidaDigital.h"
#include "Ultrasons.h"

#define MAX_STRING_SIZE 100

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

Lector lector(0, 0);

unsigned int places = 3;

unsigned long targetaCooldown = 0;

void pantallaIdle() {
    lcd.update("Benvinguts",
               places == 0 ? "Parking ple" : "Places: " + String(places));
}

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
    while (!Serial)
        ;

    lector.begin();
}

void loop() {
    Actions action = comandament.read();

    if (Comandament::isUserAction(action)) {
        int user = Comandament::getUserIndex(action);
        lcd.update("Usuari " + String(user), "Passa targeta");

        lector.detectWait();

        if (lector.write("user", String(user))) {
            lcd.update("Usuari " + String(user), "Registrat");
        } else {
            lcd.update("Usuari " + String(user), "Error");
        }
        return;
    }

    bool ambTargeta =
        (targetaCooldown == 0 || millis() - targetaCooldown > 2000) &&
        lector.detect();

    int sortida = botoSortida.read() || action == EXIT;
    int entrada = botoEntrada.read() || ultrasons.isClose() ||
                  action == ENTER || ambTargeta;

    int user = 0;

    if (ambTargeta && places > 0) {
        lcd.update("Passi detectat", "");
        delay(200);

        int u = lector.read("user");

        if (u < 1) {
            lcd.update("Error de lectura", "");
        } else
            user = u;
    }

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
                lcd.update("Benvingut", user == 0 ? "Anonim" : ("Usuari " + String(user)));

                --places;
            }
        }
    } else {
    }

    // | sol per forçar evaluació d'ambdues expressions
    // amb || es curtcircuiten
    if (barrera.checkTime() | lcd.checkTime()) {
        pantallaIdle();
    }
    delay(50);
}
