#ifndef WAY_H
#define WAY_H

#include <QWidget>

class way
{
public:
  way(QPoint waypos);
  const QPoint pos()const;


  QPoint mywaypos;
  ~way(){}
};

#endif // WAY_H
