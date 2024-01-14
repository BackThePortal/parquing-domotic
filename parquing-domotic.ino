#include <Servo.h>

#include "Barrera.h"
#include "Brunzidor.h"
// #include "Comandament.h"
#include "EntradaDigital.h"
#include "Lector.h"
#include "Pantalla.h"
#include "SortidaAnalogica.h"
#include "SortidaDigital.h"
#include "Ultrasons.h"

/*

Canvis:

led vermell   51 --> 47
led verd      50 --> 46
led blau 1    11 --> 5
led blau 2    10 --> 4




*/

SortidaDigital vermell(47);
SortidaDigital verd(46);

SortidaAnalogica blau1(5);
SortidaAnalogica blau2(4);

EntradaDigital botoEntrada(34);
EntradaDigital botoSortida(35);

Brunzidor brunzidor(9);

Ultrasons ultrasons(22, 7, &blau1, &blau2);

Barrera barrera(12, &vermell, &verd, &brunzidor);

// Comandament comandament(8);

Lector lector(53, 45);

// Nombre de places totals al pàrquing
const unsigned int placesTotal = 4;

// Nombre de places lliures. Comencem amb una plaça
// ocupada per permetre la sortida un cop.
unsigned int places = 3;

Pantalla lcd(places);


const unsigned long pantallaCooldown = 3000;

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
    lector.begin();
    // comandament.begin();

    Serial.begin(9600);

    // Esperar fins que la comunicació estigui disponible
    while (!Serial)
        ;
}

void loop() {
    /*
    Codi que vaig escriure per al registre d'usuaris.
    Per desgràcia ja no serveix...

    Actions action = comandament.read();

    if (isUserAction(action)) {
        int user = getUserIndex(action);
        lcd.update("Usuari " + String(user), "Passa targeta");

        lector.detectWait();


        lcd.update("Usuari " + String(user), "Escrivint...");
        delay(200);

        if (lector.write("user", String(user))) {
            lcd.update("Usuari " + String(user), "Registrat");
        } else {
            lcd.update("Usuari " + String(user), "Error d'escript.");
        }
        delay(1000);
        targetaCooldown = millis();
        pantallaIdle();
        return;
    }
*/
    // El mètode detect() té un temporitzador integrat. Vegeu "lector.h".
    bool ambTargeta = lector.detect();

    // "type cast" de nombres, si la diferència entre les places lliures i el
    // nombre de places al pàrquing és 0, aleshores es converteix a false i no
    // es permet la sortida.
    int sortida =
        botoSortida.read() && (placesTotal - places);  //|| action == EXIT;

    // & sol per forçar evaluació d'ambdues expressions.
    // amb && es "curtcircuiten", si el primer és false, el
    // segon ja no s'executa, i no volem això, perquè els
    // leds blaus depenen de l'ultrasons.
    int entrada = (botoEntrada.read() & ultrasons.isClose()) || ambTargeta;
    //  action == ENTER;

    /*
    Codi per a l'entrada d'usuaris registrats
        if (ambTargeta && places > 0) {
            lcd.update("Passi detectat", "Llegint");
            delay(200);

            int u = lector.read("user");

            if (u < 1) {
                lcd.update("Error de lectura", "");
                entrada = false;
            } else{
                user = u;}

            delay(1000);

            if (u < 1) pantallaIdle();
            targetaCooldown = millis();

        }*/
    

    // != amb booleans és l'operador XOR; retorna true si
    // algun dels operands és true, però si els dos ho són,
    // retorna false. Això és per evitar que ambdues accions
    // puguin ser executades.
    if ((sortida != entrada) && !barrera.isOpen) {
        // Algun botó premut o distància propera

        if (entrada && places == 0) {
            // Entrada demanada, no hi ha places

            lcd.update("Parking ple", "No pots passar", pantallaCooldown);
            brunzidor.tone(200, 400);
        } else {
            barrera.open(4000);

            if (sortida) {
                lcd.update("Fins aviat", "", pantallaCooldown);

                ++places;
            } else {
                // Si s'ha utilitzat la targeta, l'usuari és 1
                // si no, 0 (anònim).
                // Amb el comandament, l'usuari s'assignaria al
                // codi comentat de més a dalt.
                int user = ambTargeta;

                lcd.update("Benvingut",
                           user == 0 ? "Anonim" : ("Usuari " + String(user)),
                           pantallaCooldown);

                --places;
            }
        }
    }

    // Comprovar temporitzadors
    barrera.checkTime();
    lcd.checkTime();

    // Interval de temps per no apressurar l'Arduino
    // (si no, s'enfada... és molt susceptible)
    delay(50);
}
