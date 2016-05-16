#ifndef __UTILS_H__
#define __UTILS_H__

#include "CommonIncludes.h"

enum class Piece;
class QPixmap;

extern const bool DEBUG;

std::string pieceToString(Piece);
QPixmap getIcon(Piece);

#endif // __UTILS_H__
