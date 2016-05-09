#include "CommonIncludes.h"

#include "GuiView.h"
#include "GameController.h"
#include "ArgumentsParser.h"

int main(int argc, char **argv)
{
  ArgumentsParser::instance()->init(argc, argv);

  GameController *game = GameController::instance();
  game->init();

  game->playGame();

  return EXIT_SUCCESS;
}
