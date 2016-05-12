#ifndef __GAME_CONTROLLER_H__
#define __GAME_CONTROLLER_H__

#include "CommonIncludes.h"
#include "Board.h"
#include "IView.h"

class Player;
class IStrategy;

class GameController : public Board::Observer, public IView::Listener
{
  public:
    std::string toString();

    static GameController * instance()
    {
      if ( NULL == _instance )
      {
        _instance = new GameController;
      }

      return _instance;
    }

    void init();
    void playGame();

    Board * board();
    Player * firstPlayer();
    Player * secondPlayer();
    Player * currentPlayer();
    void setCurrentPlayer(Player *);
    void setRandomCurrentPlayer();
    IView * view();

    bool hasWinner();
    void playTurn();

    void cellStateChanged(Cell *);
    void cellSelected(int, int);

  private:
    GameController();

    static GameController * _instance;

    Board * _board;
    Player * _firstPlayer;
    Player * _secondPlayer;
    Player * _currentPlayer;
    IView * _view;

    void initComponents();
    void switchPlayers();
    bool isBoardFull();
};

#endif // __GAME_CONTROLLER_H__
