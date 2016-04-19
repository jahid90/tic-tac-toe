#include "CommonIncludes.h"

#include <QApplication>
#include <QIcon>

#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "Utils.h"
#include "QtBoardView.h"
#include "IView.h"

int main(int argc, char **argv)
{
  // QApplication app(argc, argv);

  // QIcon appIcon(":/images/icon");
  // app.setWindowIcon(appIcon);

  // QtBoardView *board = new QtBoardView(NULL);
  // board->show();

  // int rc = app.exec();

  Game *game = Game::instance();
  std::cerr << game->toString() << std::endl;

  game->view()->init(argc, argv);

  /*
  while ( true )
  {
    game->playTurn();

    if (game->hasWinner())
    {
      std::cout << "We have a winner!" << std::endl;
      std::cerr << pieceToString(game->board()->winner()->piece())
          << " is the winner!!" << std::endl;

      // setAllCellsEnabled( false, QtBoardView::board() );

      break;
    }
    else
    {
      std::cerr << "No winner yet" << std::endl;
    }
  }
  */

  // if (0 != rc)
  // {
    // std::cerr << "Some error occured!" << std::endl;
    // perror("error app.exec(): ");
  // }

  return EXIT_SUCCESS;
}
