#include "s_math.h"

long double s_fabs(double x) {
  if (x < 0) x *= -1;
  return x;
}