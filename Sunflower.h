#ifndef SUNFLOWER_H
#define SUNFLOWER_H
#include <iostream>
#include <QWidget>
#include <QKeyEvent>
#include<QMouseEvent>
#include<QPainter>
#include<QPoint>
class game;
using namespace std;
class sunflower{
public:
    sunflower(QPoint pos,int a=5000,int b=6,int d=64,int f=56);
    int time,sunflowerlife;
    QPixmap sunflowerimage;
  int k;
    QPoint sunmypos;
    void sundraw(QPainter*painter);
    int sunfix,sunfiy;
    void addsun(game*g);
    ~sunflower(){}
};
#endif // SUNFLOWER_H
