#include "GuiView.h"

#include <QApplication>
#include <QIcon>

#include "QtBoardView.h"

void
GuiView::init(int argc, char ** argv)
{
  _app = new QApplication(argc, argv);

  QIcon appIcon(":/images/icon");
  _app->setWindowIcon(appIcon);

  QtBoardView *board = new QtBoardView(NULL);
  board->show();

  int rc = _app->exec();
}

void
GuiView::reset()
{

}

void
GuiView::markCell(int, int, Piece)
{

}

void
GuiView::clearCell(int, int)
{

}

void
GuiView::setStatusMessage(std::string)
{

}
