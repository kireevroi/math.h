#include "test_me.h"

START_TEST(s_sqrt_1) {
  double num = 0.;
  ck_assert_ldouble_eq(s_sqrt(num), sqrt(num));
}
END_TEST

START_TEST(s_sqrt_2) {
  double num = 16.;
  ck_assert_ldouble_eq_tol(s_sqrt(num), sqrt(num), s_EPS);
}
END_TEST

START_TEST(s_sqrt_3) {
  double num = 4096.;
  ck_assert_ldouble_eq_tol(s_sqrt(num), sqrt(num), s_EPS);
}
END_TEST

START_TEST(s_sqrt_4) {
  for (double num = 400; num <= 1000.; num += 15.) {
    ck_assert_ldouble_eq_tol(s_sqrt(num), sqrt(num), s_EPS);
  }
}
END_TEST

START_TEST(s_sqrt_5) {
  for (double num = 3.; num <= 4.; num += 0.1) {
    ck_assert_ldouble_eq_tol(s_sqrt(num), sqrt(num), s_EPS);
  }
}
END_TEST

START_TEST(s_sqrt_6) {
  double num = NAN;
  ck_assert_ldouble_nan(s_sqrt(num));
  ck_assert_ldouble_nan(sqrt(num));
}
END_TEST

START_TEST(s_sqrt_7) {
  double num = NAN;
  ck_assert_ldouble_nan(s_sqrt(num));
  ck_assert_ldouble_nan(sqrt(num));
}
END_TEST

START_TEST(s_sqrt_8) {
  double num = INFINITY;
  ck_assert_ldouble_infinite(s_sqrt(num));
  ck_assert_ldouble_infinite(sqrt(num));
}
END_TEST

START_TEST(s_sqrt_9) {
  double num = -INFINITY;
  ck_assert_ldouble_nan(s_sqrt(num));
  ck_assert_ldouble_nan(sqrt(num));
}
END_TEST

START_TEST(s_sqrt_10) {
  double num = -1.;
  ck_assert_ldouble_nan(s_sqrt(num));
}
END_TEST

START_TEST(s_sqrt_11) {
  srand(time(NULL));
  for (double num = s_EPS * s_EPS; num < DBL_MAX;
       num *= (rand() % 10000) / 1000000. + 3.02) {
    long double x = s_EPS;
    if (floorl(log10l(sqrt(num))) >= 10)
      x = s_EPS * powl(10, floorl(log10l(sqrt(num))) - 10);
    ck_assert_ldouble_eq_tol(s_sqrt(num), sqrtl(num), x);
  }
}

Suite *test_s_sqrt(void) {
  Suite *s = suite_create("\033[45m-=s_SQRT=-\033[0m");
  TCase *tc = tcase_create("s_sqrt_tc");

  tcase_add_test(tc, s_sqrt_1);
  tcase_add_test(tc, s_sqrt_2);
  tcase_add_test(tc, s_sqrt_3);
  tcase_add_test(tc, s_sqrt_4);
  tcase_add_test(tc, s_sqrt_5);
  tcase_add_test(tc, s_sqrt_6);
  tcase_add_test(tc, s_sqrt_7);
  tcase_add_test(tc, s_sqrt_8);
  tcase_add_test(tc, s_sqrt_9);
  tcase_add_test(tc, s_sqrt_10);
  tcase_add_test(tc, s_sqrt_11);

  suite_add_tcase(s, tc);
  return s;
}
