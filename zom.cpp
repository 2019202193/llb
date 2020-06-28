#include "zom.h"
#include<QVector2D>
#include"Pea.h"
#include"game.h"
zom::zom(way *s, game *ga):QObject(0),zombiapos(s->mywaypos)
{
  g=ga;
  zombialife=9;
 k=0,m=1,x=1;
     myaction=false;
pan=false;

 zombiapix.load(":/pu11.png");


 zombiapix=zombiapix.scaled(zombiapix.width(),zombiapix.height()*0.8);

 walkspeed=2;
}
void zom::drawzom(QPainter*painter){

  painter->save();
  QPoint setzompoint(-100,-48);
  painter->translate(zombiapos);
  painter->drawPixmap(setzompoint,zombiapix);
  painter->restore();
}
void zom::move1(){
  if(!myaction)return ;

  if(zombiapos.x()<=20)
    {
      g->gameover=true;
      return ;
    }


  k++;
  m++;
  QPoint target(0,this->zombiapos.y());
  QVector2D normalized((target-zombiapos)*2);
  normalized.normalize();
  zombiapos=zombiapos+normalized.toPoint()*walkspeed;

  if(walkspeed==0.6){
      x++;

      if(x%80==0){
          walkspeed=2;
        }
    }
 }
void zom::action(){
  myaction=true;
}
void zom::getdamage(int s){
  zombialife-=s;
  if(s==2){
      walkspeed=0.6;
      pan=true;
    }
  if(zombialife<=0)canremove();
}
void zom::canremove(){
   if(attackpea.empty()&&zombialife<=0){
       g->removezom(this);
       return;
     }
   foreach(pea*at,attackpea)
     at->targetkilled();
   g->removezom(this);
}

void zom::getattacked(pea *p){
  attackpea.push_back(p);

}
void zom::attack1(){

   int s=120;
  foreach(pea*p,g->mypeashoot){

      if(p->mypos.y()==130&&this->zombiapos.y()==120&&this->zombiapos.x()-p->mypos.x()<=s&&this->zombiapos.x()-p->mypos.x()>=10){

          myaction=false;
          p->pealife--;
       if(p->pealife<=0)
         {
           g->removepea(p);
           myaction=true;
         }
          return;
        }
      if(p->mypos.y()==225&&this->zombiapos.y()==220&&this->zombiapos.x()-p->mypos.x()<=s&&this->zombiapos.x()-p->mypos.x()>=10){

          myaction=false;
          p->pealife--;
          if(p->pealife<=0)
            {
              g->removepea(p);
              myaction=true;
            }
          return;
        }
      if(p->mypos.y()==325&&this->zombiapos.y()==330&&this->zombiapos.x()-p->mypos.x()<=s&&this->zombiapos.x()-p->mypos.x()>=10){

          myaction=false;
          p->pealife--;
          if(p->pealife<=0)
            {
              g->removepea(p);
              myaction=true;
            }
          return;
        }
      if(p->mypos.y()==425&&this->zombiapos.y()==420&&this->zombiapos.x()-p->mypos.x()<=s&&this->zombiapos.x()-p->mypos.x()>=10){

          myaction=false;
          p->pealife--;
          if(p->pealife<=0)
            {
              g->removepea(p);
              myaction=true;
            }
          return;
        }
      if(p->mypos.y()==525&&this->zombiapos.y()==520&&this->zombiapos.x()-p->mypos.x()<=s&&this->zombiapos.x()-p->mypos.x()>=10){
          myaction=false;
          p->pealife--;
          if(p->pealife<=0)
            {
              g->removepea(p);
              myaction=true;
            }
          return;
        }
    }

}
upzom::upzom(way *s, game *ga):zom(s, ga){
  zombiapix.load(":/lu1.png");
  zombiamap[0].load(":/lu1.png");
  zombiamap[1].load(":/lu2.png");
  zombiamap[2].load(":/lu3.png");
  zombiamap[3].load(":/lu4.png");
  zombiamap[4].load(":/lu5.png");
  zombiamap[5].load(":/lu6.png");
  zombiamap[6].load(":/lu7.png");
  zombiamap[7].load(":/lu8.png");
  zombiapix=zombiapix.scaled(zombiapix.width(),zombiapix.height()*0.8);
  for(int i=0;i<8;i++){
      zombiamap[i]=zombiamap[i].scaled(zombiamap[i].width(),zombiamap[i].height()*0.8);
    }
  zombialife=15;
}
void upzom::drawzom(QPainter *painter){
  painter->save();
  QPoint setzompoint(-100,-48);
  painter->translate(zombiapos);
  painter->drawPixmap(setzompoint,zombiapix);
  painter->restore();
}
void upzom::move1(){
  if(!myaction)return ;

  if(zombiapos.x()<=20)
    {
      g->gameover=true;
      return ;
    }
  int t=k%8;
  if(m%6==0)
  zombiapix=zombiamap[t];
  k++;
  m++;
  QPoint target(0,this->zombiapos.y());
  QVector2D normalized((target-zombiapos)*2);
  normalized.normalize();
  zombiapos=zombiapos+normalized.toPoint()*walkspeed;
  if(walkspeed==0.6){
      x++;
      if(x%10==0){
          walkspeed=0.8;
        }
    }
}
void upzom::getdamage(int s){
  zombialife-=s;
  if(s==2){
      walkspeed=0.6;
    }
  if(zombialife<=0)canremove();
}
void upzom::attack1(){

   int s=120;
  foreach(pea*p,g->mypeashoot){

      if(p->mypos.y()==130&&this->zombiapos.y()==120&&this->zombiapos.x()-p->mypos.x()<=s&&this->zombiapos.x()-p->mypos.x()>=10){

          myaction=false;
          p->pealife--;
       if(p->pealife<=0)
         {
           g->removepea(p);
           myaction=true;
         }
          return;
        }
      if(p->mypos.y()==225&&this->zombiapos.y()==220&&this->zombiapos.x()-p->mypos.x()<=s&&this->zombiapos.x()-p->mypos.x()>=10){

          myaction=false;
          p->pealife--;
          if(p->pealife<=0)
            {
              g->removepea(p);
             myaction=true;
            }
          return;
        }
      if(p->mypos.y()==325&&this->zombiapos.y()==330&&this->zombiapos.x()-p->mypos.x()<=s&&this->zombiapos.x()-p->mypos.x()>=10){

          myaction=false;
          p->pealife--;
          if(p->pealife<=0)
            {
              g->removepea(p);
              myaction=true;
            }
          return;
        }
      if(p->mypos.y()==425&&this->zombiapos.y()==420&&this->zombiapos.x()-p->mypos.x()<=s&&this->zombiapos.x()-p->mypos.x()>=10){

          myaction=false;
          p->pealife--;
          if(p->pealife<=0)
            {
              g->removepea(p);
              myaction=true;
            }
          return;
        }
      if(p->mypos.y()==525&&this->zombiapos.y()==520&&this->zombiapos.x()-p->mypos.x()<=s&&this->zombiapos.x()-p->mypos.x()>=10){
          myaction=false;
          p->pealife--;
          if(p->pealife<=0)
            {
              g->removepea(p);
             myaction=true;
            }
          return;
        }
    }

}
void upzom::getattacked(pea *p){
  attackpea.push_back(p);

}
void upzom::canremove(){
  if(attackpea.empty()&&zombialife<=0){
      g->removezom(this);
      return;
    }
  foreach(pea*at,attackpea)
    at->targetkilled();
  g->removezom(this);
}
void upzom::action(){
  myaction=true;
}
