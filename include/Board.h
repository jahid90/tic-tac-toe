#ifndef __BOARD_H__
#define __BOARD_H__

#include "CommonIncludes.h"

#include "IBoardIterator.h"
#include "Cell.h"

enum class Piece;
class Player;

class Board
{
  public:
    Board();
    void populateWinningPatterns();
    Cell & cell(int, int);
    void setCell(Cell, int, int);
    bool hasWinner();
    bool isWinner(Player *);
    void onStateChanged(int, int);
    Player * winner();

    IBoardIterator & begin(IBoardIterator::Type);
    IBoardIterator & end(IBoardIterator::Type);

  private:
    std::vector< std::vector<Cell> > _cells;
    std::map< int, std::tuple< std::pair<int, int>, 
        std::pair<int, int>, std::pair<int, int> > > winningPatterns;
    Player * _winner;

    void debugPrintPiece(Piece);
};

bool operator==(Board lhs, Board rhs);

#endif // __BOARD_H__
