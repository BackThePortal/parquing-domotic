#ifndef Estat_h
#define Estat_h

#include <Arduino.h>
#include "EntradaDigital.h"
#include "Barrera.h"

class Estat {
   private:
    EntradaDigital* botoEntrada;
    EntradaDigital* botoSortida;
    Barrera* barrier;
   public:
    Estat(EntradaDigital* _enterButton, EntradaDigital* _exitButton, Barrera* _barrier);

    void c


};

#endif