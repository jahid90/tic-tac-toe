#include "CommonIncludes.h"

#include "BoardActionsHelper.h"

BoardActionsHelper::BoardActionsHelper()
{
}

BoardActionsHelper * BoardActionsHelper::instance()
{
  if (NULL == _instance)
    _instance = new BoardActionsHelper();

  return _instance;
}
