#include "HumanStrategy.h"

#include "Board.h"
#include "Cell.h"
#include "GameController.h"
#include "IView.h"

void
HumanStrategy::requestNextBestMoveOn(Board *)
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
