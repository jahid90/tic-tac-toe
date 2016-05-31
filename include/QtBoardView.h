#ifndef __QT_BOARD_VIEW_H__
#define __QT_BOARD_VIEW_H__

#include <QMainWindow>

namespace Ui
{
  class Board;
}

class GuiView;
class BoardActionsHelper;

class QtBoardView : public QMainWindow
{
  public:
    QtBoardView(QMainWindow *parent = 0);
    ~QtBoardView();

    static Ui::Board * uiboard();

    void setAllCellsEnabled(bool);

  private:
    static Ui::Board * _board;

    BoardActionsHelper * _helper;

    void initSignalsAndSlots();
    void connectMessageDispatchWithCell();
    void connectCellClickWithHelper();
    void connectCellClickWithCellComponents();
    void setupCellsToUseScaledContents();
};

#endif // __QT_BOARD_VIEW_H__
