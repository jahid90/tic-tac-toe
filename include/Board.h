#ifndef __BOARD_H__
#define __BOARD_H__

#include "CommonIncludes.h"

#include "IBoardIterator.h"

class Cell;
enum class Piece;
class Player;

class Board
{
  public:
    Board();
    void populateWinningPatterns();
    Cell * cell(int, int);
    void setCell(Cell *, int, int);
    bool hasWinner();
    bool isWinner(Player *);
    void onStateChanged(int, int);
    Player * winner();

    IBoardIterator * begin(IBoardIterator::Type);
    IBoardIterator * end(IBoardIterator::Type);

  private:
    int _ROW;
    int _COL;
    Cell *** _cells;
    std::map< int, std::tuple< std::pair<int, int>, 
        std::pair<int, int>, std::pair<int, int> > > winningPatterns;
    Player * _winner;

    void debugPrintPiece(Piece);
};

#endif // __BOARD_H__
