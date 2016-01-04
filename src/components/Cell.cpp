#include "CommonIncludes.h"

#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "Piece.h"

#include "Cell.h"

Cell::Cell(Board *parent, int x, int y)
    : QObject(NULL), 
    _parent(parent), _x(x), _y(y)
{
  _piece = new Piece;
  *_piece = Piece::BLANK;
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

void
Cell::onCellSelected()
{
  Player *p = rand() % 2 
      ? Game::instance()->firstPlayer()
      : Game::instance()->secondPlayer();

  setPiece(p->piece());
}
