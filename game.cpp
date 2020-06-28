#include "game.h"
#include<QPainter>
#include"pushbutton.h"
#include <QWidget>
#include <QTimer>
#include"over.h"
game::game(QWidget *parent) : QMainWindow(parent)
{
  mywave=0;
  k=1;
  sun=50;
  gamewin=false;

  gameover=false;
  flag1=false;
  flag2=false;
  flag3=false;
  flag4=false;
  flag5=false;
  this->setFixedSize(800,600);
  pushbutton*kapai1=new pushbutton(":/kapai1.png",0.56,0.55);
  pushbutton*kapai2=new pushbutton(":/kapai2.png",0.65,0.637);
  pushbutton*kapai3=new pushbutton(":/kapai3.png",0.6,0.55);
  pushbutton*kapai4=new pushbutton(":/up.png",1,1);
  pushbutton*kapai5=new pushbutton(":/bank.png",1,1);
 kapai1->setParent(this);
  kapai1->move(118,0);
 kapai2->setParent(this);
 kapai2->move(173,0);
 kapai3->setParent(this);
 kapai3->move(225,0);
 kapai4->setParent(this);
  kapai4->move(700,500);
  kapai5->setParent(this);
   kapai5->move(550,0);
 this->loadposition();
 this->addway();

 connect(kapai2,&pushbutton::clicked,[=](){
     flag2=true;
     flag1=false;
     flag3=false;
     flag4=false;
     flag5=false;
   });
 connect(kapai1,&pushbutton::clicked,[=](){
     flag1=true;
     flag2=false;
     flag3=false;
     flag4=false;
     flag5=false;
   });
 connect(kapai3,&pushbutton::clicked,[=](){
     flag3=true;
     flag2=false;
     flag1=false;
     flag4=false;
     flag5=false;
   });
 connect(kapai4,&pushbutton::clicked,[=](){
     flag4=true;
     flag3=false;
     flag2=false;
     flag1=false;
     flag5=false;
   });
 connect(kapai5,&pushbutton::clicked,[=](){
     flag5=true;
     flag4=false;
     flag3=false;
     flag2=false;
     flag1=false;
   });
 QTimer*timer=new QTimer(this);
 connect(timer,SIGNAL(timeout()),this,SLOT(updatemap()));
 timer->start(50);
}
 void game:: paintEvent(QPaintEvent*){

  QPixmap pixmap(":/2beijing.png");
  QPainter paint(&pixmap);

  QPixmap pix;
  pix.load(":/SeedBank1.png");

   paint.drawPixmap(30,0,500,80,pix);

       foreach(pea*pea,mypeashoot)
         pea->draw(&paint);
       foreach(sunflower*sunf,mysunflower)
         sunf->sundraw(&paint);
       foreach(zom*zombia,myzombias)
         zombia->drawzom(&paint);
      foreach(bullet*bul,mybul)
        bul->draw(&paint);
  drawsun(&paint);

  QPainter painter(this);
   painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
      if(gamewin){
         over*o=new over;
         this->hide();
         o->show();

        }
   if(gameover){
       over*o=new over;
       o->change();
       this->hide();
       o->show();
     }

}
 void game::loadposition(){
   QPoint pos[]={
     QPoint(30,85),
     QPoint(112,85),
     QPoint(190,85),
     QPoint(270,85),
     QPoint(350,85),
     QPoint(440,85),
     QPoint(520,85),
     QPoint(30,180),
     QPoint(112,180),
     QPoint(190,180),
     QPoint(270,180),
     QPoint(350,180),
     QPoint(440,180),
     QPoint(520,180),
     QPoint(30,280),
     QPoint(112,280),
     QPoint(190,280),
     QPoint(270,280),
     QPoint(350,280),
     QPoint(440,280),
     QPoint(520,280),
     QPoint(30,380),
     QPoint(112,380),
     QPoint(190,380),
     QPoint(270,380),
     QPoint(350,380),
     QPoint(440,380),
     QPoint(520,380),
     QPoint(30,480),
     QPoint(112,480),
     QPoint(190,480),
     QPoint(270,480),
     QPoint(350,480),
     QPoint(440,480),
     QPoint(520,480),
    };
   int len=sizeof(pos)/sizeof(pos[0]);
   for(int i=0;i<len;i++)
     {
       myposlist.push_back(pos[i]);
     }

 }
 void game::mousePressEvent(QMouseEvent*event){
   if(flag1==true){
       flag1=false;
   QPoint presspos=event->pos();
   auto it =myposlist.begin();
   if(this->buypea()){
   while (it!=myposlist.end()){

       if(it->containpos(presspos)&&!it->haspos()){
           it->setpos();
           pea*mypea=new pea(it->centerpos(),this);
     sun-=100;
           mypeashoot.push_back(mypea);
           update();
           break;
         }
       it++;
     }
     }
}
   if(flag2==true){
       flag2=false;
   QPoint presspos=event->pos();
   auto it1 =myposlist.begin();
   if(this->buysun()){
   while (it1!=myposlist.end()){

       if(it1->containpos(presspos)&&!it1->haspos()){
           it1->setpos();
           sunflower*sunfl=new sunflower(it1->centerpos());
           sun-=50;
           mysunflower.push_back(sunfl);
           update();
           break;
         }
       it1++;
     }
     }
}
   if(flag3==true){
       flag3=false;
   QPoint presspos=event->pos();
   auto it =myposlist.begin();
   if(this->buyicepea()){
   while (it!=myposlist.end()){

       if(it->containpos(presspos)&&!it->haspos()){
           it->setpos();
           pea*mypea=new icepea(it->centerpos(),this);
          sun-=175;
           mypeashoot.push_back(mypea);
           update();
           break;
         }
       it++;
     }
     }
}
   if(flag4==true){
       flag4=false;
   QPoint presspos=event->pos();
   auto it =myposlist.begin();

   while (it!=myposlist.end()){

       if(it->containpos(presspos)&&it->haspos()){
           foreach(pea*p,mypeashoot){
               if(it->containpos(p->mypos)&&sun>=100)
                 {
                   if(p->l!=15){
                   p->update();

                     sun-=100;}
                 }
             }



           update();
           break;
         }
       it++;

     }
}
   if(flag5==true){
       flag5=false;
   QPoint presspos=event->pos();
   auto it =myposlist.begin();

   while (it!=myposlist.end()){

       if(it->containpos(presspos)&&it->haspos()){
           foreach(pea*p,mypeashoot){
               if(it->containpos(p->mypos))
                 {
                   this->removepea(p);

                 }
             }
               foreach(sunflower*s,mysunflower){
                   if(it->containpos(s->sunmypos))
                     {
                       this->removesun(s);

                     }
                 }
           update();
break;
         }



       it++;

}
 }
}
 void game::addway(){
   way*wayp1=new way(QPoint(850,120));
   mywayvector.push_back(wayp1);
   way*wayp2=new way(QPoint(850,220));
   mywayvector.push_back(wayp2);
   way*wayp3=new way(QPoint(850,330));
   mywayvector.push_back(wayp3);
   way*wayp4=new way(QPoint(850,420));
   mywayvector.push_back(wayp4);
   way*wayp5=new way(QPoint(850,520));
   mywayvector.push_back(wayp5);


 }
