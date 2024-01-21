#ifndef _Player
#define _Player

#include "Board.h"
#include "Piece.h"


class Player {
	 // maybe this is the current piece handed to the player

public:
	Board board;			// might be private
	Piece currPiece;
	bool isPieceHit = true;

	void setBoard() { this->board.initBoard(); }
};

#endif
