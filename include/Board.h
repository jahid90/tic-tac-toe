#ifndef __BOARD_H__
#define __BOARD_H__

#include "CommonIncludes.h"

class Cell;
enum class Piece;

class Board
{
  public:
    Board();
    Cell * cell(int, int);
    void setCell(Cell*, int, int);
    bool hasWinner();
    bool isWinner(Player*);
    void onStateChanged(int, int);
    Player * winner();

  private:
    int _ROW;
    int _COL;
    Cell *** _cells;
    std::map< int, std::tuple< std::pair<int, int>, 
        std::pair<int, int>, std::pair<int, int> > > winningPatterns;
    Player *_winner;

    void debugPrintPiece(Piece);
};

#endif // __BOARD_H__
