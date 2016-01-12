#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "CommonIncludes.h"

enum class Piece;
class IStrategy;

class Player
{
  public:
    Player(Piece, IStrategy * strategy = NULL);
    std::string toString();
    void setStrategy(IStrategy *);

    Piece piece();
    void makeMove();

  private:
    Piece _piece;
    IStrategy * _strategy;

    IStrategy * strategy();
};

#endif // __PLAYER_H__
