#ifndef __BOARD_H__
#define __BOARD_H__

#include "Cell.h"
#include "IBoardIterator.h"

enum class Piece;
class Player;

class Board
{
  public:
    Board();
    Board(Board *);
    ~Board();

    std::string toString();
    bool operator==(const Board &);

    Cell * cell(int, int);
    void placePiece(Cell *, Piece);
    bool hasWinner();
    Player * winner();
    void reset();
    bool hasBlankCell();
    Cell * nextBlankCell();
    int blankCellCount();

    class Observer
    {
      public:
        virtual void cellStateChanged(Cell *) = 0;
    };

    void registerStateObserver(Observer *);
    void unregisterStateObserver(Observer *);
    void notifyObservers(Cell *);

    IBoardIterator & begin();
    IBoardIterator & end();

  private:
    void populateWinningPatterns();
    bool isWinner(Player *);

    std::vector< std::vector<Cell> > _cells;
    std::set< std::tuple< std::pair<int, int>,
        std::pair<int, int>, std::pair<int, int> > > winningPatterns;
    Player * _winner;
    std::vector<Observer *> _observers;
};

#endif // __BOARD_H__
