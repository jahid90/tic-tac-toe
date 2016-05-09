#include "HumanStrategy.h"

#include "Cell.h"

#include "Board.h"
#include "GameController.h"
#include "IView.h"

void
HumanStrategy::getNextBestMoveFor(Player * player, Board * board)
{
  GameController::instance()->view()->waitForMove();
}

std::string
HumanStrategy::toString()
{
  std::stringstream ss;
  ss << "[" << this << "] HumanStrategy";
  return ss.str();
}
