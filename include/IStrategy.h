#ifndef __ISTRATEGY_H__
#define __ISTRATEGY_H__

#include "CommonIncludes.h"

class Cell;
class Board;
class Player;

class IStrategy
{
  public:
    virtual std::string toString() = 0;
    virtual void getNextBestMoveFor(Player *, Board *) = 0;
};

#endif // __ISTRATEGY_H__
