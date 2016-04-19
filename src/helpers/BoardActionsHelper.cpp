#include "CommonIncludes.h"

#include "Utils.h"
#include "QtBoardView.h"
#include "GameController.h"
#include "Player.h"
#include "Board.h"
#include "Cell.h"

#include "BoardActionsHelper.h"

BoardActionsHelper::BoardActionsHelper(QObject * parent)
    : QObject(parent)
{
  cellMap.insert("cell_11", qMakePair(1, 1));
  cellMap.insert("cell_12", qMakePair(1, 2));
  cellMap.insert("cell_13", qMakePair(1, 3));
  cellMap.insert("cell_21", qMakePair(2, 1));
  cellMap.insert("cell_22", qMakePair(2, 2));
  cellMap.insert("cell_23", qMakePair(2, 3));
  cellMap.insert("cell_31", qMakePair(3, 1));
  cellMap.insert("cell_32", qMakePair(3, 2));
  cellMap.insert("cell_33", qMakePair(3, 3));
}

/* slot */ void
BoardActionsHelper::clearBoard()
{
  GameController::instance()->board()->clearAllCells();

  QPixmap blankImg(":/images/blank");

  emit setContent11(blankImg);
  emit setContent12(blankImg);
  emit setContent13(blankImg);
  emit setContent21(blankImg);
  emit setContent22(blankImg);
  emit setContent23(blankImg);
  emit setContent31(blankImg);
  emit setContent32(blankImg);
  emit setContent33(blankImg);

  setAllCellsEnabled( true, QtBoardView::board() );
}

/* slot */ void
BoardActionsHelper::markCell()
{
  QString senderName = sender()->objectName();

  QPixmap icon = getIcon( GameController::instance()->currentPlayer()->piece() );

  int r = cellMap[senderName].first;
  int c = cellMap[senderName].second;

  std::cerr << "emitting markCell for [" << r << "][" << c << "]" << std::endl;

  markCell(r, c, icon);
}

void
BoardActionsHelper::markCell(int r, int c, QPixmap img)
{
  switch(r)
  {
    case 1:
      switch(c)
      {
        case 1: 
          emit setContent11(img);
          GameController::instance()->board()->cell(1, 1)
              .setPiece(GameController::instance()->currentPlayer()->piece());
          break;
        case 2: 
          emit setContent12(img);
          GameController::instance()->board()->cell(1, 2)
              .setPiece(GameController::instance()->currentPlayer()->piece());
          break;
        case 3: 
          emit setContent13(img);
          GameController::instance()->board()->cell(1, 3)
              .setPiece(GameController::instance()->currentPlayer()->piece());
          break;
      }
      break;

    case 2:
      switch(c)
      {
        case 1: 
          emit setContent21(img);
          GameController::instance()->board()->cell(2, 1)
              .setPiece(GameController::instance()->currentPlayer()->piece());
          break;
        case 2:
          emit setContent22(img);
          GameController::instance()->board()->cell(2, 2)
              .setPiece(GameController::instance()->currentPlayer()->piece());
          break;
        case 3:
          emit setContent23(img);
          GameController::instance()->board()->cell(2, 3)
              .setPiece(GameController::instance()->currentPlayer()->piece());
          break;
      }
      break;

    case 3:
      switch(c)
      {
        case 1:
          emit setContent31(img);
          GameController::instance()->board()->cell(3, 1)
              .setPiece(GameController::instance()->currentPlayer()->piece());
          break;
        case 2:
          emit setContent32(img);
          GameController::instance()->board()->cell(3, 2)
              .setPiece(GameController::instance()->currentPlayer()->piece());
          break;
        case 3:
          emit setContent33(img);
          GameController::instance()->board()->cell(3, 3)
              .setPiece(GameController::instance()->currentPlayer()->piece());
          break;
      }
      break;
  }

  GameController::instance()->secondPlayer()->makeMove();
}
