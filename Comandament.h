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

    Pair actions[4] = {{Buttons::UP, ENTER}, {Buttons::DOWN, EXIT}};
};

#endif