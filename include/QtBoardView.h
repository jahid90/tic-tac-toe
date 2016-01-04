#ifndef __QT_BOARD_VIEW_H__
#define __QT_BOARD_VIEW_H__

#include <QMainWindow>
#include "ui_board.h"

class QtBoardView : public QMainWindow
{
  public:
    QtBoardView(QMainWindow *parent = 0);
    static Ui::Board * board() 
    {
      static Ui::Board board;

      return &board;
    }

  private:
    void initSignalsAndSlots();
    void connectMessageDispatchWithCell();
    void connectCellClickWithHelper();
    void setupCellsToUseScaledContents();
};

#endif // __QT_BOARD_VIEW_H__
