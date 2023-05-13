#include "Jogo.h"
using namespace std;

int main() {
    int var = 1;
    int opcao;
    Jogo jogo;
    do  {
    cout << "Digite 1 para iniciar uma partida!" << endl;
    cout << "Digite 2 para sair do jogo" << endl;

        cin >> opcao;
        switch (opcao) {
            case 1:
                jogo.iniciarJogo();
                break;
            case 2:
                var = 0;
                break;
            default:
                    cout << "Opcao invalida." << endl;
                break;
        }
    }while(var!=0);
            return 0;
        }

