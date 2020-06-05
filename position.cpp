#include "position.h"

position::position(QPoint pos):myposition(pos),mypea(false),fixx(80),fixy(90)
{

}
bool position::haspos(){
  return mypea;
}
void position::setpos(){
  mypea=true;
}
void position::rebackpos(){
  mypea=false;
}
bool position::containpos(const QPoint &pos){
  bool isxhere =myposition.x()<pos.x()&&(myposition.x()+fixx)>pos.x();
  bool isyhere=myposition.y()<pos.y()&&(myposition.y()+fixy)>pos.y();
  return isxhere&&isyhere;
}
const QPoint position ::centerpos(){
  QPoint point(fixx/2,fixy/2);
  return myposition+point;
}
