#include "CommonIncludes.h"

#include <QPixmap>

#include "Game.h"
#include "Board.h"
#include "Cell.h"
#include "ui_board.h"

#include "Utils.h"

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

void
clearAllCells(Board * board)
{
  board->cell(1, 1)->setPiece(Piece::BLANK);
  board->cell(1, 2)->setPiece(Piece::BLANK);
  board->cell(1, 3)->setPiece(Piece::BLANK);
  board->cell(2, 1)->setPiece(Piece::BLANK);
  board->cell(2, 2)->setPiece(Piece::BLANK);
  board->cell(2, 3)->setPiece(Piece::BLANK);
  board->cell(3, 1)->setPiece(Piece::BLANK);
  board->cell(3, 2)->setPiece(Piece::BLANK);
  board->cell(3, 3)->setPiece(Piece::BLANK);
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

Cell *
nextEmptyCell(Board * board)
{
  Board * copy = board;
  
  return NULL;
}
