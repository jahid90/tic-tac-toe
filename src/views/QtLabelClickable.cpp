#include "QtLabelClickable.h"

QtLabelClickable::QtLabelClickable( const QString& text, QWidget* parent )
    : QLabel(parent)
{
  setText(text);
}

QtLabelClickable::QtLabelClickable( QWidget* parent )
    : QLabel(parent)
{
}
 
QtLabelClickable::~QtLabelClickable()
{
}
 
void
QtLabelClickable::mousePressEvent( QMouseEvent* event )
{
  emit clicked();
}