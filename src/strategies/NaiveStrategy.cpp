#include "NaiveStrategy.h"

#include "Board.h"
#include "GameController.h"
#include "IView.h"
#include "Utils.h"

Cell *
NaiveStrategy::getNextBestMoveFor(Player * player, Board * board)
{
  if ( board->hasBlankCell() )
  {
    Cell * bestMove = board->nextBlankCell();

    std::string msg = "AI's move is: ";
    msg += (char)( '0' + bestMove->x() + 1 );
    msg += " ";
    msg += (char)( '0' + bestMove->y() + 1 );
    GameController::instance()->view()->setStatusMessage( msg );

    return bestMove;
  }

  if ( DEBUG ) std::cerr << "error! requested next move when no blank cell left on board." << std::endl;

  return NULL; // throw exception
}

std::string
NaiveStrategy::toString()
{
  std::stringstream ss;
  ss << "[" << this << "] NaiveStrategy";
  return ss.str();
}
