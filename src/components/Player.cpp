#include "Player.h"

#include "Piece.h"
#include "Board.h"
#include "GameController.h"
#include "Utils.h"
#include "IStrategy.h"
#include "NaiveStrategy.h"

Player::Player(std::string name, Piece piece, IStrategy * strat)
    : _name(name)
    , _piece(piece)
    , _strategy(strat)
{
  if ( NULL == _strategy ) setStrategy( new NaiveStrategy );
  if ( DEBUG ) std::cerr << "New Player created: " << toString() << std::endl;
}

std::string
Player::toString()
{
  std::stringstream ss;
  ss << _name << "[" << this << "] holding piece: " << pieceToString(piece())
      << " and having strategy: " << _strategy->toString();
  return ss.str();
}

std::string
Player::name()
{
  return _name;
}

Piece
Player::piece()
{
  return _piece;
}

void
Player::setStrategy(IStrategy * s)
{
  _strategy = s;
}

void
Player::move()
{
  if ( NULL == _strategy )
  {
    if ( DEBUG ) std::cerr << "strategy is NULL!!" << std::endl;
    return;
  }

  _strategy->requestNextBestMoveOn(GameController::instance()->board());
}
