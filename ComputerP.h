#ifndef _Computer
#define _Computer

#include "Player.h"

constexpr char ESCAPE = 27;
constexpr char NUM_OF_MOVES = 6;

enum Level{ NOVICE, GOOD, BEST};
enum Moves{ LEFT, RIGHT, ROTATE_CW, ROTATE_CCW, DROP, NOTHING};

class ComputerP : public Player {

	int level;
	void computerMove(char* ch) const;
	char bestMove()const;
	char randomMove()const;

public:
	ComputerP(const int _level = BEST) : level(_level) {}
	void alterMove(char* ch, char input);
	char bestMove();
	
};

#endif 


