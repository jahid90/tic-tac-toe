#ifndef __BOARD_ACTIONS_HELPER_H__
#define __BOARD_ACTIONS_HELPER_H__

#include <QMap>
#include <QObject>
#include <QPair>
#include <QPixmap>

#include "Piece.h"

class QString;
class IView;

class BoardActionsHelper : public QObject
{
  Q_OBJECT
  public:
    BoardActionsHelper(QObject *parent = NULL);
    ~BoardActionsHelper();

    static BoardActionsHelper * instance();
    static void nullify();

    void markCell(int, int, Piece);
    void clearBoard();
    void init(IView *);

  private:
    void cellClicked(int, int, QPixmap);
    void markCell(int, int, QPixmap);

    QMap<QString, QPair<int, int> > cellMap;
    IView * _backingView;

    static BoardActionsHelper * _instance;

  signals:
    void setContent11(QPixmap);
    void setContent12(QPixmap);
    void setContent13(QPixmap);
    void setContent21(QPixmap);
    void setContent22(QPixmap);
    void setContent23(QPixmap);
    void setContent31(QPixmap);
    void setContent32(QPixmap);
    void setContent33(QPixmap);

  public slots:
    void clear();
    void cellClicked();
};

#endif // __BOARD_ACTIONS_HELPER_H__
