#include "s_math.h"

long double s_ceil(double a) {
  long double res = 0;
  if (a != a)
    res = a;
  else if (a == s_INF || a == s_N_INF)
    res = a;
  else {
    long double b = (long long int)a;
    long double comp_a = a;
    comp_a *= 10e18;
    long double comp_b = b;
    comp_b *= 10e18;
    if (comp_a - comp_b > 0) {
      res = b;
      res += 1.;
    } else {
      res = b;
    }
  }
  return res;
}
