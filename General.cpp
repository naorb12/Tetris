#include "General.h"

// Used for printing the game
void gotoxy(const int x,const int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);

	// Hide cursor
	CONSOLE_CURSOR_INFO ConCurInf;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = DOWN;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hConsoleOutput, &ConCurInf);

}

// Clears the screen
void clrscr()
{
	system("cls");
}
