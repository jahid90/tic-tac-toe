#include "BoardColumnIterator.h"

BoardColumnIterator::BoardColumnIterator(Board & board, int r, int c)
    : IBoardIterator(board, r, c)
{
  //std::cerr << "column-iter" << std::endl;
}

BoardColumnIterator::BoardColumnIterator(BoardColumnIterator & other)
    : IBoardIterator(other.board(), other.r(), other.c())
{
  //std::cerr << "column-iter:: copy constructor" << std::endl;
}

IBoardIterator &
BoardColumnIterator::operator++()
{
  //std::cerr << "col-iter::pre-incr" << std::endl;
  //std::cerr << "before: " << toString() << std::endl;

  this->_r = 1 + this->r();

  if (this->r() > 3)
  {
    this->_r = 1;
    this->_c = 1 + this->c();
  }

  //std::cerr << "after: " << toString() << std::endl;

  return *this;
}

IBoardIterator &
BoardColumnIterator::operator++(int)
{
  //std::cerr << "col-iter::post-incr" << std::endl;
  //std::cerr << "before: " << toString() << std::endl;
  
  BoardColumnIterator * clone = new BoardColumnIterator(*this);

  this->_r = 1 + this->r();

  if (this->r() > 3)
  {
    this->_r = 1;
    this->_c = 1 + this->c();
  }

  //std::cerr << "after: " << toString() << std::endl;

  return *clone;
}
