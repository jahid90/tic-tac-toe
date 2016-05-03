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
    std::string toString();

    Cell & cell(int, int);
    void placePiece(Cell *, Piece);
    bool hasWinner();
    Player * winner();
    bool hasBlankCell();
    Cell * nextBlankCell();
    void reset();

  private:
    void populateWinningPatterns();
    bool isWinner(Player *);

    IBoardIterator & begin(IBoardIterator::Type);
    IBoardIterator & end(IBoardIterator::Type);

    std::vector< std::vector<Cell> > _cells;
    std::map< int, std::tuple< std::pair<int, int>, 
        std::pair<int, int>, std::pair<int, int> > > winningPatterns;
    Player * _winner;
};

bool operator==(Board lhs, Board rhs);

#endif // __BOARD_H__
