#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "CommonIncludes.h"

enum class Piece;

class Player
{
  public:
    Player(Piece);
    std::string toString();

    Piece piece();

  private:
    Piece _piece;
};

#endif // __PLAYER_H__
