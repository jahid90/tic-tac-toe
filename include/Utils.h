#ifndef __UTILS_H__
#define __UTILS_H__

#include "Piece.h"

class QPixmap;
class Cell;

namespace Ui
{
  class Board;
}

extern const bool DEBUG;

std::string pieceToString(Piece);
QPixmap getIcon(Piece);
void setAllCellsEnabled(bool enabled, Ui::Board * board);

#endif // __UTILS_H__
