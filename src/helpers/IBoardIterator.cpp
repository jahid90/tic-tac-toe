#include "IBoardIterator.h"

#include "Board.h"
#include "BoardRowIterator.h"
#include "Cell.h"
#include "Utils.h"

IBoardIterator::IBoardIterator(Board * board, int r, int c)
    : _board(board), _r(r), _c(c)
{
  if ( DEBUG )
    std::cerr << "New Iterator created " << toString() << std::endl;
}

IBoardIterator::~IBoardIterator()
{
  _board = NULL;
}

std::string
IBoardIterator::toString()
{
  std::stringstream ss;
  ss << "[" << this << "] holding ref board: " << _board->toString()
      << ", at: (" << _r << ", " << _c << ")";
  return ss.str();
}

Cell &
IBoardIterator::operator*()
{
  return *(_board->cell(_r, _c));
}

bool
IBoardIterator::operator==(const IBoardIterator & other)
{
  return _board == other._board
      && _r == other._r
      && _c == other._c;
}

bool
IBoardIterator::operator!=(const IBoardIterator & other)
{
  return !( *this == other );
}

void
IBoardIterator::reset()
{
  this->_r = 1;
  this->_c = 1;
}
