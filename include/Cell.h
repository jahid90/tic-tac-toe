#ifndef __CELL_H__
#define __CELL_H__

enum class Piece;

class Board;

class Cell
{
  public:
    Cell(Board *, int, int);
    std::string toString();

    int x();
    int y();
    Piece piece();
    void setPiece(Piece);
    bool isBlank();

  private:
    Board * _parent;
    int _x;
    int _y;
    Piece * _piece;
};

#endif // __CELL_H__
