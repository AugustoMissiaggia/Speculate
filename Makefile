all: app

app: application.o Dado.o Jogador.o Placar.o Tabuleiro.o Jogo.o
	g++ -o app application.o Dado.o Jogador.o Placar.o Tabuleiro.o Jogo.o

application.o: application.cpp Jogo.h
			   g++ -c application.cpp
Dado.o:	Dado.cpp Dado.h
		g++ -c Dado.cpp
Jogador.o: Jogador.cpp Jogador.h
		  g++ -c Jogador.cpp
Placar.o: Placar.cpp Placar.h
			g++ -c Placar.cpp
Tabuleiro.o: Tabuleiro.cpp Tabuleiro.h
			g++ -c Tabuleiro.cpp
Jogo.o: Jogo.cpp Jogo.h Tabuleiro.h Placar.h Jogador.h Dado.h
			g++ -c Jogo.cpp
clean:
	rm Jogo.o Tabuleiro.o Placar.o Jogador.o Dado.o application.o app
