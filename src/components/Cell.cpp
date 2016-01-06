#include "CommonIncludes.h"

#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "Piece.h"

#include "Cell.h"

Cell::Cell(Board * parent, int x, int y)
    : _parent(parent), _x(x), _y(y)
{
  _piece = new Piece;
  *_piece = Piece::BLANK;

  std::cerr << "New Cell created: [" << this << "] (" << _x << ", " << _y << ") -> "
      << (piece() == Piece::CROSS ? "X" : (piece() == Piece::OH ?
        "O" : "BLANK")) << std::endl;
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
