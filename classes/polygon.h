#ifndef POLYGONE_H
#define POLYGONE_H
#include "f3point.h"
class polygon
{
protected:
  /* data */
  int size;

public:
  f3point *data;

  polygon(int size);
  polygon(int size, f3point points[]);
  //polygon(f3point n, ...);
  int getsize();
  ~polygon();
  f3point &operator[](int i);
};
#endif
