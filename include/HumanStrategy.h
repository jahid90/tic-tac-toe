#ifndef __HUMAN_STRATEGY_H__
#define __HUMAN_STRATEGY_H__

#include "IStrategy.h"

class HumanStrategy : public IStrategy
{
  public:
    void requestNextBestMoveOn(Board *);
    std::string toString();
};

#endif // __HUMAN_STRATEGY_H__
