#include "IView.h"

IView::IView()
{
  _listener = NULL;
}

void
IView::attachListener(Listener * listener)
{
  if ( NULL != _listener ) return;

  _listener = listener;
}

void
IView::detachlistener()
{
  _listener = NULL;
}

void
IView::notify(int r, int c)
{
  if ( NULL != _listener ) _listener->cellSelected(r, c);
}
