#ifndef _Game
#define _Game

enum TETRIMINO {};
#include "General.h"
#include "GameConfig.h"
#include "Player.h"
#include <cstring>

class Game {
		
	Player p1;
	Player p2;
	bool winner = false;
	
	void drawBorders();
	bool checkHit(Player player);
	bool checkWinner();
	int printMenu(bool gameFinished);
	void printInstructions();
	void movePieces(char* ch1, char* ch2);
	void getMove(char* ch1, char* ch2);
	void performMove(char* ch1, char* ch2);
	void drop(Player& p);
	bool process();
	void startNewGame();

public:
	void run(); // menu

};


#endif
