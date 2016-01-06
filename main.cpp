#include "CommonIncludes.h"

#include <QApplication>
#include <QIcon>

#include "QtBoardView.h"
#include "Utils.h"
#include "Cell.h"
#include "Piece.h"
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

  return EXIT_SUCCESS;
}
