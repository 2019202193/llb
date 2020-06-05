#include <iostream>
 #include <QPainter>
#include"mainwindow.h"
#include<QApplication>
#include "game.h"
#include <QtGui>
#include <QFrame>
using namespace std;




int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MainWindow w;//创建了mainwindow类
    w.show();

    return app.exec();
}
