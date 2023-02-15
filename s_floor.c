#include "s_math.h"

long double s_floor(double a) {
  long double res = 0;
  int sign = 0;
  if (a != a)
    res = a;
  else if (a == s_INF || a == s_N_INF)
    res = a;
  else {
    if (a < 0) {
      a *= -1;
      sign++;
      long int b = (long int)a;
      res = (a != b) ? (long int)(a + 1.) : (long int)a;
    } else
      res = (long int)a;
  }
  if (sign) {
    res *= -1;
  }
  return res;
}