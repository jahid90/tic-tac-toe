#include "ConsoleView.h"

#include "CommonIncludes.h"

#include "GameController.h"
#include "Board.h"
#include "Utils.h"

ConsoleView::ConsoleView()
{
}

void
ConsoleView::init()
{
  std::cout << "game view initialized." << std::endl;
}

void
ConsoleView::reset()
{

}

void renderView(Board * board)
{
  for (int i = 1; i < 4; ++i)
  {
    for (int j = 1; j < 4; ++j)
    {
      std::cout << pieceToString( board->cell(i, j).piece() ) << " ";
    }
    std::cout << std::endl;
  }
}

void
ConsoleView::markCell(int, int, Piece)
{
  renderView( GameController::instance()->board() );
}

void
ConsoleView::clearCell(int, int)
{
  renderView( GameController::instance()->board() );
}

void
ConsoleView::setStatusMessage(std::string msg)
{
  std::cout << "  Game:: " << msg << std::endl;
}
