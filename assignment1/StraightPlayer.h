#pragma once
#include "Player.h"
class StraightPlayer :
    public Player
{
public:
    StraightPlayer(int type, int sizeOfBoard);
    virtual void makeMove(int** board, int sizeOfBoard);
    virtual void jump(int type);
    virtual void newLine(int type);
};

