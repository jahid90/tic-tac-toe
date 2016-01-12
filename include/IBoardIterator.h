#ifndef __BOARD_ITERATOR_H__
#define __BOARD_ITERATOR_H__

#include "CommonIncludes.h"

class Cell;
class Board;
class BoardRowIterator;
class BoardColumnIterator;

class IBoardIterator
{
  public:
    IBoardIterator(Board &, int, int);
    virtual ~IBoardIterator() {};
    std::string toString();

    int r();
    int c();
    Board & board();

    Cell & operator*();
    virtual IBoardIterator & operator++() = 0;
    virtual IBoardIterator & operator++(int) = 0;

    static BoardRowIterator & rowMajorBegin(Board &);
    static BoardColumnIterator & columnMajorBegin(Board &);
    static BoardRowIterator & rowMajorEnd(Board &);
    static BoardColumnIterator & columnMajorEnd(Board &);

    void reset();

    enum class Type { ROW, COL };

  protected:
    Board & _board;
    int _r;
    int _c;
};

bool operator==(IBoardIterator & lhs, IBoardIterator & rhs);
bool operator!=(IBoardIterator & lhs, IBoardIterator & rhs);

#endif // __BOARD_ITERATOR_H__
