#include "StraightPlayer.h"

StraightPlayer::StraightPlayer(int type, int sizeOfBoard)
{
	this->playerType(type);
	if (this->type == CROSSER)
	{
		this->x = 1;
		this->y = 0;
	}
	if (this->type == BLOCKER)
	{
		this->x = 0;
		this->y = sizeOfBoard;
	}
}

void StraightPlayer::makeMove(int** board, int sizeOfBoard)
{
	cout << this->playerSymbol << "'s turn to move: " << endl;
	if (this->type == CROSSER)
	{
		if (this->y == sizeOfBoard)
		{
			this->x += 1;
			this->y = 0;
		}
		this->y += 1;
	}
	else if(this->type == BLOCKER)
	{
		if (this->x == sizeOfBoard)
		{
			this->x = 0;
			this->y -= 1;
		}
		this->x += 1;
	}

	bool validMove = false;
	while (validMove == false)
	{
		if (this->x > sizeOfBoard || this->y > sizeOfBoard)
		{
			this->newLine(this->type);
		}

		if (this->x <= sizeOfBoard && this->y <= sizeOfBoard && this->x > 0 && this->y > 0)
		{
			if (board[this->x - 1][this->y - 1] != this->CROSSER
				&&
				board[this->x - 1][this->y - 1] != this->BLOCKER)
			{
				validMove = true;
			}
			else
			{
				this->jump(this->type);
			}
		}
	}
}

void StraightPlayer::jump(int type)
{
	if (type == CROSSER)
	{
		this->y += 1;
	}
	if (type == BLOCKER)
	{
		this->x += 1;
	}
}

void StraightPlayer::newLine(int type)
{
	if (type == CROSSER)
	{
		this->y = 1;
		this->x += 1;
	}
	if (type == BLOCKER)
	{
		this->x = 0;
		this->y -= 1;
	}
}


