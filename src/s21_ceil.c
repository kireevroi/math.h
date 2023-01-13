#include "s21_math.h"

long double s21_ceil(double a) {
  long double res = 0;
  if (a != a)
    res = a;
  else if (a == S21_INF || a == S21_N_INF)
    res = a;
  else {
    double b = (long int)a;
    // printf("%lf\n", b);
    long double comp_a = a * 10e18;
    long double comp_b = b * 10e18;
    // printf("%Lf\n", comp_b);
    if (comp_a - comp_b > 0) {
      // res = (long int)(comp_b / 10e18);
      res = b;
      res += 1.;
    } else {
      // res = (long int)(comp_a / 10e18);
      res = b;
    }
  }
  return res;
}
