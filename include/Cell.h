#ifndef __CELL_H__
#define __CELL_H__

#include <QObject>

enum class Piece;

class Board;

class Cell : public QObject
{
  Q_OBJECT
  public:
    Cell(Board *, int, int);
    int x();
    int y();
    Piece piece();
    void setPiece(Piece);

  public slots:
    void onCellSelected();

  private:
    Board * _parent;
    int _x;
    int _y;
    Piece * _piece;
};

#endif // __CELL_H__
