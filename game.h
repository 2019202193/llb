#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include"position.h"
#include"Pea.h"
#include<QMouseEvent>
#include"Sunflower.h"
#include"way.h"
#include"zom.h"
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
  bool flag1,flag2;
  QList<sunflower*>mysunflower;
  void addway();
  QList<zom*>myzombias;
  bool loadwave();
  int mywave;
  vector<way*>mywayvector;
 private slots:
    void updatemap();

signals:

};

#endif // GAME_H
