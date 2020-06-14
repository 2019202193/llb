#ifndef ZOM_H
#define ZOM_H

#include <QObject>
#include <QWidget>
#include"way.h"
#include<QPainter>
#include<QMainWindow>
class pea;
class game;
class zom:public QObject{
   Q_OBJECT
public:
  zom(way*s,game*ga);
  int zombialife;
    bool myaction;
   game*g;
    QPoint zombiapos;
    QPixmap zombiamap;
    bool gameover;
    double walkspeed;
    void drawzom(QPainter*painter);
    void move1();
   void getdamage(int s);
   void canremove();
   QList<pea*>attackpea;
   void getattacked(pea*p);
public slots:
void action();
};

#endif // ZOM_H
