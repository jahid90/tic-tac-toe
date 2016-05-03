#include "BoardColumnIterator.h"

BoardColumnIterator::BoardColumnIterator(Board & board, int r, int c)
    : IBoardIterator(board, r, c)
{
}

BoardColumnIterator::BoardColumnIterator(BoardColumnIterator & other)
    : IBoardIterator(other._board, other._r, other._c)
{
}

IBoardIterator &
BoardColumnIterator::operator++()
{
  _r = 1 + _r;

  if (_r > 3)
  {
    _r = 1;
    _c = 1 + _c;
  }

  return *this;
}

IBoardIterator &
BoardColumnIterator::operator++(int)
{
  BoardColumnIterator * clone = new BoardColumnIterator(*this);

  _r = 1 + _r;

  if (_r > 3)
  {
    _r = 1;
    _c = 1 + _c;
  }

  return *clone;
}
