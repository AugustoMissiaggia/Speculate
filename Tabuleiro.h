#ifndef TABULEIRO_H
#define TABULEIRO_H
#include <string>
class Tabuleiro {
private:
    int casas[5];
    int casa6;

public:
    Tabuleiro();
    void colocarBola(int valor);
    void removerBola(int valor);
    void colocarNa6 ();
    bool casaOcupada(int valor);
    bool casaVazia  (int valor);
    void zeraCasa6  ();
    std::string mostraTabuleiro();
};

#endif

