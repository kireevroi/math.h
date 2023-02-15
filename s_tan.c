#include "s_math.h"

long double s_tan(double x) {
  long double ret = 0;
  if (x == s_INF || x == s_N_INF || x != x)
    ret = s_NAN;
  else
    ret = s_sin(x) / s_cos(x);
  return ret;
}
