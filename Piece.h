#ifndef _Piece
#define _Piece
#include <iostream>
#include <fstream>
#include <ctime>

enum blockName
{
	I, J, L, O, S, T, Z, B
};

#include "GameConfig.h"
#include "Point.h"

class Board; // Forward declaration

class Piece
{
private:
	int pieceType;
	int setPieceType();
	
public:
	Point tetrimino[GameConfig::PIECE_SIZE];

	//set piece
	void buildpiece();

	//get type
	int getPieceType() const { return pieceType; }

	//move piece
	void moveRight(const Board& board);
	void moveleft(const Board& board);
	void rotateClockwise(const Board& board);
	void rotateCounterClockwise(const Board& board);
};
#endif
