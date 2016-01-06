#include "IBoardIterator.h"

#include "Board.h"
#include "Cell.h"
#include "BoardRowIterator.h"
#include "BoardColumnIterator.h"

IBoardIterator::IBoardIterator(Board & board, int r, int c)
    : _board(board), _r(r), _c(c)
{
  std::cerr << "New Iterator created " << toString() << std::endl;
}

std::string
IBoardIterator::toString()
{
  std::stringstream ss;
  ss << "[" << this << "] holding ref board: " << board().toString()
      << ", at: (" << r() << ", " << c() << ")";
  return ss.str();
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

BoardRowIterator &
IBoardIterator::rowMajorBegin(Board & board)
{
  BoardRowIterator * clone = new BoardRowIterator(board, 1, 1);
  return *clone;
}

BoardColumnIterator &
IBoardIterator::columnMajorBegin(Board & board)
{
  BoardColumnIterator * clone = new BoardColumnIterator(board, 1, 1);
  return *clone;
}

BoardRowIterator &
IBoardIterator::rowMajorEnd(Board & board)
{
  BoardRowIterator * clone = new BoardRowIterator(board, 4, 1);
  return *clone;
}

BoardColumnIterator &
IBoardIterator::columnMajorEnd(Board & board)
{
  BoardColumnIterator * clone = new BoardColumnIterator(board, 1, 4);
  return *clone;
}

Cell &
IBoardIterator::operator*()
{
  //std::cerr << "dereferencing iterator: " << toString() << std::endl;
  //std::cerr << "board: " << board().toString() << std::endl;
  //std::cerr << "cell: " << board().cell(r(), c()).toString() << std::endl;
  return board().cell(r(), c());
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
