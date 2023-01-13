#include "s21_math.h"

long double s21_floor(double a) {
  long double res = 0;
  int sign = 0;
  if (a != a)
    res = a;
  else if (a == S21_INF || a == S21_N_INF)
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