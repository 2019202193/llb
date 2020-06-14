#include<iostream>
#include"Pea.h"
#include"bullet.h"
using namespace std;
pea::pea(QPoint t,game*ga,int a,int b,int c,int d,int f):mypos(t)
{
  g=ga;
  peatime=a;
peaattack=b;
  pealife=c;
  fix=d;
  fiy=f;
  peashoot.load(":/peashot1.png");
 peashoot=peashoot.scaled(peashoot.width()*0.9,peashoot.height()*0.9);
 rate=new QTimer(this);
 connect(rate,SIGNAL(timeout()),this,SLOT(shootweapon()));
}

void pea::draw(QPainter*painter){
  painter->save();
  QPoint setpoint(-fix/2,-fiy/2);
  painter->translate(mypos);
  painter->drawPixmap(setpoint,peashoot);
  painter->restore();

}
void pea::attack(){
  rate->start(peatime);
}
void pea::choose(zom*z){
  choosezom=z;
  attack();
  choosezom->getattacked(this);
}
void pea::shootweapon(){
  bullet*bul=new bullet(mypos,choosezom->zombiapos,g,choosezom);
  bul->movepea();
  g->addbul(bul);
}
void pea::targetkilled(){
  if(choosezom)choosezom=NULL;
  rate->stop();
}
