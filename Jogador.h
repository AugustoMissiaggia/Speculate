#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>

class Jogador {
private:
    std::string nome;
    int numBolas;

public:
    Jogador();
    void defineNome(std::string);
    void defineBolas(int bolas);
    void PegaUmaBola();
    void ColocaUmaBola();
    int numDeBolas();
    void zerarBolas();
    std::string obtemNome();
};

#endif