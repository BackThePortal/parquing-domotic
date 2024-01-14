#include "Comandament.h"

#include <IRremote.hpp>

Comandament::Comandament(int _pin) : pin(_pin) {}

void Comandament::begin() { IrReceiver.begin(this->pin, ENABLE_LED_FEEDBACK); }


Pair actionsList[12] = {
        {Buttons::UP, ENTER},         {Buttons::DOWN, EXIT},
        {Buttons::ONE, USER_ONE},     {Buttons::TWO, USER_TWO},
        {Buttons::THREE, USER_THREE}, {Buttons::FOUR, USER_FOUR},
        {Buttons::FIVE, USER_FIVE},   {Buttons::SIX, USER_SIX},
        {Buttons::SEVEN, USER_SEVEN}, {Buttons::EIGHT, USER_EIGHT},
        {Buttons::NINE, USER_NINE}
};

int getUserIndex(Actions &b) {
    return b - 2;
}

bool isUserAction(Actions &b) {
    return (b == USER_ONE) || (b == USER_TWO) || (b == USER_THREE) ||
            (b == USER_FOUR) || (b == USER_FIVE) || (b == USER_SIX) ||
            (b == USER_SEVEN) || (b == USER_EIGHT) || (b == USER_NINE);
}

Actions Comandament::read() {
    if (IrReceiver.decode()) {

        // unsigned long, vegeu codi font de IrReceiver
        unsigned long data = IrReceiver.decodedIRData.decodedRawData;
        Serial.println(data, HEX);

        // Cercar codi a la llista de botons. ús de punters perquè són guais
        // utilitzaria decomposition declaration però l'arduino està antiquat
        // for (auto &&[button, action] : this->actions)
        
        for (auto &&item : actionsList)
            if (item.code == data) return item.action;
        IrReceiver.resume();
    }

    // No s'ha trobat cap botó. Retornar el botó _NULL (amb valor 0)
    return _NULL;
}