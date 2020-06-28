#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include"position.h"
#include"Pea.h"
#include<QMouseEvent>
#include"Sunflower.h"
#include"way.h"
#include"zom.h"
#include"bullet.h"

class game : public QMainWindow
{
  Q_OBJECT
public:
  explicit game(QWidget *parent = nullptr);
  virtual void paintEvent(QPaintEvent*);
  QList<position> myposlist;
  void loadposition();
  QList<pea*>mypeashoot;
  void mousePressEvent(QMouseEvent*event);
  bool flag1,flag2,flag3,flag4,flag5;
  QList<sunflower*>mysunflower;
  void addway();
  QList<zom*>myzombias;
  bool loadwave();
  int mywave;
  vector<way*>mywayvector;
  void removezom(zom*z);
  bool gamewin,gameover;
  QList<bullet*>mybul;
  void removebul(bullet*b);
  void addbul(bullet*b);
  int k;
  void removepea(pea*p);
  int sun;
  bool buypea();
  bool buyicepea();
  bool buysun();
  void drawsun(QPainter*painter);
  void removesun(sunflower*s);
  ~game(){}
 private slots:
    void updatemap();

signals:

};

#endif // GAME_H
