#include "test_me.h"

START_TEST(s_atan_1) {
  double num = NAN;
  ck_assert_ldouble_nan(s_atan(num));
  ck_assert_ldouble_nan(atan(num));
}
END_TEST

START_TEST(s_atan_2) {
  double num = -NAN;
  ck_assert_ldouble_nan(s_atan(num));
  ck_assert_ldouble_nan(atan(num));
}
END_TEST

START_TEST(s_atan_3) {
  double num = INFINITY;
  ck_assert_ldouble_eq_tol(s_atan(num), atan(num), s_EPS);
}
END_TEST

START_TEST(s_atan_4) {
  double num = -INFINITY;
  ck_assert_ldouble_eq_tol(s_atan(num), atan(num), s_EPS);
}
END_TEST

START_TEST(s_atan_5) {
  double num = 0.;
  ck_assert_ldouble_eq(s_atan(num), atan(num));
}
END_TEST

START_TEST(s_atan_6) {
  double num = 0.5;
  ck_assert_ldouble_eq_tol(s_atan(num), atan(num), s_EPS);
}
END_TEST

START_TEST(s_atan_7) {
  double num = -0.5;
  ck_assert_ldouble_eq_tol(s_atan(num), atan(num), s_EPS);
}
END_TEST

START_TEST(s_atan_8) {
  double num = 0.2;
  ck_assert_ldouble_eq_tol(s_atan(num), atan(num), s_EPS);
}
END_TEST

START_TEST(s_atan_9) {
  double num = -0.6;
  ck_assert_ldouble_eq_tol(s_atan(num), atan(num), s_EPS);
}
END_TEST

START_TEST(s_atan_10) {
  double num = -1;
  ck_assert_ldouble_eq_tol(s_atan(num), atan(num), s_EPS);
}
END_TEST

START_TEST(s_atan_11) {
  double num = 2813568.;
  ck_assert_ldouble_eq_tol(s_atan(num), atan(num), s_EPS);
}
END_TEST

START_TEST(s_atan_12) {
  double num = 55.926;
  ck_assert_ldouble_eq_tol(s_atan(num), atan(num), s_EPS);
}
END_TEST

START_TEST(s_atan_13) {
  srand(time(NULL));
  for (double num = s_EPS; num < DBL_MAX;
       num *= (rand() % 10000) / 1000000. + 3.02) {
    ck_assert_ldouble_eq_tol(s_atan(num), atan(num), s_EPS);
  }
}

START_TEST(s_atan_14) {
  srand(time(NULL));
  for (double num = -DBL_MAX + s_EPS + 1; num < 0;
       num /= (rand() % 10000) / 1000000. + 3.02) {
    ck_assert_ldouble_eq_tol(s_atan(num), atan(num), s_EPS);
  }
}

Suite *test_s_atan(void) {
  Suite *s = suite_create("\033[45m-=s_ATAN=-\033[0m");
  TCase *tc = tcase_create("s_atan_tc");

  tcase_add_test(tc, s_atan_1);
  tcase_add_test(tc, s_atan_2);
  tcase_add_test(tc, s_atan_3);
  tcase_add_test(tc, s_atan_4);
  tcase_add_test(tc, s_atan_5);
  tcase_add_test(tc, s_atan_6);
  tcase_add_test(tc, s_atan_7);
  tcase_add_test(tc, s_atan_8);
  tcase_add_test(tc, s_atan_9);
  tcase_add_test(tc, s_atan_10);
  tcase_add_test(tc, s_atan_11);
  tcase_add_test(tc, s_atan_12);
  tcase_add_test(tc, s_atan_13);
  tcase_add_test(tc, s_atan_14);

  suite_add_tcase(s, tc);
  return s;
}
