#ifndef __PLAYER_H__
#define __PLAYER_H__

enum class Piece;

class Player
{
  public:
    Player(Piece);
    Piece piece();

  private:
    Piece _piece;
};

#endif // __PLAYER_H__
