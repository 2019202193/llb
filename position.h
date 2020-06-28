#ifndef POSITION_H
#define POSITION_H

#include <QMainWindow>
#include <QWidget>
#include<QPoint>
class position
{
public:
  position(QPoint pos);
  void setpos();
  bool haspos();
  void rebackpos();
  bool containpos(const QPoint &pos);
  const QPoint centerpos();
  ~position(){}
private:
   QPoint myposition;
   bool mypea;
   int fixx;
   int fixy;
};

#endif // POSITION_H
