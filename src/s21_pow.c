#include "s21_math.h"
#include <math.h>
long double s21_pow(double base, double exp) {
  long double result = 0;
  if (base != base)
    result = S21_NAN;
  else if (base == S21_N_INF)
    result = S21_INF;
  else if (base == 0. && exp == 0.)
    result = 1;
  else {
    long double p = log(base) * exp;
    long double lb = s21_exp(p - 1);
    long double rb = s21_exp(p + 1);
    if (lb == S21_INF || lb == -S21_INF) {
      result = lb;
    } else {
      if (rb == S21_INF || rb == -S21_INF)
        rb = DBL_MAX;
      long double mid =  lb / 2. + rb / 2.;
      long double diff = log(mid) - p;
      int count = 0;
      while (s21_fabs(diff) >= 1e-16 && lb + 1e-16 <= lb) {
        long double ldiff = log(rb) - log(lb);
        if (s21_fabs(ldiff) > S21_EPS) {
          rb -= s21_fabs((rb - lb) *
                                  (log(rb) - p) / (ldiff));
        }
        lb -= (log(lb) - p) * lb;
        mid = lb / 2. + rb / 2.;
        diff = log(mid) - p;
        count++;
        if (count > 20) break;
      }
      result = mid;
    }
  }
  return result;
}