#include<iostream>
#include"Pea.h"
using namespace std;
pea::pea(QPoint t,int a,int b,int c,int d,int f):mypos(t)
{
  peatime=a;
peaattack=b;
  pealife=c;
  fix=d;
  fiy=f;
  peashoot.load(":/peashot1.png");
 peashoot=peashoot.scaled(peashoot.width()*0.9,peashoot.height()*0.9);
}

void pea::draw(QPainter*painter){
  painter->save();
  QPoint setpoint(-fix/2,-fiy/2);
  painter->translate(mypos);
  painter->drawPixmap(setpoint,peashoot);
  painter->restore();

}
