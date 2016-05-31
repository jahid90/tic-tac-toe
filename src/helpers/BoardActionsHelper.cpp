#include "BoardActionsHelper.h"

#include "Board.h"
#include "Cell.h"
#include "CommonIncludes.h"
#include "GameController.h"
#include "IView.h"
#include "Player.h"
#include "QtBoardView.h"
#include "Utils.h"

BoardActionsHelper * BoardActionsHelper::_instance = NULL;

BoardActionsHelper *
BoardActionsHelper::instance()
{
  if ( NULL == _instance )
  {
    _instance = new BoardActionsHelper;
  }

  return _instance;
}

void
BoardActionsHelper::nullify()
{
  delete _instance;
  _instance = NULL;
}

void
BoardActionsHelper::init(IView * view)
{
  _backingView = view;
}

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

BoardActionsHelper::~BoardActionsHelper()
{
  cellMap.clear();
  _backingView = NULL;
}

/* slot */ void
BoardActionsHelper::clear()
{
  if ( DEBUG )
    std::cerr << "received signal to clear board" << std::endl;

  GameController::instance()->reset();
}

void
BoardActionsHelper::clearBoard()
{
  QPixmap blankImg(":/images/blank");

  if ( DEBUG )
    std::cerr << "resetting ui" << std::endl;

  emit setContent11(blankImg);
  emit setContent12(blankImg);
  emit setContent13(blankImg);
  emit setContent21(blankImg);
  emit setContent22(blankImg);
  emit setContent23(blankImg);
  emit setContent31(blankImg);
  emit setContent32(blankImg);
  emit setContent33(blankImg);
}

/* slot */ void
BoardActionsHelper::cellClicked()
{
  QString senderName = sender()->objectName();

  QPixmap icon = getIcon( GameController::instance()->currentPlayer()->piece() );

  int r = cellMap[senderName].first;
  int c = cellMap[senderName].second;

  if ( DEBUG )
    std::cerr << "GUI cell clicked at [" << r << "][" << c << "]" << std::endl;

  cellClicked(r, c, icon);
}

void
BoardActionsHelper::cellClicked(int r, int c, QPixmap)
{
  switch(r)
  {
    case 1:
      switch(c)
      {
        case 1:
          _backingView->notify(1, 1);
          break;
        case 2:
          _backingView->notify(1, 2);
          break;
        case 3:
          _backingView->notify(1, 3);
          break;
      }
      break;

    case 2:
      switch(c)
      {
        case 1:
          _backingView->notify(2, 1);
          break;
        case 2:
          _backingView->notify(2, 2);
          break;
        case 3:
          _backingView->notify(2, 3);
          break;
      }
      break;

    case 3:
      switch(c)
      {
        case 1:
          _backingView->notify(3, 1);
          break;
        case 2:
          _backingView->notify(3, 2);
          break;
        case 3:
          _backingView->notify(3, 3);
          break;
      }
      break;
  }
}

void
BoardActionsHelper::markCell(int r, int c, Piece p)
{
  QPixmap icon = getIcon( p );

  if ( DEBUG )
    std::cerr << "GUI cell clicked at [" << r << "][" << c << "]" << std::endl;

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
          break;
        case 2: 
          emit setContent12(img);
          break;
        case 3: 
          emit setContent13(img);
          break;
      }
      break;

    case 2:
      switch(c)
      {
        case 1: 
          emit setContent21(img);
          break;
        case 2:
          emit setContent22(img);
          break;
        case 3:
          emit setContent23(img);
          break;
      }
      break;

    case 3:
      switch(c)
      {
        case 1:
          emit setContent31(img);
          break;
        case 2:
          emit setContent32(img);
          break;
        case 3:
          emit setContent33(img);
          break;
      }
      break;
  }
}
