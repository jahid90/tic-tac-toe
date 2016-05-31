#ifndef __GUI_VIEW_H__
#define __GUI_VIEW_H__

#include "IView.h"

class QApplication;
class QtBoardView;
class BoardActionsHelper;

class GuiView : public IView
{
  public:
    void init();
    void reset();
    void markCell(int, int, Piece);
    void clearCell(int, int);
    void setStatusMessage(std::string);
    void waitForMove();
    void freezeView();

    ~GuiView();
    GuiView();

  private:
    QApplication * _app;
    QtBoardView * _guiBoard;
    BoardActionsHelper * _helper;
};

#endif // __GUI_VIEW_H__
