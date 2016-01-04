#ifndef __QT_LABEL_CLICKABLE_H__
#define __QT_LABEL_CLICKABLE_H__

#include <QLabel>

class QString;
class QWidget;
class QMouseEvent;

class QtLabelClickable : public QLabel
{
  Q_OBJECT
  public:
      explicit QtLabelClickable( const QString& text = "", QWidget* parent = 0 );
      explicit QtLabelClickable( QWidget* parent = 0 );
      ~QtLabelClickable();

  signals:
      void clicked();

  protected:
      void mousePressEvent( QMouseEvent* event );
};

#endif // __QT_LABEL_CLICKABLE_H__
