#ifndef __BOARD_ACTIONS_HELPER_H__
#define __BOARD_ACTIONS_HELPER_H__

#include <QObject>
#include <QMap>
#include <QPair>

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
    void markCell(int r, int c, QString text);

  signals:
    void setText(QString text);
    void setText11(QString);
    void setText12(QString);
    void setText13(QString);
    void setText21(QString);
    void setText22(QString);
    void setText23(QString);
    void setText31(QString);
    void setText32(QString);
    void setText33(QString);

  public slots:
    void clearBoard();
    void markCell();
};

#endif // __BOARD_ACTIONS_HELPER_H__
