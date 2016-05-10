#include "GameController.h"

#include "Board.h"
#include "Player.h"
#include "Cell.h"
#include "Piece.h"
#include "IStrategy.h"
#include "NaiveStrategy.h"
#include "HumanStrategy.h"
#include "IView.h"
#include "ConsoleView.h"
#include "GuiView.h"
#include "QtBoardView.h"
#include "Utils.h"

GameController * GameController::_instance = new GameController;

GameController::GameController()
    : _board(new Board)
    , _firstPlayer( new Player("Naive AI", Piece::CROSS, new NaiveStrategy) )
    , _secondPlayer( new Player("Human Player", Piece::OH, new HumanStrategy) )
    , _view(new GuiView)
{
  _board->registerStateObserver(this);
  _view->attachListener(this);

  if ( DEBUG )
    std::cerr << "New GameController created: " << toString() << std::endl;
}

void
GameController::init()
{
  setRandomFirstPlayer();

  _view->init();
}

void
GameController::setRandomFirstPlayer()
{
  srand( 2 ); // TODO - randomize

  setCurrentPlayer( rand() % 2 ? firstPlayer() : secondPlayer() );

  if ( DEBUG )
    std::cerr << "currentPlayer: " << currentPlayer()->toString() << std::endl;
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
GameController::playGame()
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
    if ( DEBUG ) std::cerr << "next blank detected at: " << board()->nextBlankCell() << std::endl;

    playTurn();
  }
  else if ( !hasWinner() )
  {
      view()->setStatusMessage( "Game is a draw! Well played both!" );
      view()->freezeView();
  }
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

void
GameController::playTurn()
{
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

bool
GameController::isBoardFull()
{
  return !board()->hasBlankCell();
}

void
GameController::cellStateChanged(Cell * cell)
{
  view()->markCell(cell->x(), cell->y(), currentPlayer()->piece());
  switchPlayers();
  playGame();
}

void
GameController::cellSelected(int r, int c)
{
  Cell * cell = &board()->cell(r, c);
  board()->placePiece( cell, currentPlayer()->piece() );
}