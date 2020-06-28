#include "audio.h"

audio::audio(QObject*parent):QObject(parent),music(NULL)
{
QUrl musicurl=QUrl::fromLocalFile(":/plantsVSzombias.mp3");
if (QFile::exists(musicurl.toLocalFile()))
  {

    music = new QMediaPlayer(this);
    QMediaPlaylist *musiclist = new QMediaPlaylist();
    QMediaContent media(musicurl);
   musiclist->addMedia(media);
  musiclist->setCurrentIndex(0);
 musiclist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
 music->setPlaylist(musiclist);	}

}
void audio::startBGM(){
  if(music)
    music->play();

}
