#include "GuiView.h"

#include <QApplication>
#include <QIcon>

#include "QtBoardView.h"

int GuiView::_argc;
char ** GuiView::_argv;

void GuiView::initParams(int argc, char ** argv)
{
  _argc = argc;
  _argv = argv;
}

void
GuiView::init()
{
  _app = new QApplication(_argc, _argv);

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

void
GuiView::waitForMove()
{
  // no-op
}
