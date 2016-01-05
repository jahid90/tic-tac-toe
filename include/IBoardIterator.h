#ifndef __BOARD_ITERATOR_H__
#define __BOARD_ITERATOR_H__

class Board;
class Cell;

class IBoardIterator
{
  public:
    IBoardIterator(Board *, int, int);
    virtual ~IBoardIterator();
    int r();
    int c();
    Board * board();

    bool operator==(IBoardIterator *);
    bool operator!=(IBoardIterator *);
    Cell * operator*();

    virtual IBoardIterator * operator++() = 0;
    virtual IBoardIterator * operator++(int) = 0;

    static IBoardIterator * rowMajorBegin(Board *);
    static IBoardIterator * columnMajorBegin(Board *);
    static IBoardIterator * rowMajorEnd(Board *);
    static IBoardIterator * columnMajorEnd(Board *);

    enum class Type { ROW, COL };

  protected:
    Board * _board;
    int _r;
    int _c;
};

#endif // __BOARD_ITERATOR_H__
