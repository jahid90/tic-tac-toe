#ifdef O
#include "BoardColumnIterator.h"

BoardColumnIterator::BoardColumnIterator(Board * board, int r, int c)
    : IBoardIterator(board, r, c)
{
}

BoardColumnIterator::BoardColumnIterator(BoardColumnIterator & other)
    : IBoardIterator(other.board(), other.r(), other.c())
{
}

IBoardIterator &
BoardColumnIterator::operator++()
{
  this->_r = 1 + this->r();

  if (this->r() > 2)
  {
    this->_r = 0;
    this->_c = 1 + this->c();
  }

  return *this;
}

IBoardIterator &
BoardColumnIterator::operator++(int)
{
  BoardColumnIterator * clone = new BoardColumnIterator(*this);

  this->_r = 1 + this->r();

  if (this->r() > 2)
  {
    this->_r = 0;
    this->_c = 1 + this->c();
  }

  return *clone;
}
#endif
