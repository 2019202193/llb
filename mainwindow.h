#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QPainter>
#include "game.h"
#include"audio.h"
namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  virtual void paintEvent(QPaintEvent*);
  audio*a;
  game*ga=NULL;

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
