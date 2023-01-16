#include "s21_math.h"

long double s21_sqrt(double x) {
  long double ret = 0;
  if (x == S21_INF) ret = S21_INF;
  else if (x == S21_N_INF) ret = S21_NAN;
  else if (x != x) ret = S21_NAN;
  else if (x < 0) ret = S21_NAN;
  else if (x > 0) {
     __asm__ (
      "fldl %1;"
      "fsqrt;"
      "fstpt %0;" : "=m"(ret) : "m"(x)
     );
  }
  return ret;
}
