#include "Player.h"

#include "Piece.h"
#include "Utils.h"

Player::Player(Piece piece)
    : _piece(piece)
{
  std::cerr << "New Player created: " << toString() << std::endl;
}

std::string
Player::toString()
{
  std::stringstream ss;
  ss << "[" << this << "] holding piece: " << pieceToString(piece());
  return ss.str();
}

Piece
Player::piece()
{
  return _piece;
}
