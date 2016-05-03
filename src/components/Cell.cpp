#include "CommonIncludes.h"

#include "GameController.h"
#include "Board.h"
#include "Player.h"
#include "Piece.h"
#include "Utils.h"

#include "Cell.h"

Cell::Cell(int x, int y)
    : _x(x), _y(y)
{
  _piece = new Piece;
  *_piece = Piece::BLANK;

  if ( DEBUG ) std::cerr << "New Cell created: " << toString() << std::endl;
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
}

bool
Cell::isBlank()
{
  return Piece::BLANK == piece();
}
