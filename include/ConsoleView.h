#ifndef __CONSOLE_VIEW_H__
#define __CONSOLE_VIEW_H__

#include "IView.h"

class ConsoleView : public IView
{
  public:
    ConsoleView();
    void init();
    void reset();
    void markCell(int, int, Piece);
    void clearCell(int, int);
    void setStatusMessage(std::string);
    void waitForMove();
    void freezeView();

  private:
};

#endif  // __CONSOLE_VIEW_H__
