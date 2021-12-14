#pragma once
#include "Player.h"
class RandomPlayer : public Player
{
public:
    RandomPlayer(int type);
    virtual void makeMove(int** board, int sizeOfBoard);
};

