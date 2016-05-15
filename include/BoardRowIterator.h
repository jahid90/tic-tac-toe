#ifndef __BOARD_ROW_ITERATOR_H__
#define __BOARD_ROW_ITERATOR_H__

#include "IBoardIterator.h"

class BoardRowIterator : public IBoardIterator
{
  public:
    BoardRowIterator(Board *, int, int);

    IBoardIterator & operator++();
    IBoardIterator & operator++(int);

  private:
    BoardRowIterator(BoardRowIterator &);
};

#endif // __BOARD_ROW_ITERATOR_H__
