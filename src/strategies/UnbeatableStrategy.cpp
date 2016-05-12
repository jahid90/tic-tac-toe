#include "UnbeatableStrategy.h"

#include "Board.h"
#include "Player.h"
#include "GameController.h"
#include "Utils.h"
#include "CommonIncludes.h"

void debugView(Board * board)
{
  std::cerr << board->toString() << std::endl;

  std::cerr << std::endl;
  for (int i = 1; i < 4; ++i)
  {
    for (int j = 1; j < 4; ++j)
    {
      std::cerr << pieceToString( board->cell(i, j).piece() ) << " ";
    }
    std::cerr << std::endl;
  }
  std::cerr << std::endl;
}

void
Config::buildTree()
{
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      Cell cell = _board->cell(1 + i, 1 + j);

      if ( !cell.isBlank() )
      {
        _child[ i * 3 + j ] = NULL;
      }
      else
      {
        Board * copy = new Board(_board);
        copy->cell(1 + i, 1 + j).setPiece( _maximize 
            ? GameController::instance()->firstPlayer()->piece()
            : GameController::instance()->secondPlayer()->piece() );

        if ( DEBUG )
          std::cerr << "adding child: " << std::endl;
        if ( DEBUG )
          debugView(copy);

        _child[ i * 3 + j ] = new Config(copy, !_maximize);
        _child[ i * 3 + j ]->buildTree();
      }
    }
  }
}

Config::Config(Board * board, bool maximize)
    : _board(board)
    , _maximize(maximize)
{
  _child = new Config*[9];
  _score = INT_MIN;
  _cell = NULL;
}

Cell *
Config::bestCell()
{
  return _cell;
}

int
Config::score()
{
  if ( _score != INT_MIN ) return _score;

  if ( _board->hasWinner() )
  {
    int val = 1 + _board->blankCellCount();

    Player * firstPlayer = GameController::instance()->firstPlayer();
    Player * winner = _board->winner();

    if ( firstPlayer == winner ) 
    {
      _score = val;
      return val;
    }

    _score = -1 * val;
    return -1 * val;
  }

  if ( !_board->hasBlankCell() )
  {
    _score = 0;
    return 0;
  }

  int val = _maximize ? INT_MIN : INT_MAX;

  for (int i = 0; i < 9; ++i)
  {
    if ( NULL != _child[i] )
    {
      int childScore = _child[i]->score();

      val = _maximize ? std::max(val, childScore) : std::min(val, childScore);

      int r = i / 3;
      int c = i % 3;
      if ( val == childScore ) _cell = &_board->cell(1 + r, 1 + c);
    }
  }

  _score = val;
  return val;
}

Cell *
UnbeatableStrategy::minimax(Board * board, bool maximize)
{
  Config * root = new Config(board, maximize);
  root->buildTree();

  int score = root->score();

  if ( DEBUG )
    std::cerr << "best score achievable: " << score << std::endl;

  return root->bestCell();
}

void
UnbeatableStrategy::requestNextBestMoveOn(Board * board)
{
  if ( DEBUG )
    std::cerr << "Thinking..." << std::endl;

  Cell * bestMove = minimax(board, true);

  std::string msg = "AI's move is: ";
  msg += (char)( '0' + bestMove->x() + 1 );
  msg += " ";
  msg += (char)( '0' + bestMove->y() + 1 );
  GameController::instance()->view()->setStatusMessage( msg );

  GameController::instance()->view()->notify( bestMove->x() + 1, bestMove->y() + 1 );
}

std::string
UnbeatableStrategy::toString()
{
  std::stringstream ss;
  ss << "[" << this << "] UnbeatableStrategy - Powered by Minimax";
  return ss.str();
}
