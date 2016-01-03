#include <iostream>
#include <cstdlib>
#include <errno.h>

#include <QApplication>

#include "QtBoardView.h"

int main(int argc, char **argv)
{
  QApplication app(argc, argv);

  QtBoardView *board = new QtBoardView(NULL);
  board->show();

  int rc = app.exec();

  if (0 != rc)
  {
    std::cerr << "Some error occured!" << std::endl;
    std::cerr << errno << std::endl;
  }

  return EXIT_SUCCESS;
}
