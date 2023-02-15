#include <time.h>

#include "test_me.h"

START_TEST(s_log_1) {
  double num = INFINITY;
  ck_assert_ldouble_eq(s_log(num), log(num));
}
END_TEST

START_TEST(s_log_2) {
  double num = -INFINITY;
  ck_assert_ldouble_nan(s_log(num));
  ck_assert_ldouble_nan(log(num));
}
END_TEST

START_TEST(s_log_3) {
  double num = NAN;
  ck_assert_ldouble_nan(s_log(num));
  ck_assert_ldouble_nan(log(num));
}
END_TEST

START_TEST(s_log_4) {
  double num = -NAN;
  ck_assert_ldouble_nan(s_log(num));
  ck_assert_ldouble_nan(log(num));
}
END_TEST

START_TEST(s_log_5) {
  double num = 0.1;
  ck_assert_ldouble_eq_tol(s_log(num), log(num), s_EPS);
}
END_TEST

START_TEST(s_log_6) {
  double num = 1.;
  ck_assert_ldouble_eq(s_log(num), log(num));
}
END_TEST

START_TEST(s_log_7) {
  double num = 1.4;
  ck_assert_ldouble_eq_tol(s_log(num), log(num), s_EPS);
}
END_TEST

START_TEST(s_log_8) {
  double num = 1.6;
  ck_assert_ldouble_eq_tol(s_log(num), log(num), s_EPS);
}
END_TEST

START_TEST(s_log_9) {
  double num = 1.32781;
  ck_assert_ldouble_eq_tol(s_log(num), log(num), s_EPS);
}
END_TEST

START_TEST(s_log_10) {
  double num = 43.578;
  ck_assert_ldouble_eq_tol(s_log(num), log(num), s_EPS);
}
END_TEST

START_TEST(s_log_11) {
  double num = 68.123456;
  ck_assert_ldouble_eq_tol(s_log(num), log(num), s_EPS);
}
END_TEST

START_TEST(s_log_12) {
  double num = 5.5;
  ck_assert_ldouble_eq_tol(s_log(num), log(num), s_EPS);
}
END_TEST

START_TEST(s_log_13) {
  double num = 0.0957239;
  ck_assert_ldouble_eq_tol(s_log(num), log(num), s_EPS);
}
END_TEST

START_TEST(s_log_14) {
  double num = 1e-300;
  ck_assert_ldouble_eq_tol(s_log(num), log(num), s_EPS);
}
END_TEST

START_TEST(s_log_15) {
  double num = 1e+300;
  ck_assert_ldouble_eq_tol(s_log(num), log(num), s_EPS);
}
END_TEST

START_TEST(s_log_16) {
  double num = DBL_MAX;
  ck_assert_ldouble_eq_tol(s_log(num), log(num), s_EPS);
}
END_TEST

START_TEST(s_log_17) {
  srand(time(NULL));
  for (double num = DBL_MIN + 1e-6; num <= DBL_MAX;
       num *= (rand() % 10000) / 1000000. + 3.02) {
    ck_assert_ldouble_eq_tol(s_log(num), log(num), s_EPS);
  }
}

START_TEST(s_log_18) {
  double num = 762185.4;
  ck_assert_ldouble_eq_tol(s_log(num), log(num), s_EPS);
}
END_TEST

Suite *test_s_log(void) {
  Suite *s = suite_create("\033[45m-=s_LOG=-\033[0m");
  TCase *tc = tcase_create("s_log_tc");

  tcase_add_test(tc, s_log_1);
  tcase_add_test(tc, s_log_2);
  tcase_add_test(tc, s_log_3);
  tcase_add_test(tc, s_log_4);
  tcase_add_test(tc, s_log_5);
  tcase_add_test(tc, s_log_6);
  tcase_add_test(tc, s_log_7);
  tcase_add_test(tc, s_log_8);
  tcase_add_test(tc, s_log_9);
  tcase_add_test(tc, s_log_10);
  tcase_add_test(tc, s_log_11);
  tcase_add_test(tc, s_log_12);
  tcase_add_test(tc, s_log_13);
  tcase_add_test(tc, s_log_14);
  tcase_add_test(tc, s_log_15);
  tcase_add_test(tc, s_log_16);
  tcase_add_test(tc, s_log_17);
  tcase_add_test(tc, s_log_18);

  suite_add_tcase(s, tc);
  return s;
}
