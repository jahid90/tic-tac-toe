#ifndef __CELL_H__
#define __CELL_H__

#include "CommonIncludes.h"

enum class Piece;

class Cell
{
  public:
    Cell(int, int);
    std::string toString();

    int x();
    int y();
    Piece piece();
    void setPiece(Piece);
    bool isBlank();

  private:
    int _x;
    int _y;
    Piece * _piece;
};

#endif // __CELL_H__
