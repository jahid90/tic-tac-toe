#include "CommonIncludes.h"

#include <QPixmap>
#include <QPushButton>

#include "ui_board.h"
#include "BoardActionsHelper.h"
#include "GameController.h"
#include "Board.h"
#include "Cell.h"
#include "GuiView.h"

#include "QtBoardView.h"

QtBoardView::QtBoardView(GuiView * view, QMainWindow * parent)
    : QMainWindow(parent)
    , _view(view)
{
  uiboard()->setupUi(this);

  initSignalsAndSlots();

  setupCellsToUseScaledContents();

  BoardActionsHelper::instance()->clearBoard();
}

void 
QtBoardView::initSignalsAndSlots()
{
  connect( uiboard()->btnQuit, SIGNAL (clicked()), 
      QApplication::instance(), SLOT (quit()) );

  connect( uiboard()->btnClear, SIGNAL (clicked()), 
      BoardActionsHelper::instance(), SLOT (clear()) );

  connectMessageDispatchWithCell();

  connectCellClickWithHelper();
}

void
QtBoardView::connectMessageDispatchWithCell()
{
  connect( BoardActionsHelper::instance(), SIGNAL (setContent11(QPixmap)),
      uiboard()->cell_11, SLOT (setPixmap(QPixmap)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setContent12(QPixmap)),
      uiboard()->cell_12, SLOT (setPixmap(QPixmap)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setContent13(QPixmap)),
      uiboard()->cell_13, SLOT (setPixmap(QPixmap)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setContent21(QPixmap)),
      uiboard()->cell_21, SLOT (setPixmap(QPixmap)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setContent22(QPixmap)),
      uiboard()->cell_22, SLOT (setPixmap(QPixmap)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setContent23(QPixmap)),
      uiboard()->cell_23, SLOT (setPixmap(QPixmap)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setContent31(QPixmap)),
      uiboard()->cell_31, SLOT (setPixmap(QPixmap)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setContent32(QPixmap)),
      uiboard()->cell_32, SLOT (setPixmap(QPixmap)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setContent33(QPixmap)),
      uiboard()->cell_33, SLOT (setPixmap(QPixmap)) );
}

void
QtBoardView::connectCellClickWithHelper()
{
  connect( uiboard()->cell_11, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (cellClicked()) );
  connect( uiboard()->cell_12, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (cellClicked()) );
  connect( uiboard()->cell_13, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (cellClicked()) );
  connect( uiboard()->cell_21, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (cellClicked()) );
  connect( uiboard()->cell_22, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (cellClicked()) );
  connect( uiboard()->cell_23, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (cellClicked()) );
  connect( uiboard()->cell_31, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (cellClicked()) );
  connect( uiboard()->cell_32, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (cellClicked()) );
  connect( uiboard()->cell_33, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (cellClicked()) );
}

void
QtBoardView::setupCellsToUseScaledContents()
{
  uiboard()->cell_11->setScaledContents(true);
  uiboard()->cell_12->setScaledContents(true);
  uiboard()->cell_13->setScaledContents(true);
  uiboard()->cell_21->setScaledContents(true);
  uiboard()->cell_22->setScaledContents(true);
  uiboard()->cell_23->setScaledContents(true);
  uiboard()->cell_31->setScaledContents(true);
  uiboard()->cell_32->setScaledContents(true);
  uiboard()->cell_33->setScaledContents(true);
}

void
QtBoardView::setAllCellsEnabled(bool enabled)
{
  uiboard()->cell_11->setEnabled(enabled);
  uiboard()->cell_12->setEnabled(enabled);
  uiboard()->cell_13->setEnabled(enabled);
  uiboard()->cell_21->setEnabled(enabled);
  uiboard()->cell_22->setEnabled(enabled);
  uiboard()->cell_23->setEnabled(enabled);
  uiboard()->cell_31->setEnabled(enabled);
  uiboard()->cell_32->setEnabled(enabled);
  uiboard()->cell_33->setEnabled(enabled);
}
