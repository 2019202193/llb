#ifndef PEA_H
#define PEA_H
#include <iostream>
#include <QWidget>
#include <QKeyEvent>
#include<QMouseEvent>
#include<QPoint>
#include<QPainter>

using namespace std;
class pea{
public:
 pea(QPoint t,int a=1000,int b=2,int c=6,int d=64,int f=56);

 int peatime,pealife,peaattack,fix,fiy;
 QPoint mypos;
 QPixmap peashoot;
 void draw(QPainter *painter);
};

#endif // PEA_H
