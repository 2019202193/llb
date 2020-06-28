#include "over.h"

over::over(QWidget *parent) : QMainWindow(parent)

{
   this->setFixedSize(800,600);
   hide=true;
}
void over::change(){
  hide=false;
}
void over::paintEvent(QPaintEvent *){
  QPainter painter(this);
  QPixmap pix;
  if(hide){
      pix.load(":/win.png");
      painter.drawPixmap(0,0,this->width(),this->height(),pix);
    }
  if(!hide){
      pix.load(":/lose.png");
      painter.drawPixmap(0,0,this->width(),this->height(),pix);
    }
}
