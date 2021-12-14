#include "Player.h"

void Player::makeMove(int** board, int sizeOfBoard)
{
	cout << this->playerSymbol << "'s turn to move: ";
	bool validMove = false;
	while (!validMove)
	{
		cin >> this->x;
		cin >> this->y;
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
				cout << "already filled, please try again" << endl;
			}
		}
		else 
		{
			cout << "out of range please try again." << endl;
		}
	}
}

