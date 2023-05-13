#include "Placar.h"
#include <string>

Placar::Placar(){
    numDeRodadas = numDeRodadas;
    partida = 0;
    nome = nome;
}
void Placar::armazenaNome(std::string nomeJogador) {
    nome = nomeJogador;
}

void Placar::armazenarRodadas(){
    numDeRodadas++;

}

void Placar::zeraRodadas() {
    numDeRodadas = 0;
}

void Placar::armazenaPartida(int contador) {
    partida = contador;
}
int Placar::mostraNumDeRodadas(){
    return numDeRodadas;
}

std::string Placar::mostraPlacar() {

    std::string Placar;
        Placar += "Partida:" + std::to_string(partida) ;
        Placar += "| Nome do jogador:" + nome + "| Numero de rodadas ate a vitoria:";
        Placar += std::to_string(numDeRodadas) + "|";
        return Placar;
    }


