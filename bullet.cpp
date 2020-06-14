#include "bullet.h"
#include"game.h"

bullet::bullet(QPoint sp, QPoint tp,game*ga,zom*z):startpos(sp),targetpos(tp),target(z),g(ga)
{
   bul.load(":/pea.png");
   shoot=2;
}
void bullet::movepea(){
  int d=1000;
  QPropertyAnimation*a=new QPropertyAnimation(this,"currentpos");
  a->setDuration(d);
  a->setStartValue(startpos);
  a->setEndValue(targetpos);
  connect(a,SIGNAL(finished()),this,SLOT(hittarget()));
}
void bullet::hittarget(){
  if(g->myzombias.indexOf(target)!=-1)
    target->getdamage(shoot);
  g->removebul(this);
}
void bullet::setcpos(QPoint p){
  currentpos=p;
}
QPoint bullet::current(){
  return currentpos;
}
