#ifndef Lector_h
#define Lector_h

#include <Arduino.h>
#include <MFRC522.h>
#include <SPI.h>

/*
Pablo Sampaio, m'has defraudat, la teva llibreria
EasyMFRC522 no funciona...
*/
class Lector : MFRC522 {
   private:
    int pinSDA;
    int pinRST;
    int t;
   public:
    Lector(int _pinSDA, int _pinRST);
    void begin();
    bool detect();
    bool detectWait();
    /*
    bool write(String label, String data);
    int read(String label);
    */
};

#endif