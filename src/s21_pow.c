#include "s21_math.h"

long double pow_function(double base, double exp) {
  long double res = s21_exp(s21_log(base) * exp - 1);
  for (int i = 0; i < 100; i++) {
    long double inc = (s21_log(res) - s21_log(base) * exp) * res;
    if (inc != inc) break;
    res = res - inc;
  }
  return res;
}

long double s21_pow(double base, double exp) {
  long double res = 0;
  long double f = s21_fmod(exp, 1);
  if (base == 1.) {
    res = 1.0;
  } else if (exp == 0.) {
    res = 1.0;
  } else if (base == 0.) {
    if (exp > 0.) {
      res = ((int)exp % 2 == 1 && f == 0.) ? base : 0.;
    } else
      res = S21_INF;
  } else if (exp < 0. && f == 0. && base == S21_N_INF) {
    if ((int)exp % 2 == -1)
      res = -0.;
    else
      res = 0.;
  } else if (exp > 0. && f == 0. && base == S21_N_INF) {
    res = ((int)exp % 2 == 1) ? S21_N_INF : S21_INF;
  } else if (base == S21_INF || base == S21_N_INF) {
    res = (exp < 0.) ? 0. : S21_INF;
  } else if (base != base || exp != exp) {
    res = S21_NAN;
  } else if (base == -1. && (exp == S21_N_INF || exp == S21_INF)) {
    res = 1.0;
  } else if (base < 0.) {
    if (f == 0.L) {
      res = pow_function(-base, exp);
      res *= (int)exp % 2 != 0 ? -1 : 1;
    } else
      res = S21_NAN;
  } else if (exp == S21_N_INF) {
    res = (s21_fabs(base) < 1.) ? S21_INF : 0.;
  } else if (exp == S21_INF) {
    res = (s21_fabs(base) < 1.) ? 0. : S21_INF;
  } else
    res = pow_function(base, exp);
  return res;
}

// long double s21_pow(double base, double exp) {
//   long double res = 0.;
//   if (exp > 0) {
//     __asm__ __volatile__(
//         "fldl %2;"             // Load exponent
//         "fldl %1;"             // Load base
//         "fyl2x;"               // perform exp * log2(base)
//         "fld1;"                // load 1.
//         "fldl %%st(1);"        // load value to stack 1
//         "fprem;"               // Get remainder (f2xm1 works only in [-1:1])
//         "f2xm1;"               // Compute 2^x-1
//         "fadd;"                // Add the 1
//         "fscale;"              // Scale the result by appropriate power of 2
//         "fxch %%st(1);"        // swap registers
//         "fstp %%st(0);"        // pop register
//         "fstpt %0;"            // place value in res
//         : "=m"(res)            // where to store the result
//         : "m"(base), "m"(exp)  // what to use
//         : "st(1)", "st"  // used registers so compiler doesn't optimize them
//     );
//   }
//   return res;
// }
