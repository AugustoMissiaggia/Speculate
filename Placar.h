#ifndef SPECULATE_PLACAR_H
#define SPECULATE_PLACAR_H
#include <string>

class Placar {
private:
    int numDeRodadas;
    int partida;
    std::string nome;
public:
    Placar();
    void armazenarRodadas();
    void armazenaPartida(int contador);
    void armazenaNome(std::string nomeJogador);
    void zeraRodadas();
    int mostraNumDeRodadas();
   std::string mostraPlacar();



};


#endif
