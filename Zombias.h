#ifndef ZOMBIAS_H
#define ZOMBIAS_H

#include <QWidget>
#include"way.h"
#include<QPainter>
#include<QMainWindow>
#include<QObject>
class zombias:public QObject
{
  //Q_OBJECT
public:
  zombias(way *s);
  int zombialife,currentlife;
  bool myaction;

  QPoint zombiapos;
  QPixmap zombiamap;
  bool gameover;
  double walkspeed;
  void drawzom(QPainter*painter);
  void move();
  void action();
};


#endif // ZOMBIAS_H
