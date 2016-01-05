#include "Cell.h"
#include "Player.h"
#include "Game.h"
#include "Piece.h"
#include "QtBoardView.h"
#include "Utils.h"

#include "Board.h"

Board::Board()
    : _ROW(3), _COL(3),
    _winner(NULL)
{
  _cells = new Cell ** [_ROW];
  for (int i = 0; i < _ROW; ++i)
    _cells[i] = new Cell * [_COL];

  for (int r = 0; r < _ROW; ++r)
    for (int c = 0; c < _COL; ++c)
      _cells[r][c] = new Cell(this, r, c);

  populateWinningPatterns();
}

void
Board::populateWinningPatterns()
{
  // 0-based indexing! - 1-based everywhere else, careful!!
  winningPatterns.insert( make_pair( 1, std::make_tuple( std::make_pair(0, 0)
      , std::make_pair(0, 1), std::make_pair(0, 2) ) ) );
  winningPatterns.insert( make_pair( 2, std::make_tuple( std::make_pair(1, 0)
      , std::make_pair(1, 1), std::make_pair(1, 2) ) ) );
  winningPatterns.insert( make_pair( 3, std::make_tuple( std::make_pair(2, 0)
      , std::make_pair(2, 1), std::make_pair(2, 2) ) ) );
  winningPatterns.insert( make_pair( 4, std::make_tuple( std::make_pair(0, 0)
      , std::make_pair(1, 0), std::make_pair(2, 0) ) ) );
  winningPatterns.insert( make_pair( 5, std::make_tuple( std::make_pair(0, 1)
      , std::make_pair(1, 1), std::make_pair(2, 1) ) ) );
  winningPatterns.insert( make_pair( 6, std::make_tuple( std::make_pair(0, 2)
      , std::make_pair(1, 2), std::make_pair(2, 2) ) ) );
  winningPatterns.insert( make_pair( 7, std::make_tuple( std::make_pair(0, 0)
      , std::make_pair(1, 1), std::make_pair(2, 2) ) ) );
  winningPatterns.insert( make_pair( 8, std::make_tuple( std::make_pair(0, 2)
      , std::make_pair(1, 1), std::make_pair(2, 0) ) ) );
}

Cell *
Board::cell(int r, int c)
{
  --r; --c;

  return _cells[r][c];
}

void
Board::setCell(Cell * cell, int r, int c)
{
  --r; --c;

  _cells[r][c] = cell;
}

Player *
Board::winner()
{
  return _winner;
}

bool
Board::hasWinner()
{
  return isWinner( Game::instance()->firstPlayer() ) 
      || isWinner( Game::instance()->secondPlayer() );
}

bool
Board::isWinner(Player * player)
{
  std::cerr << "checking winner for: ";
  debugPrintPiece(player->piece());
  std::cerr << std::endl;

  for (auto itr = winningPatterns.begin(); itr != winningPatterns.end(); ++itr)
  {
    bool winner = true;
    int r, c;

    r = 1 + std::get<0>(itr->second).first;
    c = 1 + std::get<0>(itr->second).second;
    winner &= (player->piece() == cell(r, c)->piece());

    r = 1 + std::get<1>(itr->second).first;
    c = 1 + std::get<1>(itr->second).second;
    winner &= (player->piece() == cell(r, c)->piece());

    r = 1 + std::get<2>(itr->second).first;
    c = 1 + std::get<2>(itr->second).second;
    winner &= (player->piece() == cell(r, c)->piece());

    if (winner)
    {
      _winner = player;

      return true;
    }
  }

  return false;
}

void
Board::onStateChanged(int r, int c)
{
  std::cerr << std::endl;
  for (int r = 0; r < _ROW; ++r)
  {
    for (int c = 0; c < _COL; c++)
    {
      debugPrintPiece( cell(1 + r, 1 + c)->piece() );
    }
    std::cerr << std::endl;
  }

  std::cerr << "content of [" << r << ", " << c << "] changed" << std::endl;

  if (hasWinner())
  {
    std::cout << "We have a winner!" << std::endl;
    debugPrintPiece(winner()->piece());
    std::cerr << "is the winner!!" << std::endl;

    setAllCellsEnabled( false, QtBoardView::board() );
  }
  else
  {
    std::cerr << "No winner yet" << std::endl;
  }
}

IBoardIterator *
Board::begin(IBoardIterator::Type type)
{
  if (IBoardIterator::Type::ROW == type)
    return IBoardIterator::rowMajorBegin(this);

  if (IBoardIterator::Type::COL == type)
    return IBoardIterator::columnMajorBegin(this);

  return NULL;
}

IBoardIterator *
Board::end(IBoardIterator::Type type)
{
  if (IBoardIterator::Type::ROW == type)
    return IBoardIterator::rowMajorEnd(this);

  if (IBoardIterator::Type::COL == type)
    return IBoardIterator::columnMajorEnd(this);

  return NULL;
}

void
Board::debugPrintPiece(Piece p)
{
  const std::string sym[] {"X", "O", "-"};
  std::cerr << sym[(int) p] << " ";
}
