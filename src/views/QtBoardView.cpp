#include "QtBoardView.h"
#include "ui_board.h"

QtBoardView::QtBoardView(QMainWindow *parent)
    : QMainWindow(parent), board(new Ui::Board)
{
  board->setupUi(this);

  connect( board->btnQuit, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()) );
}

QtBoardView::~QtBoardView()
{
  delete board;
}
