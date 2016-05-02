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
  if (NULL == strategy()) setStrategy( new NaiveStrategy );
  if ( DEBUG ) std::cerr << "New Player created: " << toString() << std::endl;
}

std::string
Player::toString()
{
  std::stringstream ss;
  ss << _name << "[" << this << "] holding piece: " << pieceToString(piece())
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
    if ( DEBUG ) std::cerr << "strategy is NULL!!" << std::endl;
    return;
  }

  Board * board = GameController::instance()->board();

  board->placePiece(
      strategy()->getNextBestMoveFor(this, board),
      this->piece()
  );
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
