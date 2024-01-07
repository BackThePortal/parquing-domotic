#include "Motor.h"
#include "Servo.h"

Motor::Motor(int pin) : Servo() { this->attach(pin); }