#ifndef COLLISIONSOURCE_H
#define COLLISIONSOURCE_H
#include "f3point.h"
#include "polygon.h"

  bool lines2dcollision(f3point a1, f3point a2, f3point b1, f3point b2);
  bool polygon2dcollision(polygon a, polygon b);
  bool pointinside2dpolygon(f3point a, polygon b);
  bool poligoninside2dppolygon(polygon a, polygon b);
  //bool full2dcollision(polygon a, polygon b);

#endif