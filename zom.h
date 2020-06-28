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
   int k,m;
   bool pan;
    QPoint zombiapos;

    QPixmap zombiapix;

    double walkspeed;
    virtual void drawzom(QPainter*painter);
    virtual void move1();
    virtual void getdamage(int s);
    virtual void canremove();
   QList<pea*>attackpea;
   virtual void getattacked(pea*p);
    virtual void attack1();
   virtual void action();

  int x;
  virtual~zom(){}
};
class upzom:public zom{
  Q_OBJECT
public:

  upzom(way*s,game*ga);
  QPixmap zombiamap[8],zombiapix;
  int zombialife;
  void drawzom(QPainter *painter) override;
  void move1() override;
  void getdamage(int s) override;
void attack1() override;
  void canremove() override;
  void action() override;
  void getattacked(pea *p) override;
  ~upzom(){}
};

#endif // ZOM_H
