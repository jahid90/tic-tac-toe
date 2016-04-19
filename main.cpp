#include "CommonIncludes.h"
#include "GlobalConstants.h"
#include "GuiView.h"

#include "GameController.h"

int main(int argc, char **argv)
{
  GuiView::initParams(argc, argv);

  GameController *game = GameController::instance();

  game->playGame();

  return EXIT_SUCCESS;
}
