#include "CommonIncludes.h"

#include <QPixmap>

#include "Game.h"
#include "Board.h"
#include "IBoardIterator.h"
#include "Cell.h"
#include "ui_board.h"

#include "Utils.h"

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

void
clearAllCells(Board * board)
{
  board->cell(1, 1).setPiece(Piece::BLANK);
  board->cell(1, 2).setPiece(Piece::BLANK);
  board->cell(1, 3).setPiece(Piece::BLANK);
  board->cell(2, 1).setPiece(Piece::BLANK);
  board->cell(2, 2).setPiece(Piece::BLANK);
  board->cell(2, 3).setPiece(Piece::BLANK);
  board->cell(3, 1).setPiece(Piece::BLANK);
  board->cell(3, 2).setPiece(Piece::BLANK);
  board->cell(3, 3).setPiece(Piece::BLANK);
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
  //int i = 0;
  //for ( IBoardIterator &itr = board->begin( IBoardIterator::Type::ROW )
  //    ; itr != board->end( IBoardIterator::Type::ROW ) && i < 10
  //    ; itr++, ++i )
  {
    std::cout << "elem" << std::endl;
  }
  
  return NULL;
}
