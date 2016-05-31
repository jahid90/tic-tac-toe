#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "CommonIncludes.h"

enum class Piece;
class IStrategy;
class Cell;

class Player
{
  public:
    Player(std::string, Piece, IStrategy * strategy = NULL);
    ~Player();
    std::string toString();

    std::string name();
    Piece piece();
    void setStrategy(IStrategy *);
    void move();

  private:
    std::string _name;
    Piece _piece;
    IStrategy * _strategy;
};

#endif // __PLAYER_H__
