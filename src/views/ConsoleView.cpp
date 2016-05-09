#include "ConsoleView.h"

#include "CommonIncludes.h"

#include "GameController.h"
#include "Board.h"
#include "Utils.h"

void renderView(Board * board)
{
  std::cout << std::endl;
  for (int i = 1; i < 4; ++i)
  {
    for (int j = 1; j < 4; ++j)
    {
      std::cout << pieceToString( board->cell(i, j).piece() ) << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

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
  renderView( GameController::instance()->board() );
}

void
ConsoleView::markCell(int row, int col, Piece piece)
{
  if ( DEBUG ) std::cerr << "received change event (" << row << ", " << col << ")" << std::endl;
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
  std::cout << "##Game:: " << msg << std::endl;
}

void
ConsoleView::waitForMove()
{
  std::cout << "##Enter your move(r c): ";
  int r, c; std::cin >> r >> c;

  if ( r < 1 || r > 3 || c < 1 || c > 3 )
  {
    std::cerr << "error! requested next move with invalid index(es)." << std::endl;

    return; // throw exception
  }
  
  notify(r, c);
}
