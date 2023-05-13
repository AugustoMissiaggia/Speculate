#include "Jogo.h"
#include "Tabuleiro.h"
#include "Dado.h"
#include "Placar.h"
#include <limits>
#include <fstream>
using namespace std;

Jogo::Jogo(){ //Chamando construtores
    jogador1 = Jogador();
    jogador2 = Jogador();
    tabuleiro = Tabuleiro();
    dado = Dado();

}
void Jogo::iniciarJogo() {
    Placar* placar = new Placar[100]; //Alocar de forma dinamica varios reultados
    int contador = 1; //Contador referente a partida
    int numeroRodada=0;//Contador para auxiliar a alocar o placar
    start: //Ponto de retorno para continuar jogando sem reiniciar
    char c; //Variavel criada meramente para fazer o jogo rodar aos poucos
    cout << "Iniciando o jogo..." << endl;
    string nome;
    cout << "Inserir nome" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,nome);
    jogador1.defineNome(nome);                          // Chamada dos metodos para atribuir nomes, num de bolas, criar o tabuleiro
    jogador2.defineNome("Computador");
    jogador1.defineBolas(15);
    jogador2.defineBolas(15);
    tabuleiro.colocarBola(0);
    tabuleiro.colocarBola(2);
    tabuleiro.colocarBola(4);
    placar[numeroRodada].zeraRodadas(); //Zera as rodadas quando inicia uma partida nova

    cout << "Tabuleiro:" << endl;
    cout << tabuleiro.mostraTabuleiro() << endl;
    while (1 > 0) {     //loop infinito que so acaba quando alguem ganha o jogo
        int numDeLancamentos = 0; // Variavel que auxilia nos lancamento dos dados
        cout << jogador1.obtemNome() << " Voce possui: " << jogador1.numDeBolas()
             << " Bolas. Quantas vezes deseja girar o dado ?" << endl;
        cin >> numDeLancamentos;
        if (numDeLancamentos < 1 || numDeLancamentos > jogador1.numDeBolas()) { //condicao para nao deixar usuario colocar numero invalido de lancamentos
            while (numDeLancamentos < 1 || numDeLancamentos > jogador1.numDeBolas()) {
                cout << "Jogada invalida, insira um valor que corresponda ao seu numero de bolas" << endl;
                cin >> numDeLancamentos;
            }
        }
        for (int i = 0; i < numDeLancamentos; i++) {//loop para fazer os dados girarem
            int valor = dado.jogarDado();
            switch (valor) {//condicao para cada possivel caso do dado
                case 1:
                    if (tabuleiro.casaOcupada(0)) {//cout<<"digite qualquer coisa para continuar..."; cin >> c; //mensagem para fazer o jogo rodar aos poucos
                        tabuleiro.removerBola(0);       //ajusta tabuleiro, bolas do jogador e placar
                        jogador1.PegaUmaBola();
                        placar[numeroRodada].armazenarRodadas();
                    } else if (tabuleiro.casaVazia(0)) {//cout<<"digite qualquer coisa para continuar..."; cin >> c;
                        tabuleiro.colocarBola(0);
                        jogador1.ColocaUmaBola();
                        placar[numeroRodada].armazenarRodadas();
                    }
                    break;
                case 2:
                    if (tabuleiro.casaOcupada(1)) {//cout<<"digite qualquer coisa para continuar..."; cin >> c;
                        tabuleiro.removerBola(1);
                        jogador1.PegaUmaBola();
                        placar[numeroRodada].armazenarRodadas();
                    } else if (tabuleiro.casaVazia(1)) {//cout<<"digite qualquer coisa para continuar..."; cin >> c;
                        tabuleiro.colocarBola(1);
                        jogador1.ColocaUmaBola();
                        placar[numeroRodada].armazenarRodadas();
                    }
                    break;
                case 3:
                    if (tabuleiro.casaOcupada(2)) {//cout<<"digite qualquer coisa para continuar..."; cin >> c;
                        tabuleiro.removerBola(2);
                        jogador1.PegaUmaBola();
                        placar[numeroRodada].armazenarRodadas();
                    } else if (tabuleiro.casaVazia(2)) {//cout<<"digite qualquer coisa para continuar..."; cin >> c;
                        tabuleiro.colocarBola(2);
                        jogador1.ColocaUmaBola();
                        placar[numeroRodada].armazenarRodadas();
                    }
                    break;
                case 4:
                    if (tabuleiro.casaOcupada(3)) {//cout<<"digite qualquer coisa para continuar..."; cin >> c;
                        tabuleiro.removerBola(3);
                        jogador1.PegaUmaBola();
                        placar[numeroRodada].armazenarRodadas();
                    } else if (tabuleiro.casaVazia(3)) {//cout<<"digite qualquer coisa para continuar..."; cin >> c;
                        tabuleiro.colocarBola(3);
                        jogador1.ColocaUmaBola();
                        placar[numeroRodada].armazenarRodadas();
                    }
                    break;
                case 5:
                    if (tabuleiro.casaOcupada(4)) {//cout<<"digite qualquer coisa para continuar..."; cin >> c;
                        tabuleiro.removerBola(4);
                        jogador1.PegaUmaBola();
                        placar[numeroRodada].armazenarRodadas();
                    } else if (tabuleiro.casaVazia(4)) {//cout<<"digite qualquer coisa para continuar..."; cin >> c;
                        tabuleiro.colocarBola(4);
                        jogador1.ColocaUmaBola();
                        placar[numeroRodada].armazenarRodadas();
                    }
                    break;
                case 6:
                    //cout<<"digite qualquer coisa para continuar..."; cin >> c;
                    tabuleiro.colocarNa6();
                    jogador1.ColocaUmaBola();
                    placar[numeroRodada].armazenarRodadas();
                    break;
            }
            cout << "lancamento " << i + 1 << " voce obteve " << valor << " no dado e agora esta com "
                 << jogador1.numDeBolas() << " bolas o tabuleiro se encotra desse jeito: "
                 << tabuleiro.mostraTabuleiro() << endl;
        }

        numDeLancamentos = jogador2.numDeBolas();  //Jogada padrao do computador que sempre joga o que tem na mao

        cout << "Vez do Computador!" << endl;

        cout << "O Computador possui: " << jogador2.numDeBolas() << " E vai jogar o dado esse mesmo numero de vezes!"
             << endl;
        for (int j = 0; j < numDeLancamentos; j++) {
            int valor = dado.jogarDado();
            switch (valor) {
                case 1:
                    if (tabuleiro.casaOcupada(0)) {//cout<<"digite qualquer coisa para continuar..."; cin >> c;
                        tabuleiro.removerBola(0);
                        jogador2.PegaUmaBola();

                    } else if (tabuleiro.casaVazia(0)) {//cout<<"digite qualquer coisa para continuar..."; cin >> c;
                        tabuleiro.colocarBola(0);
                        jogador2.ColocaUmaBola();
                    }
                    break;
                case 2:
                    if (tabuleiro.casaOcupada(1)) {//cout<<"digite qualquer coisa para continuar..."; cin >> c;
                        tabuleiro.removerBola(1);
                        jogador2.PegaUmaBola();
                    } else if (tabuleiro.casaVazia(1)) {//cout<<"digite qualquer coisa para continuar..."; cin >> c;
                        tabuleiro.colocarBola(1);
                        jogador2.ColocaUmaBola();
                    }
                    break;
                case 3:
                    if (tabuleiro.casaOcupada(2)) {//cout<<"digite qualquer coisa para continuar..."; cin >> c;
                        tabuleiro.removerBola(2);
                        jogador2.PegaUmaBola();
                    } else if (tabuleiro.casaVazia(2)) {//cout<<"digite qualquer coisa para continuar..."; cin >> c;
                        tabuleiro.colocarBola(2);
                        jogador2.ColocaUmaBola();
                    }
                    break;
                case 4:
                    if (tabuleiro.casaOcupada(3)) {//cout<<"digite qualquer coisa para continuar..."; cin >> c;
                        tabuleiro.removerBola(3);
                        jogador2.PegaUmaBola();
                    } else if (tabuleiro.casaVazia(3)) {//cout<<"digite qualquer coisa para continuar..."; cin >> c;
                        tabuleiro.colocarBola(3);
                        jogador2.ColocaUmaBola();
                    }
                    break;
                case 5:
                    if (tabuleiro.casaOcupada(4)) {//cout<<"digite qualquer coisa para continuar..."; cin >> c;
                        tabuleiro.removerBola(4);
                        jogador2.PegaUmaBola();
                    } else if (tabuleiro.casaVazia(4)) {//cout<<"digite qualquer coisa para continuar..."; cin >> c;
                        tabuleiro.colocarBola(4);
                        jogador2.ColocaUmaBola();
                    }
                    break;
                case 6:
                    //cout<<"digite qualquer coisa para continuar..."; cin >> c;
                    tabuleiro.colocarNa6();
                    jogador2.ColocaUmaBola();
                    break;
            }
            cout << "Lancamento " << j + 1 << " o computador obteve " << valor << " no dado e agora esta com "
                 << jogador2.numDeBolas() << " bolas, o tabuleiro esta assim: " << tabuleiro.mostraTabuleiro() << endl;
        }

        if (jogador1.numDeBolas() <= 0) { //condicao de parada caso o usuario ganhe o jogo
            placar[numeroRodada].armazenaPartida(contador);
            cout << "PARABENS " << jogador1.obtemNome() << " VOCE GANHOU!!!" << endl;
            tabuleiro.removerBola(0);
            tabuleiro.removerBola(1);
            tabuleiro.removerBola(2);               //zera o tabuleiro e as bolas dos jogadores e armazena nome, numero de rodadas;
            tabuleiro.removerBola(3);
            tabuleiro.removerBola(4);
            tabuleiro.zeraCasa6();
            jogador1.zerarBolas();
            jogador2.zerarBolas();
            placar[numeroRodada].armazenaNome(nome);
            placar[numeroRodada].armazenarRodadas();
            numeroRodada++; //aumento na auxiliar que vai salvar um novo placar caso ocorrer vitoria
            contador++;//aumento na auxilir responsavel por dizer o numero da partida
            break;
        }
        if (jogador2.numDeBolas() <= 0) {
            placar[numeroRodada].armazenaPartida(contador);
            cout << "Sinto muito " << jogador1.obtemNome() << " o Computador venceu dessa vez" << endl;
            tabuleiro.removerBola(0);
            tabuleiro.removerBola(1);
            tabuleiro.removerBola(2);
            tabuleiro.removerBola(3);
            tabuleiro.removerBola(4);
            tabuleiro.zeraCasa6();
            jogador1.zerarBolas();
            jogador2.zerarBolas();
            contador++;
            break;

        }

    }
    cout << "Deseja jogar novamente ou sair do jogo? " << endl;
    cout << "Digite 1 para iniciar uma partida" << endl;
    cout << "Digite 2 se quiser salvar seus resultados e reiniciar" << endl;
    int opcao;
    int p=1;
    while ( p != 0) { //loop similar ao main para fazer usuario escolher uma opcao
        cin >> opcao;
        switch (opcao) {
            case 1:
                goto start; //inicia nova partida sem reiniciar, indo para start
            case 2:
                p=0;
                break;
            default:
                cout << "Opcao invalida." << endl;
                break;
        }

    }

    for (int i = 0; i < numeroRodada - 1; ++i) {            //Ordena os melhores resultados
        for (int j = i + 1; j < numeroRodada; ++j) {
            if (placar[i].mostraNumDeRodadas() > placar[j].mostraNumDeRodadas()) {
                Placar temp = placar[i];
                placar[i] = placar[j];
                placar[j] = temp;
            }
        }
    }

    ofstream arquivo("resultados.txt", ios::app);         //Cria um arquivo txt e armazena os melhores resultados sem sob escreve-los
    if(numeroRodada<10){ for (int i = 0; i < numeroRodada; ++i) { //Salvar e imprimir no arquivo quando tem menos de 10 resultados
            arquivo << placar[i].mostraPlacar() << endl;}
    }else{for (int i = 0; i < 10; ++i) { //Salvar e imprimir no arquivo apenas os 10 melhores resultados
            arquivo << placar[i].mostraPlacar() << endl;}
    }
    arquivo << "Reiniciou o jogo" << endl;

    arquivo.close();


}





