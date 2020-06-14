#ifndef PEA_H
#define PEA_H
#include <iostream>
#include <QWidget>
#include <QKeyEvent>
#include<QMouseEvent>
#include<QPoint>
#include<QPainter>
#include"zom.h"
#include<QTimer>
class bullet;
class game;
using namespace std;
class pea:public QObject{
  Q_OBJECT
public:
 pea(QPoint t,game*ga,int a=100,int b=2,int c=6,int d=64,int f=56);
 game*g;
 int peatime,pealife,peaattack,fix,fiy;
 QPoint mypos;
 QPixmap peashoot;
 void draw(QPainter *painter);
 QTimer*rate;
 zom*choosezom;
 void attack();
 void choose(zom*z);
 void targetkilled();
private slots:
 void shootweapon();
};

#endif // PEA_H
