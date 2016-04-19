#ifndef __IVIEWS_H__
#define __IVIEWS_H__

#include "CommonIncludes.h"

enum class Piece;

class IView
{
  public:
    virtual void init(int, char **) = 0;
    virtual void reset() = 0;
    virtual void markCell(int, int, Piece) = 0;
    virtual void clearCell(int, int) = 0;
    virtual void setStatusMessage(std::string) = 0;
};

#endif // __IVIEWS_H__
