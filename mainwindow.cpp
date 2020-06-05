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
    QPainter painter(this);//在mainwindow上画
    QPixmap pixmap(":/1beijing.png");//添加qt资源文件使用相对路径
    painter.drawPixmap(0,0,800,600/*适应屏幕大小*/,pixmap);

}
