#ifndef _Board
#define _Board
#include "General.h"
#include "GameConfig.h"
#include "Piece.h"

static constexpr int BOMB_RADIUS = 4;

class Board 
{
	bool isRowFull(const int row) const;
	void shiftRowsDown(const int startRow);

	void performBomb(const Point& p, const int playerOffset);
	void applyGravity(const int playerOffset);
	int getMax(const int a, const int b) const { return (a > b) ? a : b; }
	int getMin(const int a, const int b) const { return (a < b) ? a : b; }
public:
	char board[GameConfig::GAME_HEIGHT][GameConfig::GAME_WIDTH]; // move to private. use get() and set()

	void initBoard();
	void clearRows(const Piece& piece);
	void printBoard(const int min) const;
	void insertPiece(const Piece& piece, const int playerOffset);

};

#endif
