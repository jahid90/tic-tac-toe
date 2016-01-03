#include "CommonIncludes.h"

#include "ui_board.h"
#include "BoardActionsHelper.h"

#include "QtBoardView.h"

QtBoardView::QtBoardView(QMainWindow *parent)
    : QMainWindow(parent)
{
  board()->setupUi(this);

  initSignalsAndSlots();
}

void 
QtBoardView::initSignalsAndSlots()
{
  connect( board()->btnQuit, SIGNAL (clicked()), 
      QApplication::instance(), SLOT (quit()) );

  connect( board()->btnClear, SIGNAL (clicked()), 
      BoardActionsHelper::instance(), SLOT (clearBoard()) );

  connect( BoardActionsHelper::instance(), SIGNAL (setText11(QString)),
      board()->cell_11, SLOT (setText(QString)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setText12(QString)),
      board()->cell_12, SLOT (setText(QString)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setText13(QString)),
      board()->cell_13, SLOT (setText(QString)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setText21(QString)),
      board()->cell_21, SLOT (setText(QString)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setText22(QString)),
      board()->cell_22, SLOT (setText(QString)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setText23(QString)),
      board()->cell_23, SLOT (setText(QString)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setText31(QString)),
      board()->cell_31, SLOT (setText(QString)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setText32(QString)),
      board()->cell_32, SLOT (setText(QString)) );
  connect( BoardActionsHelper::instance(), SIGNAL (setText33(QString)),
      board()->cell_33, SLOT (setText(QString)) );

  connect( board()->cell_11, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (markCell()) );
  connect( board()->cell_12, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (markCell()) );
  connect( board()->cell_13, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (markCell()) );
  connect( board()->cell_21, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (markCell()) );
  connect( board()->cell_22, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (markCell()) );
  connect( board()->cell_23, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (markCell()) );
  connect( board()->cell_31, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (markCell()) );
  connect( board()->cell_32, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (markCell()) );
  connect( board()->cell_33, SIGNAL (clicked()),
      BoardActionsHelper::instance(), SLOT (markCell()) );
}
