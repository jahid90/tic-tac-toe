#ifndef __QT_BOARD_VIEW_H__
#define __QT_BOARD_VIEW_H__

#include <QMainWindow>

#include "ui_board.h"

class GuiView;

class QtBoardView : public QMainWindow
{
  public:
    QtBoardView(GuiView * view, QMainWindow *parent = 0);

    static Ui::Board * uiboard() 
    {
      static Ui::Board board;

      return &board;
    }

    void setAllCellsEnabled(bool);

  private:
    GuiView * _view;

    void initSignalsAndSlots();
    void connectMessageDispatchWithCell();
    void connectCellClickWithHelper();
    void connectCellClickWithCellComponents();
    void setupCellsToUseScaledContents();
};

#endif // __QT_BOARD_VIEW_H__
