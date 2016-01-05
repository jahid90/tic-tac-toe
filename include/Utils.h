#ifndef __UTILS_H__
#define __UTILS_H__

#include "Piece.h"

class QPixmap;

namespace Ui
{
  class Board;
}

QPixmap getIcon(Piece);
void setAllCellsEnabled(bool enabled, Ui::Board * board);
void clearAllCells();

#endif // __UTILS_H__
