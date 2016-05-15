#include "Board.h"

#include "BoardRowIterator.h"
#include "CommonIncludes.h"
#include "GameController.h"
#include "Piece.h"
#include "Player.h"
#include "QtBoardView.h"
#include "Utils.h"

/* Private Section */

void
Board::populateWinningPatterns()
{
  winningPatterns.insert( std::make_tuple( std::make_pair(1, 1)
      , std::make_pair(1, 2), std::make_pair(1, 3) ) );
  winningPatterns.insert( std::make_tuple( std::make_pair(2, 1)
      , std::make_pair(2, 2), std::make_pair(2, 3) ) );
  winningPatterns.insert( std::make_tuple( std::make_pair(3, 1)
      , std::make_pair(3, 2), std::make_pair(3, 3) ) );
  winningPatterns.insert( std::make_tuple( std::make_pair(1, 1)
      , std::make_pair(2, 1), std::make_pair(3, 1) ) );
  winningPatterns.insert( std::make_tuple( std::make_pair(1, 2)
      , std::make_pair(2, 2), std::make_pair(3, 2) ) );
  winningPatterns.insert( std::make_tuple( std::make_pair(1, 3)
      , std::make_pair(2, 3), std::make_pair(3, 3) ) );
  winningPatterns.insert( std::make_tuple( std::make_pair(1, 1)
      , std::make_pair(2, 2), std::make_pair(3, 3) ) );
  winningPatterns.insert( std::make_tuple( std::make_pair(1, 3)
      , std::make_pair(2, 2), std::make_pair(3, 1) ) );
}

bool
Board::isWinner(Player * player)
{
  if ( DEBUG ) std::cerr << "checking winner for: "
      << pieceToString( player->piece() ) << std::endl;

  for (auto itr = winningPatterns.begin(); itr != winningPatterns.end(); ++itr)
  {
    bool cellsHaveSamePiece = true;
    int r, c;

    r = std::get<0>(*itr).first;
    c = std::get<0>(*itr).second;
    cellsHaveSamePiece &= (player->piece() == cell(r, c)->piece());

    r = std::get<1>(*itr).first;
    c = std::get<1>(*itr).second;
    cellsHaveSamePiece &= (player->piece() == cell(r, c)->piece());

    r = std::get<2>(*itr).first;
    c = std::get<2>(*itr).second;
    cellsHaveSamePiece &= (player->piece() == cell(r, c)->piece());

    if (cellsHaveSamePiece)
    {
      _winner = player;

      return true;
    }
  }

  return false;
}

IBoardIterator &
Board::begin()
{
  IBoardIterator * iter = new BoardRowIterator(this, 1, 1);
  return *iter;
}

IBoardIterator &
Board::end()
{
  IBoardIterator * iter = new BoardRowIterator(this, 4, 1);
  return *iter;
}

/* Public Section */

Board::Board()
    : _winner(NULL)
{
  for (int i = 0; i < 3; ++i)
  {
    std::vector<Cell> c;
    for (int j = 0; j < 3; ++j)
    {
      c.push_back( Cell(i, j) );
    }
    _cells.push_back(c);
  }

  populateWinningPatterns();

  if ( DEBUG )
    std::cerr << "New Board created: " << toString() << std::endl;
}

Board::Board(Board * other)
{
  for (int i = 0; i < 3; ++i)
  {
    std::vector<Cell> c;
    for (int j = 0; j < 3; ++j)
    {
      Cell cell(i, j);
      cell.setPiece( other->cell(1 + i, 1 + j)->piece() );

      c.push_back( cell );
    }
    _cells.push_back(c);
  }

  populateWinningPatterns();

  if ( DEBUG )
    std::cerr << "Copy Board created: " << toString() << std::endl;
}

std::string
Board::toString()
{
  std::stringstream ss;
  ss << "[" << this << "]";
  return ss.str();
}

bool
Board::operator==(const Board & other)
{
  return this == &other;
}

Cell *
Board::cell(int r, int c)
{
  return &_cells[r - 1][c - 1];
}

void
Board::placePiece(Cell * cell, Piece piece)
{
  if ( !cell->isBlank() )
  {
    std::cout << "Can't place piece in an already occupied cell!" << std::endl;

    exit(1);
  }

  cell->setPiece( piece );

  notifyObservers(cell);
}

Player *
Board::winner()
{
  return _winner;
}

bool
Board::hasWinner()
{
  return isWinner( GameController::instance()->firstPlayer() ) 
      || isWinner( GameController::instance()->secondPlayer() );
}

bool
Board::hasBlankCell()
{
  for ( IBoardIterator &itr = begin()
      ; itr != end()
      ; ++itr )
  {
    if ( (*itr).isBlank() ) return true;
  }

  return false;
}

int
Board::blankCellCount()
{
  int ret = 0;

  for ( IBoardIterator &itr = begin()
      ; itr != end()
      ; ++itr )
  {
    if ( (*itr).isBlank() ) ++ret;
  }

  return ret;
}

/* call hasBlankCell() first */
Cell *
Board::nextBlankCell()
{
  for ( IBoardIterator &itr = begin()
      ; itr != end()
      ; ++itr )
  {
    if ( (*itr).isBlank() )
    {
      if ( DEBUG ) std::cerr << "found blank cell: " << (*itr).toString() << std::endl;
      return &(*itr);
    }
  }
  
  return NULL; // todo throw exception
}

void
Board::reset()
{
  for ( IBoardIterator &itr = begin()
      ; itr != end()
      ; ++itr )
  {
    (*itr).setPiece(Piece::BLANK);
  }
}

void
Board::registerStateObserver(Observer * observer)
{
  _observers.push_back( observer );
}

void
Board::unregisterStateObserver(Observer * observer)
{
  for (auto it = _observers.begin(); it != _observers.end(); ++it)
  {
    if ( *it == observer )
    {
      _observers.erase( it );
      break;
    }
  }
}

void
Board::notifyObservers(Cell * cell)
{
  for (auto it = _observers.begin(); it != _observers.end(); ++it)
  {
    (*it)->cellStateChanged(cell);
  }
}
