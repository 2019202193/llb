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
 pea(QPoint t,game*ga,int a=100,int b=2,int c=20,int d=64,int f=56);
 game*g;
 int peatime,pealife,peaattack,fix,fiy,k;
 QPoint mypos;
 QPixmap peashoot,peapix[9];
 int m,s,l;
 virtual void draw(QPainter *painter);
 QTimer*rate;
 zom*choosezom;
 void attack();

 virtual void choose(zom*z);
 void targetkilled();
 virtual void checkzom();
 void update();
 virtual ~pea(){}
private slots:
 virtual void shootweapon();
};
class icepea:public pea{
  Q_OBJECT
public:
  icepea(QPoint t,game*ga);
  QPixmap peashoot, peapix[9];
  void checkzom() override;
  void draw(QPainter *painter) override;
  void choose(zom *z) override;

  ~icepea(){}
private slots:
 void shootweapon() override;
};

#endif // PEA_H
