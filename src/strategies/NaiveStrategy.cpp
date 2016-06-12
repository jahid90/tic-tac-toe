#include "NaiveStrategy.h"

#include "Board.h"
#include "GameController.h"
#include "IView.h"
#include "Utils.h"

void
NaiveStrategy::requestNextBestMoveOn(Board * board)
{
  std::this_thread::sleep_for( std::chrono::seconds(1) );

  if ( board->hasBlankCell() )
  {
    Cell * bestMove = board->nextBlankCell();

    std::string msg = "AI's move is: ";
    msg += (char)( '0' + bestMove->x() + 1 );
    msg += " ";
    msg += (char)( '0' + bestMove->y() + 1 );
    GameController::instance()->view()->setStatusMessage( msg );

    GameController::instance()->view()->notify( bestMove->x() + 1, bestMove->y() + 1 );

    return;
  }

  if ( DEBUG )
    std::cerr << "error! requested next move when no blank cell left on board." << std::endl;

  return; // throw exception
}

std::string
NaiveStrategy::toString()
{
  std::stringstream ss;
  ss << "[" << this << "] NaiveStrategy";
  return ss.str();
}
