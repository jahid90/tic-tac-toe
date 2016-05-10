#ifndef __UNBEATABLESTRATEGY_H__
#define __UNBEATABLESTRATEGY_H__

#include "IStrategy.h"

class Board;
class Cell;

class Config
{
  public:
    Config(Board *, bool);
    int score();
    Cell * bestCell();
    void buildTree();

  private:
    Board * _board;
    Config ** _child;
    int _score;
    bool _maximize;
    Cell * _cell;
};

class UnbeatableStrategy : public IStrategy
{
  public:
    void requestNextBestMoveOn(Board *);
    std::string toString();

  private:
    Cell * minimax(Board *, bool);
};

#endif  // __UNBEATABLESTRATEGY_H__
