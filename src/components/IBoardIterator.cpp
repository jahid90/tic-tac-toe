#include "IBoardIterator.h"

#include "Board.h"
#include "Cell.h"
#include "BoardRowIterator.h"
#include "BoardColumnIterator.h"

IBoardIterator::IBoardIterator(Board * board, int r, int c)
    : _board(board), _r(r), _c(c)
{
}

IBoardIterator::~IBoardIterator()
{
  delete _board;
}

int
IBoardIterator::r()
{
  return _r;
}

int
IBoardIterator::c()
{
  return _c;
}

Board *
IBoardIterator::board()
{
  return _board;
}

IBoardIterator *
IBoardIterator::rowMajorBegin(Board * board)
{
  return new BoardRowIterator(board, 0, 0);
}

IBoardIterator *
IBoardIterator::columnMajorBegin(Board * board)
{
  return new BoardColumnIterator(board, 0, 0);
}

IBoardIterator *
IBoardIterator::rowMajorEnd(Board * board)
{
  return new BoardRowIterator(board, 3, 0);
}

IBoardIterator *
IBoardIterator::columnMajorEnd(Board * board)
{
  return new BoardColumnIterator(board, 0, 3);
}

bool
IBoardIterator::operator==(IBoardIterator * other)
{
  return this->board() == other->board()
      && this->r() == other->r()
      && this->c() == other->c();
}

bool
IBoardIterator::operator!=(IBoardIterator * other)
{
  return !( this == other);
}

Cell *
IBoardIterator::operator*()
{
  return this->board()->cell(this->r(), this->c());
}
