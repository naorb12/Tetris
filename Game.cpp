#include "Game.h"


// main game function:
void Game::run()   
{
	srand(time(NULL));
	int sign = 0;
	bool gameFinished = true;
	while (sign != 9)
	{

		sign = printMenu(gameFinished);   
		switch (sign)
		{
		case 1:
			startNewGame();
			gameFinished = process();
			break;
		case 2:
			gameFinished = process();
			break;
		case 8:
			printInstructions();		
		case 9:
			break;
		default:
				break;
		}
	}
	clrscr();
	
	
}

bool Game::process()
{
	char ch1, ch2;
	ch1 = ch2 = '\0';
	while (winner == false && ch1 != 27 && ch2 != 27)   // game loop
	{
		p1.isPieceHit = checkHit(p1); 
		p2.isPieceHit = checkHit(p2);
		// check if piece hit & build new piece
		if (p1.isPieceHit == true)
		{
			for (int i = 0; i < GameConfig::PIECE_SIZE; i++)
			{
				//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
				gotoxy(p1.currPiece.tetrimino[i].getX() + GameConfig::PIECE_X, p1.currPiece.tetrimino[i].getY());
				cout << "*";
			}
			p1.board.insertPiece(p1.currPiece);
			p1.board.clearRows(p1.currPiece);
			p1.currPiece.buildpiece();
		}
		if (p2.isPieceHit == true)
		{
			for (int i = 0; i < GameConfig::PIECE_SIZE; i++)
			{
				//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
				gotoxy(p2.currPiece.tetrimino[i].getX() + GameConfig::P2_X + GameConfig::PIECE_X, p2.currPiece.tetrimino[i].getY());
				cout << "*";
			}
			p2.board.insertPiece(p2.currPiece);
			p2.board.clearRows(p2.currPiece);
			p2.currPiece.buildpiece();
		}
		
		movePieces(&ch1, &ch2);
		
		winner = checkWinner();

	}

	return winner;
}

void Game::drawBorders()
{
	int row, col;
	//Board1
	for (col = 0; col <= GameConfig::GAME_WIDTH; col++)
	{
		gotoxy(col, GameConfig::GAME_HEIGHT);
		cout << "-";
	}
	for (row = 0; row <= GameConfig::GAME_HEIGHT; row++)
	{
		gotoxy(0, row);
		cout << "|";

		gotoxy(GameConfig::GAME_WIDTH + 1, row);
		cout << "|";
	}

	//Board2
	for (col = GameConfig::P2_X; col <= GameConfig::GAME_WIDTH + GameConfig::P2_X; col++)
	{
		gotoxy(col, GameConfig::GAME_HEIGHT);
		cout << "-";
	}
	for (row = 0; row <= GameConfig::GAME_HEIGHT; row++)
	{
		gotoxy(GameConfig::P2_X, row);
		cout << "|";

		gotoxy(GameConfig::GAME_WIDTH + GameConfig::P2_X + 1, row);
		cout << "|";
	}

	gotoxy(0, row + 2);
}

bool Game::checkHit(Player player)
{
	for (int i = 0; i < GameConfig::PIECE_SIZE; i++)
	{
		if (player.currPiece.tetrimino[i].getY() == GameConfig::GAME_HEIGHT - 1)
			return true;

		if (player.board.board[player.currPiece.tetrimino[i].getY()+1][player.currPiece.tetrimino[i].getX()] == '*')
			return true;
	}
	
	return false;
}

bool Game::checkWinner()
{
	char ch;
	bool p1Win, p2Win;
	p1Win = p2Win = false;
	for (int i = 0; i < GameConfig::PIECE_SIZE; i++)
	{
		if (p1.board.board[p1.currPiece.tetrimino[i].getY() + 1][p1.currPiece.tetrimino[i].getX()] == '*' && p1.currPiece.tetrimino[i].getY() <= 1)
			p2Win = true;
		if (p2.board.board[p2.currPiece.tetrimino[i].getY() + 1][p2.currPiece.tetrimino[i].getX()] == '*' && p2.currPiece.tetrimino[i].getY() <= 1)
			p1Win = true;
	}

	if (p1Win == true)
	{
		clrscr();
		if (p2Win == true)
		{
			cout << "The result is a tie!";
		}
		else
			cout<< "Player 1 won!";
		cout << "\n\nPress any key to continue...";
		ch = _getch();
		clrscr();
		return true;
	}
	else if (p2Win == true)
	{
		clrscr();
		cout << "Player 2 won!";
		cout << "\n\nPress any key to continue...";
		ch = _getch();
		clrscr();
		return true;
	}
	return false;
}

void Game::startNewGame()
{

	clrscr();
	p1.setBoard();		
	p2.setBoard();

	winner = false;
	p1.isPieceHit = p2.isPieceHit = true;

	p1.currPiece.buildpiece();
	p2.currPiece.buildpiece();

	drawBorders(); 
}

