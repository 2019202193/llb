#ifndef SUNFLOWER_H
#define SUNFLOWER_H
#include <iostream>
#include <QWidget>
#include <QKeyEvent>
#include<QMouseEvent>
#include<QPainter>
#include<QPoint>
using namespace std;
class sunflower{
public:
    sunflower(QPoint pos,int a=5000,int b=6,int d=64,int f=56);
    int time,sunflowerlife;
    QPixmap sunflowerimage;
    QPixmap sun;
    QPoint sunmypos;
    void sundraw(QPainter*painter);
    int sunfix,sunfiy;
};
#endif // SUNFLOWER_H
