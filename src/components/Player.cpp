#include "Player.h"

#include "Piece.h"
#include "Board.h"
#include "Game.h"
#include "Utils.h"
#include "IStrategy.h"
#include "NaiveStrategy.h"

Player::Player(Piece piece, IStrategy * strat)
    : _piece(piece)
    , _strategy(strat)
{
  if (NULL == strategy()) setStrategy( new NaiveStrategy );
  std::cerr << "New Player created: " << toString() << std::endl;
}

std::string
Player::toString()
{
  std::stringstream ss;
  ss << "[" << this << "] holding piece: " << pieceToString(piece())
      << " and having strategy: " << strategy()->toString();
  return ss.str();
}

Piece
Player::piece()
{
  return _piece;
}

void
Player::makeMove()
{
  if (NULL == strategy())
  {
    std::cerr << "strategy is NULL!!" << std::endl;
    return;
  }

  Game::instance()->board()->placePiece(
      strategy()->getNextBestMoveFor(this, Game::instance()->board()),
      this->piece() );
}

IStrategy *
Player::strategy()
{
  return _strategy;
}

void
Player::setStrategy(IStrategy * s)
{
  _strategy = s;
}
