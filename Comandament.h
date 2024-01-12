#ifndef Comandament_h
#define Comandament_h

#include <Arduino.h>

enum Buttons {
    UP = 0xF609FF00UL,
    DOWN = 0xF807FF00UL,
    UP_VOLUME = 0xB946FF00UL,
    DOWN_VOLUME = 0xEA15FF00UL,
    ONE = 0x00000000UL,
    TWO = 0x00000000UL,
    THREE = 0x00000000UL,
    FOUR = 0x00000000UL,
    FIVE = 0x00000000UL,
    SIX = 0x00000000UL,
    SEVEN = 0x00000000UL,
    EIGHT = 0x00000000UL,
    NINE = 0x00000000UL,
};

enum Actions {
    _NULL,  // 0
    ENTER,  // 1
    EXIT,   // 2
    USER_ONE,
    USER_TWO,
    USER_THREE,
    USER_FOUR,
    USER_FIVE,
    USER_SIX,
    USER_SEVEN,
    USER_EIGHT,
    USER_NINE
};

struct Pair {
    Buttons code;
    Actions action;
};

class Comandament {
   protected:
    int pin;

   public:
    Comandament(int _pin);
    void begin();
    Actions read();

    Pair actions[12] = {
        {Buttons::UP, ENTER},         {Buttons::DOWN, EXIT},
        {Buttons::ONE, USER_ONE},     {Buttons::TWO, USER_TWO},
        {Buttons::THREE, USER_THREE}, {Buttons::FOUR, USER_FOUR},
        {Buttons::FIVE, USER_FIVE},   {Buttons::SIX, USER_SIX},
        {Buttons::SEVEN, USER_SEVEN}, {Buttons::EIGHT, USER_EIGHT},
        {Buttons::NINE, USER_NINE}};

    static bool isUserAction(Actions &b) {
        return (b == USER_ONE) || (b == USER_TWO) || (b == USER_THREE) ||
               (b == USER_FOUR) || (b == USER_FIVE) || (b == USER_SIX) ||
               (b == USER_SEVEN) || (b == USER_EIGHT) || (b == USER_NINE);
    }

    static int getUserIndex(Actions &b) {
        return b - 2;
    }
};

#endif