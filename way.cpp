#include "way.h"

way::way(QPoint waypos):mywaypos(waypos)
{

}
const QPoint way::pos() const
{
  return mywaypos;
}
