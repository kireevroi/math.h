#include "test_me.h"

START_TEST(s_tan_1) {
  double num = NAN;
  ck_assert_ldouble_nan(s_tan(num));
  ck_assert_ldouble_nan(tan(num));
}
END_TEST

START_TEST(s_tan_2) {
  double num = -NAN;
  ck_assert_ldouble_nan(s_tan(num));
  ck_assert_ldouble_nan(tan(num));
}
END_TEST

START_TEST(s_tan_3) {
  double num = INFINITY;
  ck_assert_ldouble_nan(s_tan(num));
  ck_assert_ldouble_nan(tan(num));
}
END_TEST

START_TEST(s_tan_4) {
  double num = -INFINITY;
  ck_assert_ldouble_nan(s_tan(num));
  ck_assert_ldouble_nan(tan(num));
}
END_TEST

START_TEST(s_tan_5) {
  double num = 0.;
  ck_assert_ldouble_eq(s_tan(num), tan(num));
}
END_TEST

START_TEST(s_tan_6) {
  double num = 0.5;
  ck_assert_ldouble_eq_tol(s_tan(num), tan(num), s_EPS);
}
END_TEST

START_TEST(s_tan_7) {
  double num = -0.5;
  ck_assert_ldouble_eq_tol(s_tan(num), tan(num), s_EPS);
}
END_TEST

START_TEST(s_tan_8) {
  double num = 0.2;
  ck_assert_ldouble_eq_tol(s_tan(num), tan(num), s_EPS);
}
END_TEST

START_TEST(s_tan_9) {
  double num = 55.5;
  ck_assert_ldouble_eq_tol(s_tan(num), tan(num), s_EPS);
}
END_TEST

START_TEST(s_tan_10) {
  double num = 1e-10;
  ck_assert_ldouble_eq(s_tan(num), tan(num));
}
END_TEST

START_TEST(s_tan_11) {
  double num = 2185124152.12758289526;
  ck_assert_ldouble_eq_tol(s_tan(num), tan(num), s_EPS);
}
END_TEST

START_TEST(s_tan_12) {
  double num = 1e8;
  ck_assert_ldouble_eq_tol(s_tan(num), tan(num), s_EPS);
}
END_TEST

// START_TEST(s_tan_13) {
//   double num = s_PI / 2.;
//   ck_assert_ldouble_eq_tol(s_tan(num), tan(num), s_EPS);
// }
// END_TEST

// START_TEST(s_tan_14) {
//   double num = - (s_PI / 2.);
//   ck_assert_ldouble_eq_tol(s_tan(num), tan(num), s_EPS);
// }
// END_TEST

START_TEST(s_tan_15) {
  double num = s_PI;
  ck_assert_ldouble_eq_tol(s_tan(num), tan(num), s_EPS);
}
END_TEST

START_TEST(s_tan_16) {
  double num = s_PI;
  ck_assert_ldouble_eq_tol(s_tan(num), tan(num), s_EPS);
}
END_TEST

Suite *test_s_tan(void) {
  Suite *s = suite_create("\033[45m-=s_TAN=-\033[0m");
  TCase *tc = tcase_create("s_tan_tc");

  tcase_add_test(tc, s_tan_1);
  tcase_add_test(tc, s_tan_2);
  tcase_add_test(tc, s_tan_3);
  tcase_add_test(tc, s_tan_4);
  tcase_add_test(tc, s_tan_5);
  tcase_add_test(tc, s_tan_6);
  tcase_add_test(tc, s_tan_7);
  tcase_add_test(tc, s_tan_8);
  tcase_add_test(tc, s_tan_9);
  tcase_add_test(tc, s_tan_10);
  tcase_add_test(tc, s_tan_11);
  tcase_add_test(tc, s_tan_12);
  // tcase_add_test(tc, s_tan_13);
  // tcase_add_test(tc, s_tan_14);
  tcase_add_test(tc, s_tan_15);
  tcase_add_test(tc, s_tan_16);

  suite_add_tcase(s, tc);
  return s;
}
