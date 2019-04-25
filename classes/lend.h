#ifndef LEND_H
#define LEND_H
#include "gameobject.h"
class lend : public gameobject
{
private:
  /* data */
public:
  //const char *myClassID = "хуй соси";
  polygon getCollision();
  void draw();
  lend(/* args */);
  ~lend();
};

#endif