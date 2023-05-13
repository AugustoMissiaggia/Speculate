#include "Dado.h"
#include <cstdlib>
#include <ctime>

Dado::Dado() {
    valor = 1;
    srand(time(NULL));
}

int Dado::jogarDado() {
    valor = rand() % 6 + 1;
    return valor;
}

