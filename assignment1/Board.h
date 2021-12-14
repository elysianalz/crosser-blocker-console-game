#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Player.h"
using namespace std;

class Board
{
private:
	
	const int CROSSER = 1;
	const int BLOCKER = -1;
	const string CROSSER_SYMBOL = "C";
	const string BLOCKER_SYMBOL = "B";
	
public:
	int DECLARED_SIZE = 0;
	int** board = 0;
	
	Board(){}

	Board(int size)
	{
		this->DECLARED_SIZE = size;
		makeBoard();
	}

	~Board()
	{
		this->deleteBoard();
	}

	void makeBoard()
	{
		board = new int* [DECLARED_SIZE];
		for (int i = 0; i < DECLARED_SIZE; i++)
		{
			board[i] = new int[DECLARED_SIZE];
		}
	}

	void deleteBoard()
	{
		for (int i = 0; i < DECLARED_SIZE - 1; i++)
		{
			delete[] board[i];
		}
		delete[] board;
	}

	void display()
	{

		stringstream y;
		y << "     " << setw(2);
		for (int i = 1; i <= this->DECLARED_SIZE; i++)
		{
			y << i << " " << setw(3);
		}
		y << endl;
		string yRow = y.str();
		cout << yRow;

		for (int i = 0; i < this->DECLARED_SIZE; i++)
		{
			cout << setw(3) << i + 1 << " | ";
			for (int j = 0; j < this->DECLARED_SIZE; j++)
			{
				this->fillBoard(i, j);
			}
			cout << endl;
		}
	}

	void fillBoard(int x, int y)
	{
		int pos = board[x][y];
		if (pos == this->CROSSER)
		{
			cout << this->CROSSER_SYMBOL << " | ";
		}
		else if (pos == this->BLOCKER)
		{
			cout << this->BLOCKER_SYMBOL << " | ";
		}
		else {
			cout << " " << " | ";
		}
	}
};

