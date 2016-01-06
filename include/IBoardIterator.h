#ifndef __BOARD_ITERATOR_H__
#define __BOARD_ITERATOR_H__

class Board;
class Cell;

class IBoardIterator
{
  public:
    IBoardIterator(Board &, int, int);
    virtual ~IBoardIterator() {};
    int r();
    int c();
    Board & board();

    Cell & operator*();
    virtual IBoardIterator & operator++() {};
    virtual IBoardIterator operator++(int) {};

#ifdef O
    static IBoardIterator rowMajorBegin(Board &);
    static IBoardIterator columnMajorBegin(Board &);
    static IBoardIterator rowMajorEnd(Board &);
    static IBoardIterator columnMajorEnd(Board &);
#endif

    enum class Type { ROW, COL };

  protected:
    Board & _board;
    int _r;
    int _c;
};

bool operator==(const IBoardIterator & lhs, const IBoardIterator & rhs);
bool operator!=(const IBoardIterator & lhs, const IBoardIterator & rhs);

#endif // __BOARD_ITERATOR_H__
