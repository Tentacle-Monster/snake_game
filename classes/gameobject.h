#ifndef GAMEOBGECT_H
#define GAMEOBGECT_H
#include "polygon.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <typeinfo>
#include <iostream>
class gameobject
{
protected:
  /* data */
  f3point position;
  f3point rotation;
  f3point scaling;

public:
  //const char *myClassID = "хуй соси губой тряси";
  gameobject(/* args */);
  gameobject(f3point p, f3point r, f3point s);
  ~gameobject();
  virtual void draw();
  //virtual void modeldraw();
  virtual polygon getCollision();
  // template <class T>
  virtual void collision(gameobject *target);
  void moveto(f3point target);
  void rotate(f3point angles);
  void scale(f3point parametres);
};

#endif