#ifndef __GAME_H__
#define __GAME_H__

#include "CommonIncludes.h"

class Board;
class Player;
class IStrategy;
class IView;

class Game
{
  public:
    Game();
    std::string toString();

    static Game * instance()
    {
      static Game _instance;

      return &_instance;
    }
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
};

#endif // __GAME_H__
