#include "game.h"
#include<QPainter>
#include"pushbutton.h"
#include <QWidget>
#include <QTimer>
game::game(QWidget *parent) : QMainWindow(parent)
{
  mywave=0;
  flag1=false;
  flag2=false;
  this->setFixedSize(800,600);
  pushbutton*kapai1=new pushbutton(":/kapai1.png",0.56,0.55);
  pushbutton*kapai2=new pushbutton(":/kapai2.png",0.65,0.637);
 kapai1->setParent(this);
  kapai1->move(118,0);
 kapai2->setParent(this);
 kapai2->move(173,0);
 this->loadposition();
 this->addway();
 bool t=this->loadwave();
 connect(kapai2,&pushbutton::clicked,[=](){
     flag2=true;
     flag1=false;
   });
 connect(kapai1,&pushbutton::clicked,[=](){
     flag1=true;
     flag2=false;
   });
 QTimer*timer=new QTimer(this);
 connect(timer,SIGNAL(timeout()),this,SLOT(updatemap()));
 timer->start(30);
}
 void game:: paintEvent(QPaintEvent*){
  QPainter painter(this);
  QPixmap pixmap(":/2beijing.png");
 painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
  QPixmap pix;
  pix.load(":/SeedBank1.png");

   painter.drawPixmap(30,0,500,80,pix);

       foreach(pea*pea,mypeashoot)
         pea->draw(&painter);
       foreach(sunflower*sunf,mysunflower)
         sunf->sundraw(&painter);
       foreach(zom*zombia,myzombias)
         zombia->drawzom(&painter);



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
   while (it!=myposlist.end()){

       if(it->containpos(presspos)&&!it->haspos()){
           it->setpos();
           pea*mypea=new pea(it->centerpos(),this);
           mypeashoot.push_back(mypea);
           update();
           break;
         }
       it++;
     }
}
   if(flag2==true){
       flag2=false;
   QPoint presspos=event->pos();
   auto it1 =myposlist.begin();
   while (it1!=myposlist.end()){

       if(it1->containpos(presspos)&&!it1->haspos()){
           it1->setpos();
           sunflower*sunfl=new sunflower(it1->centerpos());
           mysunflower.push_back(sunfl);
           update();
           break;
         }
       it1++;
     }
}
 }
 void game::addway(){
   way*wayp1=new way(QPoint(800,120));
   mywayvector.push_back(wayp1);
   way*wayp2=new way(QPoint(800,220));
   mywayvector.push_back(wayp2);
   way*wayp3=new way(QPoint(800,330));
   mywayvector.push_back(wayp3);
   way*wayp4=new way(QPoint(800,420));
   mywayvector.push_back(wayp4);
   way*wayp5=new way(QPoint(800,520));
   mywayvector.push_back(wayp5);


 }
bool game::loadwave(){
   if (mywave>=6)return false;
   way *startway=mywayvector[2];
   int interval[]={100,500,600,1000,3000,6000};
   for(int i=0;i<6;i++){
       zom*zombia=new zom(startway,this);
       myzombias.push_back(zombia);
       QTimer::singleShot(interval[i],zombia,SLOT(action()));
 }return true;
 }
 void game::updatemap(){
   foreach(zom*zombia,myzombias)
     zombia->move1();
   update();
 }
