#ifndef __IVIEWS_H__
#define __IVIEWS_H__

#include "CommonIncludes.h"

enum class Piece;

class IView
{
  public:
    IView();

    virtual void init() = 0;
    virtual void reset() = 0;
    virtual void markCell(int, int, Piece) = 0;
    virtual void clearCell(int, int) = 0;
    virtual void setStatusMessage(std::string) = 0;

    class Listener
    {
      public:
        virtual void cellSelected(int, int) = 0;
    };

    void attachListener(Listener *);
    void detachlistener();
    void notify(int, int);

  private:
    Listener * _listener;
};

#endif // __IVIEWS_H__
