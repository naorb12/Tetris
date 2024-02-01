#ifndef _Game
#define _Game

#include "General.h"
#include "GameConfig.h"
#include "Player.h"
#include <cstring>

enum menuInput
{
	startGame = 1, continueGame = 2, instructions = 8, exitGame = 9
};

enum keyPlayer1
{
	left1 = 97, LEFT1 = 65, right1 = 100, RIGHT1 = 68, rotateclock1 = 115, ROTATECLOCK1 = 83, rotatecounterclock1 = 119, ROTATECOUNTERCLOCK1 = 87,
	drop1 = 120, DROP1 = 88
};

enum keyPlayer2
{
	left2 = 106, LEFT2 = 74, right2 = 108, RIGHT2 = 76, rotateclock2 = 107, ROTATECLOCK2 = 75, rotatecounterclock2 = 105, ROTATECOUNTERCLOCK2 = 73,
	drop2 = 109, DROP2 = 77
};

constexpr char NULL_CHAR = '\0';
constexpr char ESCAPE = 27;
constexpr char HORIZON_BORDER = '-';
constexpr char VERTICAL_BORDER = '|';


class Game {

	Player p1;
	Player p2;
	bool winner = false;

	void drawBorders() const;
	bool checkHit(const Player& player) const;
	void performHit(Player& player);
	bool checkWinner() const;
	int printMenu(bool gameFinished) const;
	void printInstructions() const;
	void movePieces(char* ch1, char* ch2);
	void getMove(char* ch1, char* ch2) const;
	void performMove(char* ch1, char* ch2);
	void drop(Player& p);
	bool process();
	void startNewGame();


public:
	void run(); // menu

};


#endif