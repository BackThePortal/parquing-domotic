#include "Estat.h"

#include "EntradaDigital.h"

Estat::Estat(EntradaDigital* _enterButton, EntradaDigital* _exitButton,
             Barrera* _barrier)
    : botoEntrada(_enterButton), botoSortida(_exitButton), barrier(_barrier) {}
