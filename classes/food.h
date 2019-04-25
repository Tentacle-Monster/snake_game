#ifndef FOOD_H
#define FOOD_H
#include "gameobject.h"
class food : public gameobject
{
  private:
    /* data */
  public:
    //const char *myClassID = "хуй соси";
    //virtual polygon getCollision();
    virtual void collision(gameobject *target);
    virtual void draw();
    void bite();
    food(/* args */);
    food(f3point p, f3point r, f3point s);
    food(f3point p);
    ~food();
};

#endif