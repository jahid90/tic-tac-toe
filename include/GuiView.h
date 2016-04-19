#ifndef __GUI_VIEW_H__
#define __GUI_VIEW_H__

#include "IView.h"

class QApplication;
class QtBoardView;

class GuiView : public IView
{
  public:
    void init(int, char **);
    void reset();
    void markCell(int, int, Piece);
    void clearCell(int, int);
    void setStatusMessage(std::string);

  private:
    QApplication * _app;
    QtBoardView * _guiBoard;
};

#endif // __GUI_VIEW_H__
