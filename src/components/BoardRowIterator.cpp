#include "BoardRowIterator.h"

BoardRowIterator::BoardRowIterator(Board & board, int r, int c)
    : IBoardIterator(board, r, c)
{
  // std::cerr << "row-iter" << std::endl;
}

BoardRowIterator::BoardRowIterator(BoardRowIterator & other)
    : IBoardIterator(other.board(), other.r(), other.c())
{
  // std::cerr << "row-iter:: copy constructor" << std::endl;
}

IBoardIterator &
BoardRowIterator::operator++()
{
  // std::cerr << "row-iter::pre-incr" << std::endl;
  // std::cerr << "before: " << toString() << std::endl;

  this->_c = 1 + this->c();

  if (this->c() > 3)
  {
    this->_c = 1;
    this->_r = 1 + this->r();
  }

  // std::cerr << "after: " << toString() << std::endl;

  return *this;
}

IBoardIterator &
BoardRowIterator::operator++(int)
{
  // std::cerr << "row-iter::pre-incr" << std::endl;
  // std::cerr << "before: " << toString() << std::endl;
  
  BoardRowIterator * clone = new BoardRowIterator(*this);

  this->_c = 1 + this->c();

  if (this->c() > 3)
  {
    this->_c = 1;
    this->_r = 1 + this->r();
  }

  // std::cerr << "after: " << toString() << std::endl;

  return *clone;
}
