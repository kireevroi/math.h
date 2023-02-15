#include "s_math.h"

long double s_fmod(double x, double y) {
  long double res = 0;
  if (x != x || y != y || y == 0 || x == s_INF || x == s_N_INF) {
    res = s_NAN;
  } else if (y == s_INF || y == s_N_INF) {
    res = x;
  } else {
    res = x;
    y = s_fabs(y);
    if (res > 0) {
      while (res >= y) {
        res -= y;
      }
    } else {
      while (res <= -y) {
        res += y;
      }
    }
  }
  return res;
}
