#include "GameController.h"

#include "Board.h"
#include "Player.h"
#include "Piece.h"
#include "IStrategy.h"
#include "NaiveStrategy.h"
#include "HumanStrategy.h"
#include "IView.h"
#include "ConsoleView.h"
#include "GuiView.h"
#include "QtBoardView.h"

GameController::GameController()
    : _board(new Board)
    , _firstPlayer( new Player("Naive AI", Piece::CROSS, new NaiveStrategy) )
    , _secondPlayer( new Player("Human Player", Piece::OH, new HumanStrategy) )
    , _view(new ConsoleView)
{
  setCurrentPlayer( firstPlayer() );

  _view->init();

  std::cerr << "New GameController created: " << toString() << std::endl;
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
  while ( !isBoardFull() )
  {
    std::cerr << "next blank detected at: " << board()->nextBlankCell() << std::endl;

    playTurn();
    switchPlayers();

    if ( hasWinner() )
    {
      std::cout << board()->winner()->toString() 
          << " is the winner! Congrats!" << std::endl;
      break;
    }
  }

  if ( !hasWinner() )
  {
      std::cout << "Game is a draw! Well played both!" << std::endl;
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
  currentPlayer()->makeMove();
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
