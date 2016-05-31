#ifndef __BOARD_ITERATOR_H__
#define __BOARD_ITERATOR_H__

#include "CommonIncludes.h"

class Cell;
class Board;
class BoardRowIterator;

class IBoardIterator
{
  public:
    IBoardIterator(Board *, int, int);
    virtual ~IBoardIterator();
    std::string toString();

    bool operator==(const IBoardIterator &);
    bool operator!=(const IBoardIterator &);
    Cell & operator*();
    virtual IBoardIterator & operator++() = 0;
    virtual IBoardIterator & operator++(int) = 0;

    void reset();

  protected:
    Board * _board;
    int _r;
    int _c;
};

#endif // __BOARD_ITERATOR_H__