bool game::loadwave(){
   if (k>=4000)return false;
   if(k>=200&&k%150==0&&k<=2000){
   int m=qrand()%5;
   way*startway=mywayvector[m];
   zom*z=new zom(startway,this);
   z->action();
   myzombias.push_back(z);

     }
   if(k>800&&k%50==0&&k<=2000){
       int m=qrand()%5;

          way*startway=mywayvector[m];
          zom*z=new upzom(startway,this);

          z->action();
          myzombias.push_back(z);

     }
   if(k>2000&&k<=3960&&k%20==0){
       int m=qrand()%5;

          way*startway=mywayvector[m];
          zom*z=new upzom(startway,this);

          z->action();
          myzombias.push_back(z);
     }
 return true;
 }
 void game::updatemap(){
   foreach(zom*zombia,myzombias){
       if(zombia!=NULL){
zombia->attack1();
     zombia->move1();

}
     }
   foreach(pea*p,mypeashoot)
          p->checkzom();
   foreach(bullet*b,mybul){
      b->movepea();
     }
  foreach(sunflower*s,mysunflower)
    s->addsun(this);

   k++;
   bool t=this->loadwave();
   update();
 }
 void game::removezom(zom *z){
   Q_ASSERT(z);
   myzombias.removeOne(z);
   delete z;
   if(myzombias.empty()){

       if(!loadwave()){
           gamewin=true;
         }
     }
 }
 void game::addbul(bullet*b){
   Q_ASSERT(b);
   mybul.push_back(b);
 }
 void game:: removebul(bullet*b){
   Q_ASSERT(b);
   mybul.removeOne(b);
   delete b;
 }
 void game::removepea(pea*p){
   Q_ASSERT(p);
   auto it =myposlist.begin();
   while (it!=myposlist.end()){

       if(it->containpos(p->mypos)){
           it->rebackpos();
           break;
         }
       it++;
}
   mypeashoot.removeOne(p);
   delete p;
 }
 void game::removesun(sunflower*s){
   Q_ASSERT(s);
   auto it =myposlist.begin();
   while (it!=myposlist.end()){

       if(it->containpos(s->sunmypos)){
           it->rebackpos();
           break;
         }
       it++;
}
   mysunflower.removeOne(s);
   delete s;
 }
 bool game::buypea(){
   if(sun>=100)return true;
   return false;
 }
 bool game::buyicepea(){
   if(sun>=175)return true;
   return false;
 }
 bool game::buysun(){
   if(sun>=50)return true;
   return false;
 }
void game::drawsun(QPainter*painter){
   painter->setPen(QPen(Qt::black));
   painter->drawText(QRect(70,60,100,25),QString("%1").arg(sun));
 }
