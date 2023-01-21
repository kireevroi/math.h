#include "s21_math.h"

long double pow_function(double base, double exp) {
  long double res = s21_exp(s21_log(base) * exp - 1);
  long double inc = 0.;
  for (int i = 0; i < 100; i++) {
    inc = (s21_log(res) - s21_log(base) * exp) * res;
    if (inc != inc)
      break;
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
    } else if (base == 0. && exp > 0.) {
      if ((int) exp % 2 == 1 && f == 0.) res = base;
      else res = 0.;
    } else if (exp < 0. && f == 0. && (int) exp % 2 == -1 && base == S21_N_INF) {
      res = -0.;
    } else if (exp < 0. && f == 0. && (int) exp % 2 == 0 && base == S21_N_INF) {
      res = 0.;
    } else if (exp > 0. && f == 0. && (int) exp % 2 == 1 && base == S21_N_INF) {
      res = S21_N_INF;
    } else if (exp > 0. && f == 0. && (int) exp % 2 == 0 && base == S21_N_INF) {
      res = S21_INF;
    } else if (exp < 0. && (base == S21_INF || base == S21_N_INF)) {
      res = 0.;
    } else if (exp > 0. && (base == S21_INF || base == S21_N_INF)) {
      res = S21_INF;
    } else if (base != base || exp != exp) {
      res = S21_NAN;
    } else if (base == -1. && (exp == S21_N_INF || exp == S21_INF)) {
      res = 1.0;
    } else if (base < 0. && (f > 1e18 || f < -1e-18)) {
      res = S21_NAN;
    } else if (base < 0. && f == 0.L) {
      res = pow_function(-base, exp);
      res *= (int) exp % 2 != 0 ? -1 : 1;
    } else if (base == 0. && exp < 0) {
      res = S21_INF;
    } else if (s21_fabs(base) < 1. && exp == S21_N_INF) {
      res = S21_INF;
    } else if (s21_fabs(base) < 1. && exp == S21_INF) {
      res = 0.;
    } else if (s21_fabs(base) > 1. && exp == S21_N_INF) {
      res = 0.;
    } else if (s21_fabs(base) > 1. && exp == S21_INF) {
      res = S21_INF;
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
