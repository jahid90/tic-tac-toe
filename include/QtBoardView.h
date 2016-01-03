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
    Ui::Board * board();

  private:
    Ui::Board * _board;

    void initSignalsAndSlots();
};

#endif // __QT_BOARD_VIEW_H__