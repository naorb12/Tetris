#ifndef _Board
#define _Board
#include "General.h"
#include "GameConfig.h"
#include "Piece.h"


class Board 
{
	bool isRowFull(const int row) const;
	void shiftRowsDown(const int startRow);

public:
	char board[GameConfig::GAME_HEIGHT][GameConfig::GAME_WIDTH]; // move to private. use get() and set()

	void initBoard();
	void clearRows(const Piece& piece);
	void printBoard(const int min) const;
	void insertPiece(const Piece& piece);

};

#endif
