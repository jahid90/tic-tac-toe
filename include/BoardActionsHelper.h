#ifndef __BOARD_ACTIONS_HELPER_H__
#define __BOARD_ACTIONS_HELPER_H__

#include <QObject>

class BoardActionsHelper : public QObject
{
  Q_OBJECT
  public:
    static BoardActionsHelper * instance() { 
      static BoardActionsHelper instance;

      return &instance; 
    }

  private:

  public slots:
    void clearBoard();
};

#endif // __BOARD_ACTIONS_HELPER_H__