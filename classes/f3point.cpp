
#include "f3point.h"
#include <cmath>
#include <GL/glut.h>

f3point ::f3point()
{
    x = 0;
    y = 0;
    z = 0;
}
f3point ::f3point(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
f3point ::f3point(f3point *target)
{
    x = target->x;
    y = target->y;
    z = target->z;
}
f3point ::~f3point()
{
}
float &
    f3point::operator[](int i)
{
    switch (i)
    {
    case 0 /* constant-expression */:
        /* code */
        return x;
        break;
    case 1:
        return y;
        break;
    case 2:
        return z;
        break;

    default:
        break;
    }
    //return 0;
}
void f3point::operator=(f3point target)
{
    x = target.x;
    y = target.y;
    z = target.z;
}
bool f3point::operator==(f3point target)
{

    return (
        this == &target ||
        x == target.x &&
            y == target.y &&
            z == target.z);
}
void f3point::operator*=(float k)
{
    x *= k;
    y *= k;
    z *= k;
}
void f3point::operator/=(float k)
{
    x /= k;
    y /= k;
    z /= k;
}
void f3point::operator+=(f3point target)
{
    x += target.x;
    y += target.y;
    z += target.z;
}
void f3point::operator-=(f3point target)
{

    x -= target.x;
    y -= target.y;
    z -= target.z;
}
f3point f3point::operator*(float k)
{
    f3point a = f3point(this);
    a *= k;
    return a;
}
f3point f3point::operator/(float k)
{
    f3point a = f3point(this);
    a /= k;
    return a;
}
f3point f3point::operator+(f3point target)
{
    f3point a = f3point(this);
    a += target;
    return a;
}
f3point f3point::operator-(f3point target)
{

    f3point a = f3point(this);
    a -= target;
    return a;
}
void f3point::useinglut()
{
    glVertex3f(x, y, z);
}