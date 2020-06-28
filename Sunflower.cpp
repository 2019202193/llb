#include<iostream>
#include"Sunflower.h"
#include"game.h"
sunflower::sunflower(QPoint pos,int a,int b,int d,int f):sunmypos(pos){
  time=a;
  sunflowerlife=b;
  sunfix=d;
  sunfiy=f;
  sunflowerimage.load(":/sunflower.png");
  sunflowerimage=sunflowerimage.scaled(sunflowerimage.width()*0.32,sunflowerimage.height()*0.28);
  k=1;
}
void sunflower::sundraw(QPainter*painter){
  painter->save();
  QPoint setpoint(-sunfix/2,-sunfiy/2);
  painter->translate(sunmypos);
  painter->drawPixmap(setpoint,sunflowerimage);
  painter->restore();

}
void sunflower::addsun(game *g){
  k++;
  if(k%30==0)
     g->sun+=25;
  return;
}
