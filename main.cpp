#include "ArgumentsParser.h"
#include "GameController.h"

int main(int argc, char **argv)
{
  ArgumentsParser::instance()->init(argc, argv);

  GameController::instance()->init();

  GameController::nullify();

  ArgumentsParser::nullify();

  return EXIT_SUCCESS;
}
