#include "test_me.h"

START_TEST(s21_fmod_1) {
  double x = 0.;
  double y = 3.;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_2) {
  double x = 0.;
  double y = 1.;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_3) {
  double x = 1.2;
  double y = 3.;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_4) {
  double x = 5326.;
  double y = 10.;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_5) {
  double x = 21523.;
  double y = 4.;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_6) {
  double x = 241231.;
  double y = 10.;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_7) {
  double x = -211.;
  double y = 1.;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_8) {
  double x = 1253.4321542;
  double y = -1.;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_9) {
  double x = INFINITY;
  double y = INFINITY;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_10) {
  double x = NAN;
  double y = NAN;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_11) {
  double x = 2029753896.324252;
  double y = 100.;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_12) {
  double x = 20.324;
  double y = 0.10;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_13) {
  double x = 2029753896.324252;
  double y = NAN;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_14) {
  double x = 2029753896.324252;
  double y = -NAN;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_15) {
  double x = -NAN;
  double y = 1.;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_16) {
  double x = 2029.324252;
  double y = 0.6;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_17) {
  double x = 202976.324252;
  double y = INFINITY;
  ck_assert_ldouble_eq(s21_fmod(x, y), (fmod(x, y)));
}
END_TEST

START_TEST(s21_fmod_18) {
  double x = 202976.324252;
  double y = -INFINITY;
  ck_assert_ldouble_eq(s21_fmod(x, y), (fmod(x, y)));
}
END_TEST

START_TEST(s21_fmod_19) {
  double x = -INFINITY;
  double y = 4.;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_20) {
  double x = 78.90998;
  double y = 4.21;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_21) {
  srand(time(NULL));
  for (double num = S21_EPS; num < DBL_MAX - 1;
       num *= (rand() % 10000) / 1000000. + 3.02) {
    double a = (rand() % 10) + rand() % 100 * S21_EPS;
    long double x = S21_EPS;
      if (floorl(log10l(fmod(a, num))) >= 10)
        x = S21_EPS * pow(10, floorl(log10l(fmod(a, num))) - 10);
    ck_assert_ldouble_eq_tol(s21_fmod(a, num), fmod(a, num), x);
  }
}END_TEST

START_TEST(s21_fmod_22) {
  srand(time(NULL));
  for (double num = -DBL_MAX + S21_EPS + 1; num < -S21_EPS;
       num /= (rand() % 10000) / 1000000. + 3.02) {
    double a = (rand() % 10) + rand() % 100 * S21_EPS;
    long double x = S21_EPS;
      if (floorl(log10l(fmod(a, num))) >= 10)
        x = S21_EPS * pow(10, floorl(log10l(fmod(a, num))) - 10);
    ck_assert_ldouble_eq_tol(s21_fmod(a, num), fmod(a, num), x);
  }
}END_TEST

Suite *test_s21_fmod(void) {
  Suite *s = suite_create("\033[45m-=S21_FMOD=-\033[0m");
  TCase *tc = tcase_create("s21_fmod_tc");

  tcase_add_test(tc, s21_fmod_1);
  tcase_add_test(tc, s21_fmod_2);
  tcase_add_test(tc, s21_fmod_3);
  tcase_add_test(tc, s21_fmod_4);
  tcase_add_test(tc, s21_fmod_5);
  tcase_add_test(tc, s21_fmod_6);
  tcase_add_test(tc, s21_fmod_7);
  tcase_add_test(tc, s21_fmod_8);
  tcase_add_test(tc, s21_fmod_9);
  tcase_add_test(tc, s21_fmod_10);
  tcase_add_test(tc, s21_fmod_11);
  tcase_add_test(tc, s21_fmod_12);
  tcase_add_test(tc, s21_fmod_13);
  tcase_add_test(tc, s21_fmod_14);
  tcase_add_test(tc, s21_fmod_15);
  tcase_add_test(tc, s21_fmod_16);
  tcase_add_test(tc, s21_fmod_17);
  tcase_add_test(tc, s21_fmod_18);
  tcase_add_test(tc, s21_fmod_19);
  tcase_add_test(tc, s21_fmod_20);
  tcase_add_test(tc, s21_fmod_21);
  tcase_add_test(tc, s21_fmod_22);

  suite_add_tcase(s, tc);
  return s;
}