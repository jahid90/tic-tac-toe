#ifndef __GAME_CONTROLLER_H__
#define __GAME_CONTROLLER_H__

#include "CommonIncludes.h"

class Board;
class Player;
class IStrategy;
class IView;

class GameController
{
  public:
    GameController();
    std::string toString();

    static GameController * instance()
    {
      static GameController _instance;

      return &_instance;
    }

    void playGame();

    Board * board();
    Player * firstPlayer();
    Player * secondPlayer();
    Player * currentPlayer();
    void setCurrentPlayer(Player *);
    IView * view();

    bool hasWinner();
    void playTurn();

  private:
    Board * _board;
    Player * _firstPlayer;
    Player * _secondPlayer;
    Player * _currentPlayer;
    IView * _view;

    void switchPlayers();
    bool isBoardFull();
};

#endif // __GAME_CONTROLLER_H__
