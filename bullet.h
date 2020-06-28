#ifndef BULLET_H
#define BULLET_H

#include <QWidget>
#include<QObject>
#include<QPainter>
#include<QMainWindow>
#include"zom.h"
class game;

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
  int speed;
  zom*target;
  game*g;
  int shoot;
  virtual void draw(QPainter*painter);
  void movepea();
  void setcpos(QPoint p);
  QPoint current();

  void hittarget();
  virtual ~bullet(){}

};
class icebul:public bullet{
public:
  icebul(QPoint sp,QPoint tp,game*ga,zom*z);
  QPixmap bul;
  void draw(QPainter *painter) override;
  ~icebul(){}
};

#endif // BULLET_H
