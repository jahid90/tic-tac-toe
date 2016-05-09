#ifndef __GUI_VIEW_H__
#define __GUI_VIEW_H__

#include "IView.h"

class QApplication;
class QtBoardView;

class GuiView : public IView
{
  public:
    void init();
    void reset();
    void markCell(int, int, Piece);
    void clearCell(int, int);
    void setStatusMessage(std::string);
    void waitForMove();

    static void initParams(int argc, char ** argv);

  private:
    static int _argc;
    static char ** _argv;
    QApplication * _app;
    QtBoardView * _guiBoard;
};

#endif // __GUI_VIEW_H__
