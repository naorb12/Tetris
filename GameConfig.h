#ifndef _GameConfig
#define _GameConfig

class GameConfig
{
public:

	static constexpr int GAME_WIDTH = 12;
	static constexpr int GAME_HEIGHT = 18;
	static constexpr int PIECE_SIZE = 4;
	static constexpr int NUMBER_OF_PIECE_TYPE = 7;
	static constexpr int BOTTOM = 22;

	static constexpr int P2_X = 24;
	static constexpr int PIECE_X = 1;

	static const int COLORS[];
	static const int NUM_OF_COLORS;
};
#endif
