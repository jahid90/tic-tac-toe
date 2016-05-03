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
    bool operator==(const IBoardIterator &);
    bool operator!=(const IBoardIterator &);

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

#endif // __BOARD_ITERATOR_H__
