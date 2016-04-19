#include "CommonIncludes.h"

#include <QPixmap>
#include <QPushButton>

#include "ui_board.h"
#include "BoardActionsHelper.h"
#include "GameController.h"
#include "Board.h"
#include "Cell.h"

#include "QtBoardView.h"

QtBoardView::QtBoardView(QMainWindow * parent)
    : QMainWindow(parent)
{
  board()->setupUi(this);

  initSignalsAndSlots();

  setupCellsToUseScaledContents();

  BoardActionsHelper::instance()->clearBoard();
}

void 
QtBoardView::initSignalsAndSlots()
{
  connect( board()->btnQuit, SIGNAL (clicked()), 
      QApplication::instance(), SLOT (quit()) );

  connect( board()->btnClear, SIGNAL (clicked()), 
      BoardActionsHelper::instance(), SLOT (clearBoard()) );

  connectMessageDispatchWithCell();

  connectCellClickWithHelper();
}

void
QtBoardView::connectMessageDispatchWithCell()
{
  connect( BoardActionsHelper::instance(), SIGNAL (setContent11(QPixmap)),
      board()->cell_11, SLOT (setPixmap(QPixmap)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setContent12(QPixmap)),
      board()->cell_12, SLOT (setPixmap(QPixmap)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setContent13(QPixmap)),
      board()->cell_13, SLOT (setPixmap(QPixmap)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setContent21(QPixmap)),
      board()->cell_21, SLOT (setPixmap(QPixmap)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setContent22(QPixmap)),
      board()->cell_22, SLOT (setPixmap(QPixmap)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setContent23(QPixmap)),
      board()->cell_23, SLOT (setPixmap(QPixmap)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setContent31(QPixmap)),
      board()->cell_31, SLOT (setPixmap(QPixmap)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setContent32(QPixmap)),
      board()->cell_32, SLOT (setPixmap(QPixmap)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setContent33(QPixmap)),
      board()->cell_33, SLOT (setPixmap(QPixmap)) );
}

void
QtBoardView::connectCellClickWithHelper()
{
  connect( board()->cell_11, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (markCell()) );
  connect( board()->cell_12, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (markCell()) );
  connect( board()->cell_13, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (markCell()) );
  connect( board()->cell_21, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (markCell()) );
  connect( board()->cell_22, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (markCell()) );
  connect( board()->cell_23, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (markCell()) );
  connect( board()->cell_31, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (markCell()) );
  connect( board()->cell_32, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (markCell()) );
  connect( board()->cell_33, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (markCell()) );
}

void
QtBoardView::setupCellsToUseScaledContents()
{
  board()->cell_11->setScaledContents(true);
  board()->cell_12->setScaledContents(true);
  board()->cell_13->setScaledContents(true);
  board()->cell_21->setScaledContents(true);
  board()->cell_22->setScaledContents(true);
  board()->cell_23->setScaledContents(true);
  board()->cell_31->setScaledContents(true);
  board()->cell_32->setScaledContents(true);
  board()->cell_33->setScaledContents(true);
}
