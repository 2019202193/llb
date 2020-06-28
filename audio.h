#ifndef AUDIO_H
#define AUDIO_H

#include <QObject>
#include <QWidget>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QFile>
#include<iostream>
using namespace std;
class audio:public QObject
{
public:
  explicit audio(QObject*parent=0);
  void startBGM();
  QMediaPlayer*music;
  ~audio(){}
};

#endif // AUDIO_H
