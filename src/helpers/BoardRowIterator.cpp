#include "BoardRowIterator.h"

BoardRowIterator::BoardRowIterator(Board * board, int r, int c)
    : IBoardIterator(board, r, c)
{
}

BoardRowIterator::BoardRowIterator(BoardRowIterator & other)
    : IBoardIterator(other._board, other._r, other._c)
{
}

IBoardIterator &
BoardRowIterator::operator++()
{
  _c = 1 + _c;

  if (_c > 3)
  {
    _c = 1;
    _r = 1 + _r;
  }

  return *this;
}

IBoardIterator &
BoardRowIterator::operator++(int)
{
  BoardRowIterator * clone = new BoardRowIterator(*this);

  _c = 1 + _c;

  if (_c > 3)
  {
    _c = 1;
    _r = 1 + _r;
  }

  return *clone;
}
