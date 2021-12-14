#include "RandomPlayer.h"

RandomPlayer::RandomPlayer(int type)
{
	this->playerType(type);
}

void RandomPlayer::makeMove(int** board, int sizeOfBoard)
{
	cout << this->playerSymbol << "'s turn to move: " << endl;
	bool validMove = false;
	while (!validMove)
	{
		this->x = 1+ rand() % sizeOfBoard;
		this->y = 1+ rand() % sizeOfBoard;
		if (this->x <= sizeOfBoard && this->y <= sizeOfBoard && this->x > 0 && this->y > 0)
		{
			if (board[this->x - 1][this->y - 1] != this->CROSSER
				&&
				board[this->x - 1][this->y - 1] != this->BLOCKER)
			{
				validMove = true;
			}
		}
	}
}