#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"pushbutton.h"
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  this->setFixedSize(800,600);
  pushbutton*start=new pushbutton(":/start.png");
  start->setParent(this);
 a=new audio;
  a->startBGM();
  /*QMediaPlayer*player = new QMediaPlayer;
  player->setMedia(QUrl(":/plantsVSzombias.mp3"));
  player->setVolume(100);
  player->play();*/


  connect(start,&pushbutton::clicked,[=](){
      this->hide();
     ga=new game;
     ga->show();

    });
}

MainWindow::~MainWindow()
{
  delete ui;
}
void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pixmap(":/1beijing.png");
    painter.drawPixmap(0,0,800,600,pixmap);

}
