#include <iostream>
#include "Board.h"

using namespace std;


void Board::initBoard()
{
    for (int i = 0; i < GameConfig::GAME_HEIGHT; i++) {
        for (int j = 0; j < GameConfig::GAME_WIDTH; j++) {
            board[i][j] = ' '; // EMPTY
        }
    }
}

bool Board::isRowFull(int row) 
{
    for (int col = 0; col < GameConfig::GAME_WIDTH; col++) 
    {
        if (board[row][col] == ' ') 
        {  
            return false;
        }
    }
    return true;
}

void Board::shiftRowsDown(int startRow) 
{
    for (int row = startRow; row > 0; row--)
    {
        for (int col = 0; col < GameConfig::GAME_WIDTH; col++) 
        {
            board[row][col] = board[row - 1][col]; 
        }
    }

    // Clear the top row
    for (int col = 0; col < GameConfig::GAME_WIDTH; col++)
    {
        board[0][col] = ' ';  
    }
    clrscr();
}

void Board::clearRows(const Piece& piece) 
{
    for (int i = 0; i < GameConfig::PIECE_SIZE; i++) 
    {
        int row = piece.tetrimino[i].getY();
        if (isRowFull(row))
        {
            shiftRowsDown(row);
           // i = -1; // Restart loop to check for multiple full rows
        }
    }
}


void Board::printBoard(const int min)          
{
    for (int i = 0; i < GameConfig::GAME_HEIGHT; ++i) 
    {
        for (int j = 0; j < GameConfig::GAME_WIDTH; ++j)
        {
            if (board[i][j] == '*')
            {
                gotoxy(j + min + GameConfig::PIECE_X, i);
                cout << '*';
            }
        }
    }
}

void Board::insertPiece(Piece piece)   // This function is called after we know it hit (checkHit()), thus it is a simple one
{
    for (int i = 0; i < GameConfig::PIECE_SIZE; i++)
    {
        board[piece.tetrimino[i].getY()][piece.tetrimino[i].getX()] = '*';
    }
}

