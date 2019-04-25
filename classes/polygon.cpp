#include "polygon.h"
polygon::polygon(int i)
{
    size = i;
    data = new f3point[size];
    for (int i = 0; i < size; i++)
        data[i] = f3point(0, 0, 0);
}
polygon::polygon(int i, f3point points[])
{
    size = i;
    data = new f3point[size];
    for (int i = 0; i < size; i++)
        data[i] = f3point(points[i]);
}
polygon::~polygon()
{
}
int polygon::getsize()
{
    return size;
}
f3point &
    polygon::operator[](int i)
{
    return data[i];
}