#include "Game.h"

#include "Board.h"
#include "Player.h"
#include "Piece.h"
#include "IStrategy.h"
#include "NaiveStrategy.h"

Game::Game()
    : _board(new Board)
    , _firstPlayer( new Player(Piece::CROSS) )
    , _secondPlayer( new Player(Piece::OH) )
{
  setCurrentPlayer( firstPlayer() );

  std::cerr << "New Game created: " << toString() << std::endl;
}

std::string
Game::toString()
{
  std::stringstream ss;
  ss << "[" << this << "] fP: " << firstPlayer()->toString()
      << ", sP: " << secondPlayer()->toString();
  return ss.str();
}

Board *
Game::board()
{
  return _board;
}

Player *
Game::firstPlayer()
{
  return _firstPlayer;
}

Player *
Game::secondPlayer()
{
  return _secondPlayer;
}

Player *
Game::currentPlayer()
{
  return _currentPlayer;
}

void
Game::setCurrentPlayer(Player * p)
{
  _currentPlayer = p;
}

bool
Game::hasWinner()
{
  return board()->hasWinner();
}

void
Game::playTurn()
{
  currentPlayer()->makeMove();
  switchPlayers();
}

void
Game::switchPlayers()
{
  if ( currentPlayer() == firstPlayer() )
  {
    setCurrentPlayer( secondPlayer() );
  }
  else
  {
    setCurrentPlayer( firstPlayer() );
  }
}
