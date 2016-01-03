#include "CommonIncludes.h"

#include <QObject>

#include "Utils.h"
#include "QtBoardView.h"

#include "BoardActionsHelper.h"

BoardActionsHelper::BoardActionsHelper(QObject *parent)
    : QObject(parent)
{
  cellMap.insert("cell_11", qMakePair(1, 1));
  cellMap.insert("cell_12", qMakePair(1, 2));
  cellMap.insert("cell_13", qMakePair(1, 3));
  cellMap.insert("cell_21", qMakePair(2, 1));
  cellMap.insert("cell_22", qMakePair(2, 2));
  cellMap.insert("cell_23", qMakePair(2, 3));
  cellMap.insert("cell_31", qMakePair(3, 1));
  cellMap.insert("cell_32", qMakePair(3, 2));
  cellMap.insert("cell_33", qMakePair(3, 3));
}

void
BoardActionsHelper::clearBoard()
{
  QString emptyString("");

  emit setText11(emptyString);
  emit setText12(emptyString);
  emit setText13(emptyString);
  emit setText21(emptyString);
  emit setText22(emptyString);
  emit setText23(emptyString);
  emit setText31(emptyString);
  emit setText32(emptyString);
  emit setText33(emptyString);
}

void
BoardActionsHelper::markCell()
{
  QString senderName = sender()->objectName();

  QString crossString("X");

  int r = cellMap[senderName].first;
  int c = cellMap[senderName].second;

  markCell(r, c, crossString);
}

void
BoardActionsHelper::markCell(int r, int c, QString text)
{
  switch(r)
  {
    case 1:
      switch(c)
      {
        case 1:
          emit setText11(text);
          break;

        case 2:
          emit setText12(text);
          break;

        case 3:
          emit setText13(text);
          break;
      }
      break;

    case 2:
      switch(c)
      {
        case 1:
          emit setText21(text);
          break;

        case 2:
          emit setText22(text);
          break;

        case 3:
          emit setText23(text);
          break;
      }
      break;

    case 3:
      switch(c)
      {
        case 1:
          emit setText31(text);
          break;

        case 2:
          emit setText32(text);
          break;

        case 3:
          emit setText33(text);
          break;
      }
      break;
  }
}
