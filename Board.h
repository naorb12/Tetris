#ifndef _Board
#define _Board
#include "General.h"
#include "GameConfig.h"
#include "Piece.h"


class Board {
public:
	char board[GameConfig::GAME_HEIGHT][GameConfig::GAME_WIDTH];

	void initBoard();
	bool isRowFull(int row);
	void shiftRowsDown(int startRow);
	void clearRows(const Piece& piece);
	void printBoard(const int min);
	void insertPiece(Piece piece); 

};

#endif
