#include <iostream>
#include "Board.h"

// This function initialize the board to empty cells
void Board::initBoard()
{
    for (int i = 0; i < GameConfig::GAME_HEIGHT; i++) {
        for (int j = 0; j < GameConfig::GAME_WIDTH; j++) {
            board[i][j] = GameConfig::EMPTY_CELL;
        }
    }
}

// This function checks if a row is full in a board
bool Board::isRowFull(const int row) const 
{
    for (int col = 0; col < GameConfig::GAME_WIDTH; col++) 
    {
        if (board[row][col] == GameConfig::EMPTY_CELL)
        {  
            return false;
        }
    }
    return true;
}

// This function shifts rows down 
void Board::shiftRowsDown(const int startRow) 
{
    for (int row = startRow; row > 0; row--)
    {
        for (int col = 0; col < GameConfig::GAME_WIDTH; col++) 
        {
            board[row][col] = board[row - 1][col]; 
        }
    }

  
    for (int col = 0; col < GameConfig::GAME_WIDTH; col++)
    {
        board[0][col] = GameConfig::EMPTY_CELL;
    }
    clrscr();
}

// This function checks if rows are full in a board, and deletes them 
void Board::clearRows(const Piece& piece) 
{
    for (int i = 0; i < GameConfig::PIECE_SIZE; i++) 
    {
        int row = piece.tetrimino[i].getY();
        if (isRowFull(row))
        {
            shiftRowsDown(row);
            i = -1;
        }
    }
}

// This function prints the board and its pieces
void Board::printBoard(const int min) const          
{
    for (int i = 0; i < GameConfig::GAME_HEIGHT; ++i) 
    {
        for (int j = 0; j < GameConfig::GAME_WIDTH; ++j)
        {
            if (board[i][j] == GameConfig::FILLED_CELL)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
                gotoxy(j + min + GameConfig::PIECE_X, i);
                cout << GameConfig::FILLED_CELL;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
    }
}

// This function inserts a piece into the board
void Board::insertPiece(const Piece& piece)   
{
    for (int i = 0; i < GameConfig::PIECE_SIZE; i++)
    {
        board[piece.tetrimino[i].getY()][piece.tetrimino[i].getX()] = GameConfig::FILLED_CELL;
    }
}

