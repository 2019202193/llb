#include "bullet.h"
#include"game.h"
#include<QVector2D>

bullet::bullet(QPoint sp, QPoint tp,game*ga,zom*z):target(z),g(ga)
{
  speed=10;

  currentpos.setX(sp.x()+15);
  currentpos.setY(sp.y()-15);
  startpos.setX(sp.x()+15);
  startpos.setY(sp.y()-15);
  targetpos.setY(sp.y()-15);


  if(z->myaction==false)
  targetpos.setX(tp.x()-80);
  else if(z->pan)
    targetpos.setX(tp.x()-115);
  else if(!z->pan)
    targetpos.setX(tp.x()-150);
   bul.load(":/pea.png");
   bul=bul.scaled(bul.width()*0.9,bul.height()*0.9);
   shoot=3;

}
void bullet::movepea(){

  if(targetpos.x()<=currentpos.x()){
      this->hittarget();
      return;
    }

  QVector2D normalized(targetpos-currentpos);
  normalized.normalize();
  currentpos=currentpos+normalized.toPoint()*speed;

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
void bullet::draw(QPainter *painter) {

     painter->save();
        painter->drawPixmap(currentpos,bul );
        painter->restore();
}
icebul::icebul(QPoint sp,QPoint tp,game*ga,zom*z):bullet(sp,tp,ga,z){
  bul.load(":/icebul.png");
  bul=bul.scaled(bul.width()*0.9,bul.height()*0.9);
  shoot=2;
}

void icebul::draw(QPainter *painter) {
  painter->save();
     painter->drawPixmap(currentpos,bul );
     painter->restore();
}
