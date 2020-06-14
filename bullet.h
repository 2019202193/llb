#ifndef BULLET_H
#define BULLET_H

#include <QWidget>
#include<QObject>
#include"zom.h"
class game;
#include<QPropertyAnimation>
class bullet:public QObject
{
  Q_OBJECT
  Q_PROPERTY(QPoint currentpos READ current WRITE setcpos)

public:
  bullet(QPoint sp,QPoint tp,game*ga,zom*z);
  QPoint startpos;
  QPoint targetpos;
  QPoint currentpos;
  QPixmap bul;

  zom*target;
  game*g;
  int shoot;
  void draw(QPainter*painter);
  void movepea();
  void setcpos(QPoint p);
  QPoint current();
private slots:
  void hittarget();
};

#endif // BULLET_H
