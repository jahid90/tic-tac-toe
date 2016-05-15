#include "ArgumentsParser.h"
#include "CommonIncludes.h"
#include "GameController.h"

int main(int argc, char **argv)
{
  ArgumentsParser::instance()->init(argc, argv);

  GameController::instance()->init();

  return EXIT_SUCCESS;
}
