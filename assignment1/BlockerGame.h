#pragma once
#include <iostream>
#include "Board.h"
#include "Player.h"
#include "RandomPlayer.h"
#include "StraightPlayer.h"

using namespace std;
const int CROSSER = 1;
const int BLOCKER = -1;

class BlockerGame
{
protected:
	Player *crosser;
	Player *blocker;
	Board *board;
	int currentPlayer = CROSSER;
	int gameResult = 0;
public:
	int sizeOfBoard = 0;
	int maxMoves = 0;

	BlockerGame() 
	{
		srand((unsigned)time(0));
	}

	~BlockerGame()
	{
		delete board;
		delete crosser;
		delete blocker;
	}
	
	void setup()
	{
		cout << "enter size of board";
		cin >> sizeOfBoard;
		while (sizeOfBoard < 3)
		{
			cout << "board must be bigger 3x3 or bigger." << endl;
			cout << "enter size of board: ";
			cin >> sizeOfBoard;
		}
		this->maxMoves = this->sizeOfBoard * this->sizeOfBoard;
		board = new Board(sizeOfBoard);
	}

	void playerSelection()
	{
		int choice;
		cout << "Please select game type: " << endl
			<< "~ crosser vs blocker ~" << endl
			<< "1. player vs player" << endl
			<< "2. player vs random" << endl
			<< "3. random vs random" << endl
			<< "4. random vs player" << endl
			<< "5. straight vs player" << endl
			<< "6. player vs straight" << endl
			<< "7. straight vs straight" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			this->crosser = new Player(CROSSER);
			this->blocker = new Player(BLOCKER);
			break;
		case 2:
			this->crosser = new Player(CROSSER);
			this->blocker = new RandomPlayer(BLOCKER);
			break;
		case 3:
			this->crosser = new RandomPlayer(CROSSER);
			this->blocker = new RandomPlayer(BLOCKER);
			break;
		case 4:
			this->crosser = new RandomPlayer(CROSSER);
			this->blocker = new Player(BLOCKER);
			break;
		case 5:
			this->crosser = new StraightPlayer(CROSSER, this->sizeOfBoard);
			this->blocker = new Player(BLOCKER);
			break;
		case 6:
			this->crosser = new Player(CROSSER);
			this->blocker = new StraightPlayer(BLOCKER, this->sizeOfBoard);
			break;
		case 7:
			this->crosser = new StraightPlayer(CROSSER, this->sizeOfBoard);
			this->blocker = new StraightPlayer(BLOCKER, this->sizeOfBoard);
		}
	}

	void start()
	{	
		this->board->display();
		this->loop();
	}

	int gameStatus()
	{
		for (int i = 0; i < sizeOfBoard; i++)
		{
			this->findWin(board->board, i, 0);
		}

		if (this->gameResult == 1)
		{
			cout << "crosser wins!";
			return 0;
		}
		int loss = this->checkLoss();
		if (loss == 0)
		{
			cout << "blocker wins!";
			return 0;
		}
		return 1;
	}

	int findWin(int** board, int x, int y, int lastx = 0)
	{
		if (this->gameResult == 1)
		{
			return 1;
		}
		if (board[x][y] == 1)
		{
			int right = 0; int upRight = 0; int downRight = 0;
			int up = 0; int down = 0;

			if (y < sizeOfBoard - 1)
			{
				right = board[x][y + 1];
				if (x - 1 >= 0)
				{
					up = board[x - 1][y];
					upRight = board[x - 1][y + 1];
				}
				if (x + 1 <= sizeOfBoard - 1)
				{
					down = board[x + 1][y];
					downRight = board[x + 1][y + 1];
				}
				if (upRight == 1)
				{
					findWin(board, x - 1, y + 1);
				}
				if (downRight == 1)
				{
					findWin(board, x + 1, y + 1);
				}
				if (right == 1)
				{
					findWin(board, x, y + 1);
				}
				if (up == 1)
				{
					if (lastx != x )
					{
						findWin(board, x - 1, y, x - 1);
					}	
				}
				if (down == 1)
				{
					if (lastx != x)
					{
						findWin(board, x + 1, y, x + 1);
					}
				}
			}
			else {
				this->gameResult = 1;
				return 1;
			}
		}
		return 0;
	}

	int checkLoss()
	{
		int moveCount = 0;
		for (int i = 0; i < this->sizeOfBoard; i++)
		{
			for (int j = 0; j < this->sizeOfBoard; j++)
			{
				if (board->board[i][j] == CROSSER || board->board[i][j] == BLOCKER)
				{
					moveCount++;
				}
			}
		}
		if (moveCount == this->maxMoves)
		{
			return 0;
		}
		else {
			return 1;
		}
	}

	void loop()
	{
		int game = this->gameStatus();
		while (game)
		{
			this->crosser->makeMove(board->board, this->sizeOfBoard);
			this->blocker->makeMove(board->board, this->sizeOfBoard);
			this->crosser->placePiece(board->board);
			this->blocker->placePiece(board->board);
			this->board->display();
			game = this->gameStatus();
		}
	}
};

