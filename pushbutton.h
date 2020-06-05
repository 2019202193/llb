#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QPushButton>
#include <QWidget>
class pushbutton : public QPushButton
{
  Q_OBJECT
public:
   pushbutton(QString normal,double widthr=0.5,double heightr=0.5,QString press="");
   QString normalimage;
   QString pressimage;
   double widthrate;
   double heightrate;

signals:

};

#endif // PUSHBUTTON_H
