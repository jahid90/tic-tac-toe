#include "CommonIncludes.h"

#include "ui_board.h"
#include "BoardActionsHelper.h"

#include "QtBoardView.h"

QtBoardView::QtBoardView(QMainWindow *parent)
    : QMainWindow(parent)
{
  if (_board == NULL) 
    _board = new Ui::Board;

  _board->setupUi(this);

  initSignalsAndSlots();
}

QtBoardView::~QtBoardView()
{
  delete _board;
}

Ui::Board * QtBoardView::board()
{
  return _board;
}

void 
QtBoardView::initSignalsAndSlots()
{
  connect( _board->btnQuit, SIGNAL (clicked()), 
      QApplication::instance(), SLOT (quit()) );

  connect( _board->btnClear, SIGNAL (clicked()), 
      BoardActionsHelper::instance(), SLOT (clearBoard()) );
}
