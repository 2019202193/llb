#include<iostream>
#include"Pea.h"
#include"bullet.h"
#include"game.h"
#include"zom.h"

using namespace std;
pea::pea(QPoint t,game*ga,int a,int b,int c,int d,int f):mypos(t)
{
  g=ga;
  m=1;
  s=1;
  l=30;
  peatime=a;
peaattack=b+1;
  pealife=c;
  fix=d;
  fiy=f;
  peashoot.load(":/pea1.png");
  peapix[0].load(":/pea1.png");
  peapix[1].load(":/pea2.png");
  peapix[2].load(":/pea3.png");
  peapix[3].load(":/pea4.png");
  peapix[4].load(":/pea5.png");
  peapix[5].load(":/pea6.png");
  peapix[6].load(":/pea7.png");
  peapix[7].load(":/pea8.png");
  peapix[8].load(":/pea9.png");
 k=0;
 peashoot=peashoot.scaled(peashoot.width()*0.8,peashoot.height()*0.8);

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

  rate->start(50);
}
void pea::choose(zom*z){
  choosezom=z;
  attack();
  choosezom->getattacked(this);
}
void pea::shootweapon(){
  if(k%l!=0)
    {
      k++;
      return;
    }
  bullet*bul=new bullet(mypos,choosezom->zombiapos,g,choosezom);
  bul->movepea();
  g->addbul(bul);
  k++;
}
void pea::targetkilled(){
  if(choosezom)choosezom=NULL;
  rate->stop();
}
void pea::checkzom()
{


		QList<zom *> z = g->myzombias;
		for(int i=z.length()-1;i>=0;i--)
		{

			if(z[i]->zombiapos.y()==330&&this->mypos.y()==325&&z[i]->zombiapos.x()-this->mypos.x()>10){

			    this->choose(z[i]);
			  }
			if(z[i]->zombiapos.y()==120&&this->mypos.y()==130&&z[i]->zombiapos.x()-this->mypos.x()>10){

			    this->choose(z[i]);
			  }
			if(z[i]->zombiapos.y()==220&&this->mypos.y()==225&&z[i]->zombiapos.x()-this->mypos.x()>10){

			    this->choose(z[i]);
			  }
			if(z[i]->zombiapos.y()==420&&this->mypos.y()==425&&z[i]->zombiapos.x()-this->mypos.x()>10){

			    this->choose(z[i]);
			  }
			if(z[i]->zombiapos.y()==520&&this->mypos.y()==525&&z[i]->zombiapos.x()-this->mypos.x()>10){

			    this->choose(z[i]);
			  }



    }
                if(s%3==0){
             int t=m%9;
             peashoot=peapix[t];
             peashoot=peashoot.scaled(peashoot.width()*0.8,peashoot.height()*0.8);
             m++;
                  }
     s++;


}

icepea::icepea(QPoint t,game*ga):pea(t,ga){
  peashoot.load(":/ice1.png");
  peapix[0].load(":/ice1.png");
  peapix[1].load(":/ice2.png");
  peapix[2].load(":/ice3.png");
  peapix[3].load(":/ice4.png");
  peapix[4].load(":/ice5.png");
  peapix[5].load(":/ice6.png");
  peapix[6].load(":/ice7.png");
  peapix[7].load(":/ice8.png");
  peashoot=peashoot.scaled(peashoot.width()*0.8,peashoot.height()*0.8);
  peaattack=2;
}
void icepea::draw(QPainter *painter){
  painter->save();
  QPoint setpoint(-fix/2,-fiy/2);
  painter->translate(mypos);
  painter->drawPixmap(setpoint,peashoot);
  painter->restore();

}
void icepea::checkzom(){
  QList<zom *> z = g->myzombias;
  for(int i=z.length()-1;i>=0;i--)
  {

          if(z[i]->zombiapos.y()==330&&this->mypos.y()==325&&z[i]->zombiapos.x()-this->mypos.x()>10){


      this->choose(z[i]);
	    }
	  if(z[i]->zombiapos.y()==120&&this->mypos.y()==130&&z[i]->zombiapos.x()-this->mypos.x()>10){

	 this->choose(z[i]);
	    }
	  if(z[i]->zombiapos.y()==220&&this->mypos.y()==225&&z[i]->zombiapos.x()-this->mypos.x()>10){

	this->choose(z[i]);
	    }
	  if(z[i]->zombiapos.y()==420&&this->mypos.y()==425&&z[i]->zombiapos.x()-this->mypos.x()>10){

	  this->choose(z[i]);
	    }
	  if(z[i]->zombiapos.y()==520&&this->mypos.y()==525&&z[i]->zombiapos.x()-this->mypos.x()>10){


	      this->choose(z[i]);
	    }



}
  if(s%3==0){
int t=m%8;
peashoot=peapix[t];
peashoot=peashoot.scaled(peashoot.width()*0.8,peashoot.height()*0.8);
m++;
    }
s++;
}
void icepea::shootweapon(){
  if(k%30!=0)
    {
      k++;
      return;
    }
  bullet*bul=new icebul(mypos,choosezom->zombiapos,g,choosezom);
  bul->movepea();
  g->addbul(bul);
  k++;
}
void icepea::choose(zom *z){
  choosezom=z;
  attack();

  choosezom->getattacked(this);
}
void pea::update(){
  l=15;
}
