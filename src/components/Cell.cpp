#include "Cell.h"

#include "Board.h"
#include "GameController.h"
#include "Player.h"
#include "Utils.h"

Cell::Cell(int x, int y, Piece piece)
    : _x(x), _y(y), _piece(piece)
{
  if ( DEBUG )
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
  return _piece;
}

void
Cell::setPiece(Piece piece)
{
  _piece = piece;
}

bool
Cell::isBlank()
{
  return Piece::BLANK == _piece;
}
