#include "ComputerP.h"

void ComputerP::alterMove(char* ch, char input)
{
	if (input == ESCAPE)
		*ch = input;
	else
	{
		computerMove(ch);
	}
}

void ComputerP::computerMove(char* ch) const
{
	int number = rand() % 100;
	switch (level)
	{
	case BEST:
		*ch = bestMove();
		break;
	case GOOD:
		if(number<95)
			*ch = bestMove();
		else
			*ch = randomMove();
		break;
	case NOVICE:
		if (number < 90)
			*ch = bestMove();
		else
			*ch = randomMove();
		break;
	default:
		break;
	}
}

char ComputerP::bestMove() const
{
	
}

char ComputerP::randomMove()const
{
	int number = rand() % NUM_OF_MOVES;

}
