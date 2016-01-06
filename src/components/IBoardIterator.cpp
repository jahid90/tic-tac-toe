#include "IBoardIterator.h"

#include "CommonIncludes.h"

#include "Board.h"
#include "Cell.h"
#include "BoardRowIterator.h"
#include "BoardColumnIterator.h"

IBoardIterator::IBoardIterator(Board & board, int r, int c)
    : _board(board), _r(r), _c(c)
{
  std::cerr << "New Iterrator created [" << this
    << "] for: " << &_board 
    << " at pos: (" << _r << ", " << _c << ")" << std::endl;
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

Board &
IBoardIterator::board()
{
  return _board;
}

#ifdef O
IBoardIterator
IBoardIterator::rowMajorBegin(Board & board)
{
  BoardRowIterator itr(board, 0, 0);
  return (IBoardIterator) itr;
}

IBoardIterator &
IBoardIterator::columnMajorBegin(Board * board)
{
  BoardColumnIterator itr(board, 0, 0);
  return (IBoardIterator) itr;
}

IBoardIterator &
IBoardIterator::rowMajorEnd(Board * board)
{
  BoardRowIterator itr(board, 3, 0);
  return (IBoardIterator) itr;
}

IBoardIterator &
IBoardIterator::columnMajorEnd(Board * board)
{
  BoardColumnIterator itr(board, 0, 3);
  return (IBoardIterator) itr;
}

bool
IBoardIterator::operator==(IBoardIterator * other)
{
  std::cerr << "equality check on itr" << std::endl;

  return this->board() == other->board()
      && this->r() == other->r()
      && this->c() == other->c();
}

bool
IBoardIterator::operator!=(IBoardIterator * other)
{
  return !( this == other);
}
#endif

Cell &
IBoardIterator::operator*()
{
  return this->board().cell(this->r(), this->c());
}

bool operator==(IBoardIterator & lhs, IBoardIterator & rhs)
{
  return &lhs.board() == &rhs.board()
      && lhs.r() == rhs.r()
      && lhs.c() == rhs.c();
}

bool operator!=(IBoardIterator & lhs, IBoardIterator & rhs)
{
  return !( lhs == rhs );
}
