#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double res = 0.;
  if (exp > 0) {
    __asm__ __volatile__(
        "fldl %2;"             // Load exponent
        "fldl %1;"             // Load base
        "fyl2x;"               // perform exp * log2(base)
        "fld1;"                // load 1.
        "fldl %%st(1);"        // load value to stack 1
        "fprem;"               // Get remainder (f2xm1 works only in [-1:1])
        "f2xm1;"               // Compute 2^x-1
        "fadd;"                // Add the 1
        "fscale;"              // Scale the result by appropriate power of 2
        "fxch %%st(1);"        // swap registers
        "fstp %%st(0);"        // pop register
        "fstpt %0;"            // place value in res
        : "=m"(res)            // where to store the result
        : "m"(base), "m"(exp)  // what to use
        : "st(1)", "st"  // used registers so compiler doesn't optimize them
    );
  }
  return res;
}
