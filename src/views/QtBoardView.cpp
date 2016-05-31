#include "QtBoardView.h"

#include <QPixmap>
#include <QPushButton>

#include "Board.h"
#include "BoardActionsHelper.h"
#include "Cell.h"
#include "CommonIncludes.h"
#include "GameController.h"
#include "GuiView.h"
#include "ui_board.h"

Ui::Board * QtBoardView::_board = NULL;

Ui::Board *
QtBoardView::uiboard()
{
  if (NULL == _board)
  {
    _board = new Ui::Board;
  }

  return _board;
}

QtBoardView::QtBoardView(QMainWindow * parent)
    : QMainWindow(parent)
{
  _helper = BoardActionsHelper::instance();

  uiboard()->setupUi(this);

  initSignalsAndSlots();

  setupCellsToUseScaledContents();

  _helper->clearBoard();
}

QtBoardView::~QtBoardView()
{
  _helper = NULL;
}

void 
QtBoardView::initSignalsAndSlots()
{
  connect( uiboard()->btnQuit, SIGNAL (clicked()), 
      QApplication::instance(), SLOT (quit()) );

  connect( uiboard()->btnClear, SIGNAL (clicked()), 
      _helper, SLOT (clear()) );

  connectMessageDispatchWithCell();

  connectCellClickWithHelper();
}

void
QtBoardView::connectMessageDispatchWithCell()
{
  connect( _helper, SIGNAL (setContent11(QPixmap)),
      uiboard()->cell_11, SLOT (setPixmap(QPixmap)) );
  connect( _helper, SIGNAL (setContent12(QPixmap)),
      uiboard()->cell_12, SLOT (setPixmap(QPixmap)) );
  connect( _helper, SIGNAL (setContent13(QPixmap)),
      uiboard()->cell_13, SLOT (setPixmap(QPixmap)) );
  connect( _helper, SIGNAL (setContent21(QPixmap)),
      uiboard()->cell_21, SLOT (setPixmap(QPixmap)) );
  connect( _helper, SIGNAL (setContent22(QPixmap)),
      uiboard()->cell_22, SLOT (setPixmap(QPixmap)) );
  connect( _helper, SIGNAL (setContent23(QPixmap)),
      uiboard()->cell_23, SLOT (setPixmap(QPixmap)) );
  connect( _helper, SIGNAL (setContent31(QPixmap)),
      uiboard()->cell_31, SLOT (setPixmap(QPixmap)) );
  connect( _helper, SIGNAL (setContent32(QPixmap)),
      uiboard()->cell_32, SLOT (setPixmap(QPixmap)) );
  connect( _helper, SIGNAL (setContent33(QPixmap)),
      uiboard()->cell_33, SLOT (setPixmap(QPixmap)) );
}

void
QtBoardView::connectCellClickWithHelper()
{
  connect( uiboard()->cell_11, SIGNAL (clicked()),
      _helper, SLOT (cellClicked()) );
  connect( uiboard()->cell_12, SIGNAL (clicked()),
      _helper, SLOT (cellClicked()) );
  connect( uiboard()->cell_13, SIGNAL (clicked()),
      _helper, SLOT (cellClicked()) );
  connect( uiboard()->cell_21, SIGNAL (clicked()),
      _helper, SLOT (cellClicked()) );
  connect( uiboard()->cell_22, SIGNAL (clicked()),
      _helper, SLOT (cellClicked()) );
  connect( uiboard()->cell_23, SIGNAL (clicked()),
      _helper, SLOT (cellClicked()) );
  connect( uiboard()->cell_31, SIGNAL (clicked()),
      _helper, SLOT (cellClicked()) );
  connect( uiboard()->cell_32, SIGNAL (clicked()),
      _helper, SLOT (cellClicked()) );
  connect( uiboard()->cell_33, SIGNAL (clicked()),
      _helper, SLOT (cellClicked()) );
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
