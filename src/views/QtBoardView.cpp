#include "CommonIncludes.h"

#include "QtBoardView.h"
#include "ui_board.h"

QtBoardView::QtBoardView(QMainWindow *parent)
    : QMainWindow(parent), board(new Ui::Board)
{
  board->setupUi(this);

  initSignalsAndSlots();
}

QtBoardView::~QtBoardView()
{
  delete board;
}

void QtBoardView::initSignalsAndSlots()
{
  connect( board->btnQuit, SIGNAL (clicked()), 
      QApplication::instance(), SLOT (quit()) );
}
