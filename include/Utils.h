#ifndef __UTILS_H__
#define __UTILS_H__

#include "Piece.h"

class QPixmap;
class Board;
class Cell;

namespace Ui
{
  class Board;
}

std::string pieceToString(Piece);
QPixmap getIcon(Piece);
void setAllCellsEnabled(bool enabled, Ui::Board * board);
void clearAllCells(Board *);
Cell * nextEmptyCell(Board *);

#endif // __UTILS_H__
