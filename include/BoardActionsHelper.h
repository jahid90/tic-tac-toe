#ifndef __BOARD_ACTIONS_HELPER_H__
#define __BOARD_ACTIONS_HELPER_H__

#include <QObject>
#include <QMap>
#include <QPair>
#include <QPixmap>

class BoardActionsHelper : public QObject
{
  Q_OBJECT
  public:
    BoardActionsHelper(QObject *parent = 0);
    static BoardActionsHelper * instance() { 
      static BoardActionsHelper instance;

      return &instance; 
    }

  private:
    QMap<QString, QPair<int, int> > cellMap;
    void markCell(int, int, QPixmap);

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
    void clearBoard();
    void markCell();
};

#endif // __BOARD_ACTIONS_HELPER_H__
