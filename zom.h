#ifndef ZOM_H
#define ZOM_H

#include <QObject>
#include <QWidget>
#include"way.h"
#include<QPainter>
#include<QMainWindow>
class zom:public QObject{
   Q_OBJECT
public:
  zom(way*s);
  int zombialife,currentlife;
    bool myaction;

    QPoint zombiapos;
    QPixmap zombiamap;
    bool gameover;
    double walkspeed;
    void drawzom(QPainter*painter);
    void move1();

public slots:
void action();
};

#endif // ZOM_H
