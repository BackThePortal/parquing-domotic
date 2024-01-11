#include <Servo.h>

#include "Barrera.h"
#include "Brunzidor.h"
#include "EntradaDigital.h"
#include "Pantalla.h"
#include "SortidaDigital.h"
#include "Ultrasons.h"
#include "Comandament.h"

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

    lcd.update("Benvinguts", "Place: " + String(places));
}

void loop() {
    int sortida = botoSortida.read();
    int entrada = botoEntrada.read() || ultrasons.isClose();

    comandament.check();

    // XOR
    if ((sortida != entrada) && !barrera.isOpen) {
        if (sortida || places > 1) {
            barrera.open();

            if (sortida) {
                lcd.update("Fins aviat", "");

                ++places;
            } else {
                lcd.update("Benvinguts", "");

                if (places > 0) {
                    --places;
                }
            }
        } else {
            lcd.update("Parking ple", "");
        }
    } else {
    }

    if (barrera.checkTime()) {
        lcd.update("Benvinguts", "Places: " + String(places));
    }
    delay(50);
}
