#include "test_me.h"

START_TEST(s21_tan_1) {
  double num = NAN;
  ck_assert_ldouble_nan(s21_tan(num));
  ck_assert_ldouble_nan(tan(num));
}
END_TEST

START_TEST(s21_tan_2) {
  double num = -NAN;
  ck_assert_ldouble_nan(s21_tan(num));
  ck_assert_ldouble_nan(tan(num));
}
END_TEST

START_TEST(s21_tan_3) {
  double num = INFINITY;
  ck_assert_ldouble_nan(s21_tan(num));
  ck_assert_ldouble_nan(tan(num));
}
END_TEST

START_TEST(s21_tan_4) {
  double num = -INFINITY;
  ck_assert_ldouble_nan(s21_tan(num));
  ck_assert_ldouble_nan(tan(num));
}
END_TEST

START_TEST(s21_tan_5) {
  double num = 0.;
  ck_assert_ldouble_eq(s21_tan(num), tan(num));
}
END_TEST

START_TEST(s21_tan_6) {
  double num = 0.5;
  ck_assert_ldouble_eq_tol(s21_tan(num), tan(num), S21_EPS);
}
END_TEST

START_TEST(s21_tan_7) {
  double num = -0.5;
  ck_assert_ldouble_eq_tol(s21_tan(num), tan(num), S21_EPS);
}
END_TEST

START_TEST(s21_tan_8) {
  double num = 0.2;
  ck_assert_ldouble_eq_tol(s21_tan(num), tan(num), S21_EPS);
}
END_TEST

START_TEST(s21_tan_9) {
  double num = 55.5;
  ck_assert_ldouble_eq_tol(s21_tan(num), tan(num), S21_EPS);
}
END_TEST

START_TEST(s21_tan_10) {
  double num = 1e-10;
  ck_assert_ldouble_eq(s21_tan(num), tan(num));
}
END_TEST

START_TEST(s21_tan_11) {
  double num = 2185124152.12758289526;
  ck_assert_ldouble_eq_tol(s21_tan(num), tan(num), S21_EPS);
}
END_TEST

START_TEST(s21_tan_12) {
  double num = 1e8;
  ck_assert_ldouble_eq_tol(s21_tan(num), tan(num), S21_EPS);
}
END_TEST

// START_TEST(s21_tan_13) {
//   double num = S21_PI / 2.;
//   ck_assert_ldouble_eq_tol(s21_tan(num), tan(num), S21_EPS);
// }
// END_TEST

// START_TEST(s21_tan_14) {
//   double num = - (S21_PI / 2.);
//   ck_assert_ldouble_eq_tol(s21_tan(num), tan(num), S21_EPS);
// }
// END_TEST

START_TEST(s21_tan_15) {
  double num = S21_PI;
  ck_assert_ldouble_eq_tol(s21_tan(num), tan(num), S21_EPS);
}
END_TEST

START_TEST(s21_tan_16) {
  double num = S21_PI;
  ck_assert_ldouble_eq_tol(s21_tan(num), tan(num), S21_EPS);
}
END_TEST

Suite *test_s21_tan(void) {
  Suite *s = suite_create("\033[45m-=S21_TAN=-\033[0m");
  TCase *tc = tcase_create("s21_tan_tc");

  tcase_add_test(tc, s21_tan_1);
  tcase_add_test(tc, s21_tan_2);
  tcase_add_test(tc, s21_tan_3);
  tcase_add_test(tc, s21_tan_4);
  tcase_add_test(tc, s21_tan_5);
  tcase_add_test(tc, s21_tan_6);
  tcase_add_test(tc, s21_tan_7);
  tcase_add_test(tc, s21_tan_8);
  tcase_add_test(tc, s21_tan_9);
  tcase_add_test(tc, s21_tan_10);
  tcase_add_test(tc, s21_tan_11);
  tcase_add_test(tc, s21_tan_12);
  // tcase_add_test(tc, s21_tan_13);
  // tcase_add_test(tc, s21_tan_14);
  tcase_add_test(tc, s21_tan_15);
  tcase_add_test(tc, s21_tan_16);

  suite_add_tcase(s, tc);
  return s;
}
