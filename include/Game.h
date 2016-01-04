#ifndef __GAME_H__
#define __GAME_H__

class Board;
class Player;

class Game
{
  public:
    Game();
    static Game * instance()
    {
      static Game _instance;

      return &_instance;
    }
    Board * board();
    Player * firstPlayer();
    Player * secondPlayer();

  private:
    Board * _board;
    Player * _firstPlayer;
    Player * _secondPlayer;
};

#endif // __GAME_H__
