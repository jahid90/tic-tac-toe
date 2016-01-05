#include "Game.h"

#include "Board.h"
#include "Player.h"
#include "Piece.h"

Game::Game()
    : _board(new Board)
    , _firstPlayer( new Player(Piece::CROSS) )
    , _secondPlayer( new Player(Piece::OH) )
{
  setCurrentPlayer( firstPlayer() );
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
