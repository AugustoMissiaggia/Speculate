#ifndef JOGO_H
#define JOGO_H

#include <iostream>
#include "Tabuleiro.h"
#include "Dado.h"
#include "Jogador.h"
#include "Placar.h"
class Jogo {
private:
    Jogador jogador1;
    Jogador jogador2;
    Tabuleiro tabuleiro;
    Dado dado;

public:
    Jogo ();
    void iniciarJogo();

};

#endif
