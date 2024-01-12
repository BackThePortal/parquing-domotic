#ifndef Lector_h
#define Lector_h
#include <Arduino.h>
#include <EasyMFRC522.h>

class Lector : EasyMFRC522 {
   protected:
    int pinSDA;
    int pinRST;

   public:
    Lector(int _pinSDA, int _pinRST);
    void begin();
    bool detect();
    bool detectWait();

    bool write(String label, String data);
    int read(String label);

};

#endif