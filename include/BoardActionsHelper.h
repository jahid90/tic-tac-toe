#ifndef __BOARD_ACTIONS_HELPER_H__
#define __BOARD_ACTIONS_HELPER_H__

class BoardActionsHelper
{
  public:
    BoardActionsHelper * instance();

  private:
    BoardActionsHelper();
    BoardActionsHelper * _instance;
};

#endif // __BOARD_ACTIONS_HELPER_H__