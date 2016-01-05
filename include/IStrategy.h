#ifndef __ISTRATEGY_H__
#define __ISTRATEGY_H__

class Board;
class Player;

/* abstract */ class IStrategy
{
  public:
    Board * getNextBestMoveFor(Player *, Board *);
};

#endif // __ISTRATEGY_H__
