#include "BoardRowIterator.h"

BoardRowIterator::BoardRowIterator(Board * board, int r, int c)
    : IBoardIterator(board, r, c)
{
}

BoardRowIterator::BoardRowIterator(BoardRowIterator * other)
    : IBoardIterator(other->board(), other->r(), other->c())
{
}

IBoardIterator *
BoardRowIterator::operator++()
{
  this->_c = 1 + this->c();

  if (this->c() > 2)
  {
    this->_c = 0;
    this->_r = 1 + this->r();
  }

  return this;
}

IBoardIterator *
BoardRowIterator::operator++(int)
{
  IBoardIterator * clone = new BoardRowIterator(this);

  this->_c = 1 + this->c();

  if (this->c() > 2)
  {
    this->_c = 0;
    this->_r = 1 + this->r();
  }

  return clone;
}
