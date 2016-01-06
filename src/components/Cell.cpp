#include "CommonIncludes.h"

#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "Piece.h"
#include "Utils.h"

#include "Cell.h"

Cell::Cell(Board * parent, int x, int y)
    : _parent(parent), _x(x), _y(y)
{
  _piece = new Piece;
  *_piece = Piece::BLANK;

  std::cerr << "New Cell created: " << toString() << std::endl;
}

std::string
Cell::toString()
{
  std::stringstream ss;
  ss << "[" << this << "] (" 
      << x() << ", " << y()
      << ") -> " << pieceToString(piece());

  return ss.str();
}

int
Cell::x()
{
  return _x;
}

int
Cell::y()
{
  return _y;
}

Piece
Cell::piece()
{
  return *_piece;
}

void
Cell::setPiece(Piece piece)
{
  *_piece = piece;
  _parent->onStateChanged(this->x(), this->y());
}

bool
Cell::isBlank()
{
  return Piece::BLANK == piece();
}
