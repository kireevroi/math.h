#include "s_math.h"

long double s_acos(double x) {
  long double ret = 0;
  if (x != x)
    ret = s_NAN;
  else if (x == 1.)
    ret = 0.;
  else if (x == s_INF || x == s_N_INF)
    ret = s_NAN;
  else if (x > 1. || x < -1.)
    ret = s_NAN;
  else
    ret = (long double)s_PI / 2 - s_asin(x);
  return ret;
}