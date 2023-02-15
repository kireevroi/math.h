#include "test_me.h"

START_TEST(s_fmod_1) {
  double x = 0.;
  double y = 3.;
  ck_assert_ldouble_eq_tol(s_fmod(x, y), fmod(x, y), s_EPS);
}
END_TEST

START_TEST(s_fmod_2) {
  double x = 0.;
  double y = 1.;
  ck_assert_ldouble_eq(s_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s_fmod_3) {
  double x = 1.2;
  double y = 3.;
  ck_assert_ldouble_eq(s_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s_fmod_4) {
  double x = 5326.;
  double y = 10.;
  ck_assert_ldouble_eq(s_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s_fmod_5) {
  double x = 21523.;
  double y = 4.;
  ck_assert_ldouble_eq(s_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s_fmod_6) {
  double x = 241231.;
  double y = 10.;
  ck_assert_ldouble_eq(s_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s_fmod_7) {
  double x = -211.;
  double y = 1.;
  ck_assert_ldouble_eq(s_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s_fmod_8) {
  double x = 1253.4321542;
  double y = -1.;
  ck_assert_ldouble_eq(s_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s_fmod_9) {
  double x = INFINITY;
  double y = INFINITY;
  ck_assert_ldouble_nan(s_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

START_TEST(s_fmod_10) {
  double x = NAN;
  double y = NAN;
  ck_assert_ldouble_nan(s_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

START_TEST(s_fmod_11) {
  double x = 2029753896.324252;
  double y = 100.;
  ck_assert_ldouble_eq(s_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s_fmod_12) {
  double x = 20.324;
  double y = 0.10;
  ck_assert_ldouble_eq(s_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s_fmod_13) {
  double x = 2029753896.324252;
  double y = NAN;
  ck_assert_ldouble_nan(s_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

START_TEST(s_fmod_14) {
  double x = 2029753896.324252;
  double y = -NAN;
  ck_assert_ldouble_nan(s_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

START_TEST(s_fmod_15) {
  double x = -NAN;
  double y = 1.;
  ck_assert_ldouble_nan(s_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

START_TEST(s_fmod_16) {
  double x = 2029.324252;
  double y = 0.6;
  ck_assert_ldouble_eq_tol(s_fmod(x, y), fmod(x, y), s_EPS);
}
END_TEST

START_TEST(s_fmod_17) {
  double x = 202976.324252;
  double y = INFINITY;
  ck_assert_ldouble_eq(s_fmod(x, y), (fmod(x, y)));
}
END_TEST

START_TEST(s_fmod_18) {
  double x = 202976.324252;
  double y = -INFINITY;
  ck_assert_ldouble_eq(s_fmod(x, y), (fmod(x, y)));
}
END_TEST

START_TEST(s_fmod_19) {
  double x = -INFINITY;
  double y = 4.;
  ck_assert_ldouble_nan(s_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

START_TEST(s_fmod_20) {
  double x = 78.90998;
  double y = 4.21;
  ck_assert_ldouble_eq(s_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s_fmod_21) {
  double x = 3.;
  double y = 0.;
  ck_assert_ldouble_nan(s_fmod(x, y));
}
END_TEST

START_TEST(s_fmod_22) {
  double x = 9.;
  double y = 0.;
  ck_assert_ldouble_nan(s_fmod(x, y));
}
END_TEST

START_TEST(s_fmod_23) {
  srand(time(NULL));
  for (double num = s_EPS; num < DBL_MAX - 1;
       num *= (rand() % 10000) / 1000000. + 3.02) {
    double a = (rand() % 10) + rand() % 100 * s_EPS;
    long double x = s_EPS;
    if (floorl(log10l(fmod(a, num))) >= 10)
      x = s_EPS * pow(10, floorl(log10l(fmod(a, num))) - 10);
    ck_assert_ldouble_eq_tol(s_fmod(a, num), fmod(a, num), x);
  }
}
END_TEST

START_TEST(s_fmod_24) {
  srand(time(NULL));
  for (double num = -DBL_MAX + s_EPS + 1; num < -s_EPS;
       num /= (rand() % 10000) / 1000000. + 3.02) {
    double a = (rand() % 10) + rand() % 100 * s_EPS;
    long double x = s_EPS;
    if (floorl(log10l(fmod(a, num))) >= 10)
      x = s_EPS * pow(10, floorl(log10l(fmod(a, num))) - 10);
    ck_assert_ldouble_eq_tol(s_fmod(a, num), fmod(a, num), x);
  }
}
END_TEST

Suite *test_s_fmod(void) {
  Suite *s = suite_create("\033[45m-=s_FMOD=-\033[0m");
  TCase *tc = tcase_create("s_fmod_tc");

  tcase_add_test(tc, s_fmod_1);
  tcase_add_test(tc, s_fmod_2);
  tcase_add_test(tc, s_fmod_3);
  tcase_add_test(tc, s_fmod_4);
  tcase_add_test(tc, s_fmod_5);
  tcase_add_test(tc, s_fmod_6);
  tcase_add_test(tc, s_fmod_7);
  tcase_add_test(tc, s_fmod_8);
  tcase_add_test(tc, s_fmod_9);
  tcase_add_test(tc, s_fmod_10);
  tcase_add_test(tc, s_fmod_11);
  tcase_add_test(tc, s_fmod_12);
  tcase_add_test(tc, s_fmod_13);
  tcase_add_test(tc, s_fmod_14);
  tcase_add_test(tc, s_fmod_15);
  tcase_add_test(tc, s_fmod_16);
  tcase_add_test(tc, s_fmod_17);
  tcase_add_test(tc, s_fmod_18);
  tcase_add_test(tc, s_fmod_19);
  tcase_add_test(tc, s_fmod_20);
  tcase_add_test(tc, s_fmod_21);
  tcase_add_test(tc, s_fmod_22);
  tcase_add_test(tc, s_fmod_23);
  tcase_add_test(tc, s_fmod_24);

  suite_add_tcase(s, tc);
  return s;
}