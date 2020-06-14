#include "zom.h"
#include<QVector2D>
#include"Pea.h"
#include"game.h"
zom::zom(way *s, game *ga):QObject(0),zombiapos(s->mywaypos)
{
  g=ga;
  zombialife=10;

     myaction=false;
   gameover=false;
  zombiamap.load(":/lu1.png");
  zombiamap=zombiamap.scaled(zombiamap.width(),zombiamap.height()*0.8);
   walkspeed=1.0;
}
void zom::drawzom(QPainter*painter){
  if(!myaction)return;
  painter->save();
  QPoint setzompoint(-100,-48);
  painter->translate(zombiapos);
  painter->drawPixmap(setzompoint,zombiamap);
  painter->restore();
}
void zom::move1(){
  if(!myaction)return ;
  if(zombiapos.x()<=20)
    {
      gameover=true;
      return ;
    }
  QPoint target(0,300);
  QVector2D normalized(target-zombiapos);
  normalized.normalize();
  zombiapos=zombiapos+normalized.toPoint()*walkspeed;
 }
void zom::action(){
  myaction=true;
}
void zom::getdamage(int s){
  zombialife-=s;
  if(zombialife<=0)canremove();
}
void zom::canremove(){
   if(attackpea.empty())return;
   foreach(pea*at,attackpea)
     at->targetkilled();
   g->removezom(this);
}
void zom::getattacked(pea *p){
  attackpea.push_back(p);
}
