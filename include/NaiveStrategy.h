#ifndef __NAIVE_STRATEGY_H__
#define __NAIVE_STRATEGY_H__

#include "IStrategy.h"

class NaiveStrategy : public IStrategy
{
  public:
    Cell * getNextBestMoveFor(Player *, Board *);
    std::string toString();
};

#endif // __NAIVE_STRATEGY_H__
