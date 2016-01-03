#ifndef __QT_BOARD_VIEW_H__
#define __QT_BOARD_VIEW_H__

#include <QMainWindow>

namespace Ui 
{
  class Board;
}

class QtBoardView : public QMainWindow
{
  public:
    QtBoardView(QMainWindow *parent = 0);
    virtual ~QtBoardView();

  private:
    Ui::Board *board;
};

#endif // __QT_BOARD_VIEW_H__