#ifndef __CELL_H__
#define __CELL_H__

enum class Piece;

class Board;

class Cell
{
  public:
    Cell(Board *, int, int);
    int x();
    int y();
    Piece piece();
    void setPiece(Piece);

  private:
    Board * _parent;
    int _x;
    int _y;
    Piece * _piece;
};

#endif // __CELL_H__
