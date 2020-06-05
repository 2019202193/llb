#include "pushbutton.h"

pushbutton::pushbutton(QString normal,double widthr,double heightr,QString press) {
  this->normalimage=normal;
  this->pressimage=press;
  this->widthrate=widthr;
  this->heightrate=heightr;
  QPixmap pix;
  pix.load(normalimage);
  pix=pix.scaled(pix.width()*widthrate,pix.height()*heightrate);
  this->setFixedSize(pix.width(),pix.height());
  this->setIcon(pix);
  this->setIconSize(QSize(pix.width(),pix.height()));
}
