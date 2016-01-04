#include "Piece.h"

#include "Player.h"

Player::Player(Piece piece)
    : _piece(piece)
{
}

Piece
Player::piece()
{
  return _piece;
}
