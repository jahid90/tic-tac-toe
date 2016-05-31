#include "GuiView.h"

#include <QApplication>
#include <QIcon>
#include <QString>

#include "ArgumentsParser.h"
#include "BoardActionsHelper.h"
#include "GameController.h"
#include "QtBoardView.h"
#include "Utils.h"
#include "ui_board.h"

void
GuiView::init()
{
  int argc = ArgumentsParser::instance()->getArgc();
  char ** argv = ArgumentsParser::instance()->getArgv();

  _helper = BoardActionsHelper::instance();
  _helper->init( this );

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

GuiView::GuiView()
{
  BoardActionsHelper::nullify();
  _helper = NULL;

  _app = NULL;
  
  _guiBoard = NULL;
}

GuiView::~GuiView()
{
  delete _guiBoard;
  _guiBoard = NULL;

  delete _app;
  _app = NULL;

  _helper = NULL;
}

void
GuiView::reset()
{
  _helper->clearBoard();

  _guiBoard->uiboard()->statusbar->showMessage("");
  _guiBoard->setAllCellsEnabled( true );
}

void
GuiView::markCell(int r, int c, Piece p)
{
  _helper->markCell(1 + r, 1 + c, p);
}

void
GuiView::clearCell(int r, int c)
{
  _helper->markCell(1 + r, 1 + c, Piece::BLANK);
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
