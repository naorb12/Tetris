#ifndef _Player
#define _Player

#include "Board.h"
#include "Piece.h"


class Player {

public:
	Board board;
	Piece currPiece;
	bool isPieceHit = true;

	// This function initialise a PLAYER'S board
	void setBoard() { this->board.initBoard(); }
	virtual void alterMove(char* ch, char input) = 0;
};

#endif
