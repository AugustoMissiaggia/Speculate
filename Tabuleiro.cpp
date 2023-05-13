#include "tabuleiro.h"
#include <iostream>
#include <string>
using namespace std;
Tabuleiro::Tabuleiro() {
    casas[0] = 0;
    casas[1] = 0;
    casas[2] = 0;
    casas[3] = 0;
    casas[4] = 0;
    casa6 = 0;
}

    void Tabuleiro::colocarBola(int valor) {
            casas[valor] = 1;
    }

    void Tabuleiro::removerBola(int valor) {
            casas[valor] = 0;
    }
    void Tabuleiro:: colocarNa6(){
    casa6++;
}

    bool Tabuleiro:: casaOcupada(int valor){
    if (casas[valor]==1){
        return true;
    }else return false;
}

bool Tabuleiro:: casaVazia(int valor){
    if (casas[valor]==0){
        return true;
    }else return false;

}

void Tabuleiro:: zeraCasa6(){
    casa6 = 0;
}

std::string Tabuleiro::mostraTabuleiro(){
    std::string tabuleiro;
    tabuleiro += "|" + std::to_string(casas[0]) + "|";
    tabuleiro += std::to_string(casas[1]) + "|";
    tabuleiro += std::to_string(casas[2]) + "|";
    tabuleiro += std::to_string(casas[3]) + "|";
    tabuleiro += std::to_string(casas[4]) + "|";
    tabuleiro += std::to_string(casa6) + "|\n";
    return tabuleiro;
}
