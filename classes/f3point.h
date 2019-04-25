#ifndef F3POINT_H
#define F3POINT_H
#include <cmath>
const double PI = 3.141592653589793238463;
const float toRad = PI / 180.0;
class f3point
{
private:
public:
  f3point();
  f3point(float x, float y, float z);
  f3point(f3point *target);
  ~f3point();
  float &operator[](int i);
  void operator=(f3point target);
  bool operator==(f3point target);
  void operator*=(float k);
  void operator/=(float k);
  void operator+=(f3point target);
  void operator-=(f3point target);
  f3point operator*(float k);
  f3point operator/(float k);
  f3point operator+(f3point target);
  f3point operator-(f3point target);
  float x;
  float y;
  float z;
  void useinglut();
};
#endif
