#include "f3point.h"
class model
{
private:
  f3point data[];
  /* data */
public:
  const int size;
  model(int size);
  model(f3point maitix[]);

  ~model();
};