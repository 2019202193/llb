#ifndef OVER_H
#define OVER_H

#include <QMainWindow>
#include<QWidget>
#include<QPainter>
class over:public QMainWindow
{
public:
  explicit over(QWidget *parent = nullptr);
  bool hide;
  void change();
  virtual void paintEvent(QPaintEvent*);
  ~over(){}
};

#endif // OVER_H
