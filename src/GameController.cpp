#include "GameController.h"

#include "ArgumentsParser.h"
#include "Cell.h"
#include "ConsoleView.h"
#include "GuiView.h"
#include "HumanStrategy.h"
#include "IStrategy.h"
#include "NaiveStrategy.h"
#include "Piece.h"
#include "Player.h"
#include "QtBoardView.h"
#include "UnbeatableStrategy.h"
#include "Utils.h"

GameController * GameController::_instance = NULL;

GameController * 
GameController::instance()
{
  if ( NULL == _instance )
  {
    _instance = new GameController;
  }

  return _instance;
}

GameController::GameController()
{
  initComponents();

  _board->registerStateObserver(this);
  _view->attachListener(this);

  if ( DEBUG )
    std::cerr << "New GameController created: " << toString() << std::endl;
}

void
GameController::initComponents()
{
  bool easyMode = ArgumentsParser::instance()->get("beginner") ? true : false;
  bool graphical = ArgumentsParser::instance()->get("console") ? false : true;

  _board = new Board;

  _firstPlayer = easyMode
      ? new Player("Naive AI", Piece::CROSS, new NaiveStrategy)
      : new Player("Unbeatable AI", Piece::CROSS, new UnbeatableStrategy);

  _secondPlayer = new Player("Human Player", Piece::OH, new HumanStrategy);

  _view = graphical
      ? (IView *) new GuiView
      : (IView *) new ConsoleView;
}

void
GameController::init()
{
  randomizeCurrentPlayer();

  _view->init();

  playTurn();
}

void
GameController::randomizeCurrentPlayer()
{
  srand( 0 ); // TODO - randomize

  // setCurrentPlayer( rand() % 2 ? firstPlayer() : secondPlayer() );
  setCurrentPlayer( secondPlayer() );

  if ( DEBUG )
    std::cerr << "currentPlayer at randomize: " << currentPlayer()->toString() << std::endl;
}

std::string
GameController::toString()
{
  std::stringstream ss;
  ss << "[" << this << "] fP: " << firstPlayer()->toString()
      << ", sP: " << secondPlayer()->toString();
  return ss.str();
}

void
GameController::playTurn()
{
  if ( hasWinner() )
  {
    std::string msg = board()->winner()->name();
    msg += " is the winner! Congrats!";
    view()->setStatusMessage( msg );
    view()->freezeView();
  }
  else if ( !isBoardFull() )
  {
    if ( DEBUG )
      std::cerr << "next blank detected at: " << board()->nextBlankCell() << std::endl;

    makeMove();
  }
  else if ( !hasWinner() )
  {
    view()->setStatusMessage( "Game is a draw! Well played both!" );
    view()->freezeView();
  }
}

void
GameController::makeMove()
{
  if ( DEBUG )
    std::cerr << "playing " << currentPlayer()->toString() << "'s turn..." << std::endl;

  currentPlayer()->move();
}

void
GameController::switchPlayers()
{
  setCurrentPlayer( 
      currentPlayer() == firstPlayer()
      ? secondPlayer()
      : firstPlayer()
  );
}

Board *
GameController::board()
{
  return _board;
}

Player *
GameController::firstPlayer()
{
  return _firstPlayer;
}

Player *
GameController::secondPlayer()
{
  return _secondPlayer;
}

Player *
GameController::currentPlayer()
{
  return _currentPlayer;
}

void
GameController::setCurrentPlayer(Player * p)
{
  _currentPlayer = p;
}

IView *
GameController::view()
{
  return _view;
}

bool
GameController::hasWinner()
{
  return board()->hasWinner();
}

bool
GameController::isBoardFull()
{
  return !board()->hasBlankCell();
}

void
GameController::reset()
{
  GameController::instance()->randomizeCurrentPlayer();
  GameController::instance()->playTurn();
}

void
GameController::cellStateChanged(Cell * cell)
{
  view()->markCell(cell->x(), cell->y(), currentPlayer()->piece());
  switchPlayers();
  playTurn();
}

void
GameController::cellSelected(int r, int c)
{
  board()->placePiece( board()->cell(r, c), currentPlayer()->piece() );
}