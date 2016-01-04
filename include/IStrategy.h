#ifndef __ISTARATEGY_H__
#define __ISTARATEGY_H__

class Board;
class Player;

/* abstract */ class IStrategy
{
  public:
    Board * getNextBestMove(Player *forPlayer, Board *currentState);
};

#endif // __ISTARATEGY_H__
