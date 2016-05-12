#include "Board.h"

#include "CommonIncludes.h"

#include "Player.h"
#include "GameController.h"
#include "Piece.h"
#include "Utils.h"
#include "BoardRowIterator.h"
#include "BoardColumnIterator.h"
#include "QtBoardView.h"

/* Private Section */

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

bool
Board::isWinner(Player * player)
{
  if ( DEBUG ) std::cerr << "checking winner for: "
      << pieceToString( player->piece() ) << std::endl;

  for (auto itr = winningPatterns.begin(); itr != winningPatterns.end(); ++itr)
  {
    bool winner = true;
    int r, c;

    r = 1 + std::get<0>(itr->second).first;
    c = 1 + std::get<0>(itr->second).second;
    winner &= (player->piece() == cell(r, c).piece());

    r = 1 + std::get<1>(itr->second).first;
    c = 1 + std::get<1>(itr->second).second;
    winner &= (player->piece() == cell(r, c).piece());

    r = 1 + std::get<2>(itr->second).first;
    c = 1 + std::get<2>(itr->second).second;
    winner &= (player->piece() == cell(r, c).piece());

    if (winner)
    {
      _winner = player;

      return true;
    }
  }

  return false;
}


IBoardIterator &
Board::begin(IBoardIterator::Type type)
{
  static BoardRowIterator &rItr = IBoardIterator::rowMajorBegin( *this );
  static BoardColumnIterator &cItr = IBoardIterator::columnMajorBegin( *this );

  rItr.reset();
  cItr.reset();
  
  if (IBoardIterator::Type::ROW == type)
    return rItr;

  if (IBoardIterator::Type::COL == type)
    return cItr;

  return rItr;  // row iter by default, todo throw exception
}

IBoardIterator &
Board::end(IBoardIterator::Type type)
{
  static BoardRowIterator &rItr = IBoardIterator::rowMajorEnd( *this );
  static BoardColumnIterator &cItr = IBoardIterator::columnMajorEnd( *this );
  
  if (IBoardIterator::Type::ROW == type)
    return rItr;

  if (IBoardIterator::Type::COL == type)
    return cItr;

  return rItr;  // row iter by default, todo throw exception
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
      cell.setPiece( other->cell(1 + i, 1 + j).piece() );

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

Cell &
Board::cell(int r, int c)
{
  --r; --c;

  return _cells[r][c];
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
  /*
  for ( IBoardIterator &itr = begin( IBoardIterator::Type::ROW )
      ; itr != end( IBoardIterator::Type::ROW )
      ; ++itr )
  {
    if ( (*itr).isBlank() ) return true;
  }
  */

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
  {
    if ( cell(1 + i, 1 + j).isBlank() ) return true;
  }

  return false;
}

int
Board::blankCellCount()
{
  int ret = 0;

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
  {
    if ( cell(1 + i, 1 + j).isBlank() ) ++ret;
  }

  return ret;
}

/* call hasBlankCell() first */
Cell *
Board::nextBlankCell()
{
  for ( IBoardIterator &itr = begin( IBoardIterator::Type::ROW )
      ; itr != end( IBoardIterator::Type::ROW )
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
  for ( IBoardIterator &itr = begin( IBoardIterator::Type::COL )
      ; itr != end( IBoardIterator::Type::COL )
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
