#pragma once
#include <iostream>
#include <string>
using namespace std;

class Player
{
protected:
	string playerSymbol = "";
	const int CROSSER = 1;
	const int BLOCKER = -1;
	const string CROSSER_SYMBOL = "C";
	const string BLOCKER_SYMBOL = "B";
	int type = NULL;
	int x = 1;
	int y = 1;

public:

	Player(){}
	~Player(){}

	Player(int type)
	{
		playerType(type);
	}

	void playerType(int type)
	{
		switch (type)
		{
		case 1:
			this->playerSymbol = this->CROSSER_SYMBOL;
			this->type = this->CROSSER;
			break;
		case -1:
			this->playerSymbol = this->BLOCKER_SYMBOL;
			this->type = this->BLOCKER;
			break;
		}
	}

	virtual void makeMove(int** board, int sizeOfBoard);

	void placePiece(int** board)
	{
		board[this->x - 1][this->y - 1] = this->type;
	}

	string Symbol()
	{
		return this->playerSymbol;
	}
};

