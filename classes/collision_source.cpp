#include "collision_source.h"
bool lines2dcollision(f3point a, f3point b, f3point c, f3point d)
{
    double common = (b.x - a.x) * (d.y - c.y) - (b.y - a.y) * (d.x - c.x);

    if (common == 0)
        return false;

    double rH = (a.y - c.y) * (d.x - c.x) - (a.x - c.x) * (d.y - c.y);
    double sH = (a.y - c.y) * (b.x - a.x) - (a.x - c.x) * (b.y - a.y);

  //  double r = rH / common;
  //  double s = sH / common;
// if (r >= 0 && rH <= 1 && s >= 0 && s <= 1)
    if (rH >= 0 && rH <= common && sH >= 0 && sH <= common)//faster
        return true;
    else
        return false;
}
bool polygon2dcollision(polygon a, polygon b)
{
    int asize = a.getsize();
    int bsize = b.getsize();
    for (int ai = 0; ai < asize; ai++)
        for (int bi = 0; bi < bsize; bi++)
            if (lines2dcollision(a.data[ai % asize], a.data[(ai + 1) % asize], b.data[bi % bsize], b.data[(bi + 1) % bsize]))
                return 1;
    return 0;
}
bool pointinside2dpolygon(f3point a, polygon b){
 
      bool c = false;
      int col = b.getsize();
      if(col<3) return c;
    for (int i = 0, j = col - 1; i <  col; j = i++) 
    {
      if ((((b[i].y<=a.y) && (a.y<b[j].y)) || ((b[j].y<=a.y) && (a.y<b[i].y))) &&
        (a.x > (b[j].x - b[i].x) * (a.y - b[i].y) / (b[j].y - b[i].y) + b[i].x))
          c = !c;
    }
    return c;
}
  bool poligoninside2dppolygon(polygon a, polygon b){
      for(int i=0; i<a.getsize();i++){
          if(pointinside2dpolygon(a[i],b))
          return true;
      }
      return false;
  }
  /*bool full2dcollision(polygon a, polygon b);*/