#include "gameobject.h"
class rock : public gameobject
{
private:
  /* data */
public:
  rock(/* args */);
  rock(f3point p, f3point s, f3point r);
  rock(f3point target);
  // virtual polygon getCollision();
  virtual void collision(gameobject *target);
  virtual void draw();
  ~rock();
};
