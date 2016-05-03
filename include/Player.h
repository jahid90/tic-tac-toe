#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "CommonIncludes.h"

enum class Piece;
class IStrategy;
class Cell;
class GameController;

class Player
{
  public:
    Player(GameController * controller, std::string, Piece, IStrategy * strategy = NULL);
    std::string toString();
    std::string name();

    Piece piece();
    void setStrategy(IStrategy *);
    Cell * move();

  private:
    GameController * _controller;
    std::string _name;
    Piece _piece;
    IStrategy * _strategy;
};

#endif // __PLAYER_H__
