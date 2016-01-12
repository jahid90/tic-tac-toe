#include "NaiveStrategy.h"

#include "Board.h"

Cell *
NaiveStrategy::getNextBestMoveFor(Player * player, Board * board)
{
  if ( board->hasBlankCell() )
  {
    return board->nextBlankCell();
  }

  std::cerr << "error! requested next move when no blank cell left on board." << std::endl;

  return NULL; // throw exception
}

std::string
NaiveStrategy::toString()
{
  std::stringstream ss;
  ss << "[" << this << "] NaiveStrategy";
  return ss.str();
}
