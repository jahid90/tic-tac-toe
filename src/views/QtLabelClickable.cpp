#include "CommonIncludes.h"

#include <QString>
#include <QWidget>
#include <QMouseEvent>

#include "QtLabelClickable.h"
#include "Utils.h"

QtLabelClickable::QtLabelClickable( const QString & text, QWidget * parent )
    : QLabel(parent)
{
  setText(text);
}

QtLabelClickable::QtLabelClickable( QWidget * parent )
    : QLabel(parent)
{
}
 
QtLabelClickable::~QtLabelClickable()
{
}
 
void
QtLabelClickable::mousePressEvent( QMouseEvent * event )
{
  if ( DEBUG ) std::cerr << "received mousePressEvent: " << event->type() << std::endl;

  emit clicked();
}