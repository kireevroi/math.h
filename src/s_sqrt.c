#include "s_math.h"

long double s_sqrt(double x) {
  long double ret = 0;
  if (x == s_INF)
    ret = s_INF;
  else if (x == s_N_INF)
    ret = s_NAN;
  else if (x != x)
    ret = s_NAN;
  else if (x < 0)
    ret = s_NAN;
  else if (x > 0) {
    __asm__ __volatile__(
        "fldl %1;"
        "fsqrt;"
        "fstpt %0;"
        : "=m"(ret)
        : "m"(x));
  }
  return ret;
}
