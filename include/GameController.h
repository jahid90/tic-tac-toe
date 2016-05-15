#ifndef __GAME_CONTROLLER_H__
#define __GAME_CONTROLLER_H__

#include "Board.h"
#include "CommonIncludes.h"
#include "IView.h"

class Player;
class IStrategy;

class GameController : public Board::Observer, public IView::Listener
{
  public:
    std::string toString();

    static GameController * instance();

    Board * board();
    Player * firstPlayer();
    Player * secondPlayer();
    Player * currentPlayer();
    IView * view();

    void init();
    void reset();
    bool hasWinner();
    
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
    bool isBoardFull();
    void playTurn();
    void makeMove();
    void switchPlayers();
    void setCurrentPlayer(Player *);
    void randomizeCurrentPlayer();
};

#endif // __GAME_CONTROLLER_H__
