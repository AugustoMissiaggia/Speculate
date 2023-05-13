#include "Jogador.h"
using namespace std;
Jogador::Jogador() {
    nome = nome;
    numBolas = numBolas;
}

void Jogador::defineNome(string nomee)  {
   nome = nomee;
}
void Jogador::defineBolas(int bolas){
    numBolas = bolas;
}
void Jogador:: PegaUmaBola()  {
   numBolas++;
}

void Jogador:: ColocaUmaBola() {
    numBolas--;
}

int Jogador:: numDeBolas() {
    return numBolas;
}
    std::string Jogador::obtemNome(){
        return nome;

}

void Jogador:: zerarBolas(){
    numBolas=0;
}