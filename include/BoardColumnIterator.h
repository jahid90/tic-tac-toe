#ifndef __BOARD_COLUMN_ITERATOR_H__
#define __BOARD_COLUMN_ITERATOR_H__

#include "IBoardIterator.h"

class BoardColumnIterator : public IBoardIterator
{
  public:
    BoardColumnIterator(Board &, int, int);

    IBoardIterator & operator++();
    IBoardIterator & operator++(int);

  private:
    BoardColumnIterator(BoardColumnIterator &);
};

#endif // __BOARD_COLUMN_ITERATOR_H__
