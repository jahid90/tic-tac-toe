#ifndef __HUMAN_STRATEGY_H__
#define __HUMAN_STRATEGY_H__

#include "IStrategy.h"

class HumanStrategy : public IStrategy
{
  public:
    Cell * getNextBestMoveFor(Player *, Board *);
    std::string toString();

  private:
};

#endif // __HUMAN_STRATEGY_H__
