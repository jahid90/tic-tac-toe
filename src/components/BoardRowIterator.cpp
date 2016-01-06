#ifdef O
#include "CommonIncludes.h"

#include "BoardRowIterator.h"

BoardRowIterator::BoardRowIterator(Board * board, int r, int c)
    : IBoardIterator(board, r, c)
{
  std::cerr << "row iter created at: " << r << ", " << c << std::endl;
}

BoardRowIterator::BoardRowIterator(BoardRowIterator & other)
    : IBoardIterator(other.board(), other.r(), other.c())
{
}

IBoardIterator &
BoardRowIterator::operator++()
{
  std::cerr << "r: " << this->r() << ", c: " << this->c() << std::endl;

  this->_c = 1 + this->c();

  if (this->c() > 2)
  {
    this->_c = 0;
    this->_r = 1 + this->r();
  }

  std::cerr << "new r: " << this->r() << ", new c: " << this->c() << std::endl;

  return *this;
}

IBoardIterator &
BoardRowIterator::operator++(int)
{
  BoardRowIterator * clone = new BoardRowIterator(*this);

  this->_c = 1 + this->c();

  if (this->c() > 2)
  {
    this->_c = 0;
    this->_r = 1 + this->r();
  }

  return *clone;
}
#endif
