#include "CommonIncludes.h"

#include <QApplication>
#include <QIcon>

#include "QtBoardView.h"
#include "Utils.h"
#include "Cell.h"
#include "Board.h"
#include "IBoardIterator.h"
#include "Game.h"

int main(int argc, char **argv)
{
  QApplication app(argc, argv);

  QIcon appIcon(":/images/icon");
  app.setWindowIcon(appIcon);

  QtBoardView *board = new QtBoardView(NULL);
  board->show();

  int rc = app.exec();

  if (0 != rc)
  {
    std::cerr << "Some error occured!" << std::endl;
    perror("error app.exec(): ");
  }

  nextEmptyCell( Game::instance()->board() );

  Board b;
  std::cerr << "returned cell: " << &(*IBoardIterator(b, 0, 2)) << std::endl;

  return EXIT_SUCCESS;
}
