#include "CommonIncludes.h"

#include <QPixmap>

#include "ui_board.h"

#include "Utils.h"

const bool DEBUG = false;

std::string pieceToString(Piece p)
{
  return (Piece::CROSS == p)
      ? "X" 
      : (Piece::OH == p)
          ? "O"
          : "-";
}

void
setAllCellsEnabled(bool enabled, Ui::Board * board)
{
  board->cell_11->setEnabled(enabled);
  board->cell_12->setEnabled(enabled);
  board->cell_13->setEnabled(enabled);
  board->cell_21->setEnabled(enabled);
  board->cell_22->setEnabled(enabled);
  board->cell_23->setEnabled(enabled);
  board->cell_31->setEnabled(enabled);
  board->cell_32->setEnabled(enabled);
  board->cell_33->setEnabled(enabled);
}

QPixmap
getIcon(Piece p)
{
  if (p == Piece::CROSS)
    return QPixmap(":/images/x");

  if (p == Piece::OH)
    return QPixmap(":/images/o");

  return QPixmap(":/images/blank");
}
