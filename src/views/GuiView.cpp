#include "GuiView.h"

#include <QApplication>
#include <QIcon>
#include <QString>

#include "QtBoardView.h"
#include "BoardActionsHelper.h"
#include "ArgumentsParser.h"
#include "Utils.h"
#include "GameController.h"

void
GuiView::init()
{
  int argc = ArgumentsParser::instance()->getArgc();
  char ** argv = ArgumentsParser::instance()->getArgv();

  if ( DEBUG )
    std::cerr << "received arguments" << std::endl;
  
  _app = new QApplication(argc, argv);

  if ( DEBUG )
    std::cerr << "setting app icon" << std::endl;

  QIcon appIcon(":/images/icon");
  _app->setWindowIcon(appIcon);

  _guiBoard = new QtBoardView(NULL);
  _guiBoard->show();

  if ( DEBUG ) 
    std::cerr << "init done. launching gui..." << std::endl;

  _app->exec();
}

void
GuiView::reset()
{
  BoardActionsHelper::instance()->clearBoard();
  _guiBoard->uiboard()->statusbar->showMessage("");
  _guiBoard->setAllCellsEnabled( true );
  GameController::instance()->setRandomFirstPlayer();
}

void
GuiView::markCell(int r, int c, Piece p)
{
  BoardActionsHelper::instance()->markCell(1 + r, 1 + c, p);
}

void
GuiView::clearCell(int r, int c)
{
  BoardActionsHelper::instance()->markCell(1 + r, 1 + c, Piece::BLANK);
}

void
GuiView::setStatusMessage(std::string m)
{
  QString msg(m.c_str());
  _guiBoard->uiboard()->statusbar->showMessage( msg );
}

void
GuiView::waitForMove()
{
  // no-op
}

void
GuiView::freezeView()
{
  _guiBoard->setAllCellsEnabled( false );
}