int Game::printMenu(bool gameFinished)
{
	clrscr();

	cout << "(1) Start a new game" << endl;
	if (gameFinished == false)
		cout << "(2) Continue a paused game" << endl;
	cout << "(8) Present instructions and keys" << endl;
	cout << "(9) EXIT" << endl;

	int select = 0;
	while (select == 0)
	{
		select = _getch() - '0';
		switch (select)
		{
		case 1:
			break;
		case 2:
			if (gameFinished == true)
				select = 0;
			else
				break;
		case 8:
			break;
		case 9:
			break;

		default:
			select = 0;
			break;
		}
	}
	clrscr();
	drawBorders();
	p1.board.printBoard(0);
	p2.board.printBoard(GameConfig::P2_X);
	return select;
}

void Game::movePieces(char *ch1, char* ch2)
{
	*ch1 = *ch2 = '\0';
	drawBorders();
	p1.board.printBoard(0);
	p2.board.printBoard(GameConfig::P2_X);

	//print 
	for (int i = 0; i < GameConfig::PIECE_SIZE; i++)
	{
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
		gotoxy(p1.currPiece.tetrimino[i].getX() + GameConfig::PIECE_X, p1.currPiece.tetrimino[i].getY());
		cout << "*";
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
		gotoxy(p2.currPiece.tetrimino[i].getX() + GameConfig::P2_X + GameConfig::PIECE_X, p2.currPiece.tetrimino[i].getY());
		cout << "*";
		gotoxy(40, 20);
	}
	
	getMove(ch1, ch2);
	for (int i = 0; i < GameConfig::PIECE_SIZE; i++)
	{
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_GREEN);
		gotoxy(p1.currPiece.tetrimino[i].getX() + GameConfig::PIECE_X, p1.currPiece.tetrimino[i].getY());
		cout << " ";
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_GREEN);
		gotoxy(p2.currPiece.tetrimino[i].getX() + GameConfig::P2_X + GameConfig::PIECE_X, p2.currPiece.tetrimino[i].getY());
		cout << " ";
	}
	performMove(ch1, ch2);

}

void Game::getMove(char* ch1, char* ch2)
{
	Sleep(400);

	while (_kbhit())
	{
		char ch = _getch(); 

		if (!*ch1 && (ch == 'a' || ch == 'A' || ch == 'd' || ch == 'D' || ch == 's' || ch == 'S' || ch == 'w' || ch == 'W' || ch == 'x' || ch == 'X' || ch == 27))
		{
			*ch1 = ch;
		}
		else if (!*ch2 && (ch == 'j' || ch == 'J' || ch == 'l' || ch == 'L' || ch == 'k' || ch == 'K' || ch == 'i' || ch == 'I' || ch == 'm' || ch == 'M' || ch == 27))
		{
			*ch2 = ch;
		}
	}

}

void Game::performMove(char* ch1, char* ch2)
{
	
	switch (*ch1)
	{
	case 'a': case 'A':
		p1.currPiece.moveleft(p1.board);
		break;
	case 'd': case 'D':
		p1.currPiece.moveRight(p1.board);
		break;
	case 's': case 'S':
		p1.currPiece.rotateClockwise(p1.board);
		break;
	case 'w': case 'W':
		p1.currPiece.rotateCounterClockwise(p1.board);
		break;
	case 'x': case 'X':
		drop(p1);
		break;
	default:
		break;
	}

	switch (*ch2)
	{
	case 'j': case 'J':
		p2.currPiece.moveleft(p2.board);
		break;
	case 'l': case 'L':
		p2.currPiece.moveRight(p2.board);
		break;
	case 'k': case 'K':
		p2.currPiece.rotateClockwise(p2.board);
		break;
	case 'i': case 'I':
		p2.currPiece.rotateCounterClockwise(p2.board);
		break;
	case 'm': case'M':
		drop(p2);
		break;
	default:
		break;
	}

	// move down row
	for (int i = 0; i < GameConfig::PIECE_SIZE; i++)
	{
		if(*ch1 != 'x' && *ch1 != 'X')
			p1.currPiece.tetrimino[i].addToY(1);
		if (*ch2 != 'm' && *ch2 != 'M')
			p2.currPiece.tetrimino[i].addToY(1);
	}

	if (*ch1 != 27)
		*ch1 = '\0';
	if (*ch2 != 27)
		*ch2 = '\0';

}

void Game::drop(Player &p)
{
	while (checkHit(p) == false)
	{
		for (int i = 0; i < GameConfig::PIECE_SIZE; i++)
		{
			p.currPiece.tetrimino[i].addToY(1);
		}
	}
	p.isPieceHit = true;
}

void Game::printInstructions()
{
	clrscr();
	cout << R"(
Keys:

			Left Player            Right Player
LEFT                     a or A                 j or J
RIGHT                    d or D                 l or L
ROTATE clockwise         s or S                 k or K
ROTATE counterclockwise  w or W                 i or I (uppercase i)
DROP                     x or X                 m or M
)" << std::endl;
	cout << "\n\nPress any key to go back to menu";
	char ch = _getch();
	
	
}

