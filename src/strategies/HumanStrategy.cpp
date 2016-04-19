#include "HumanStrategy.h"

#include "Cell.h"

#include "Board.h"

Cell *
HumanStrategy::getNextBestMoveFor(Player * player, Board * board)
{
  std::cout << "Enter your move: ";
  int r, c; std::cin >> r >> c;

  if (r == -1 && c == -1)
  {
    std::cerr << "error! requested next move when no blank cell left on board." << std::endl;

    return NULL; // throw exception
  }
  else
  {
    return  &board->cell(r, c);
  }
}

std::string
HumanStrategy::toString()
{
  std::stringstream ss;
  ss << "[" << this << "] HumanStrategy";
  return ss.str();
}
