#include "Utils.h"

#include "Piece.h"

#include <QPixmap>

const bool DEBUG = false;

std::string pieceToString(Piece p)
{
  return (Piece::CROSS == p)
      ? "X" 
      : (Piece::OH == p)
          ? "O"
          : "-";
}

QPixmap
getIcon(Piece p)
{
  if (p == Piece::CROSS)
    return QPixmap(":/images/x");

  if (p == Piece::OH)
    return QPixmap(":/images/o");

  return QPixmap(":/images/blank");
}
