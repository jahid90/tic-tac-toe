#ifndef __BOARD_ACTIONS_HELPER_H__
#define __BOARD_ACTIONS_HELPER_H__

#include <QObject>
#include <QMap>
#include <QPair>
#include <QPixmap>

#include "Piece.h"

class QString;

class BoardActionsHelper : public QObject
{
  Q_OBJECT
  public:
    BoardActionsHelper(QObject *parent = NULL);

    static BoardActionsHelper * instance()
    {
      if ( NULL == _instance )
      {
        _instance = new BoardActionsHelper;
      }

      return _instance; 
    }

    void markCell(int, int, Piece);
    void clearBoard();

  private:
    QMap<QString, QPair<int, int> > cellMap;
    void cellClicked(int, int, QPixmap);
    void markCell(int, int, QPixmap);

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
