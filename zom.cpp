#include "zom.h"
#include<QVector2D>
zom::zom(way *s):QObject(0),zombiapos(s->mywaypos)
{
  zombialife=10;
     currentlife=10;
     myaction=false;
   gameover=false;
  zombiamap.load(":/lu1.png");
  zombiamap=zombiamap.scaled(zombiamap.width(),zombiamap.height()*0.9);
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
