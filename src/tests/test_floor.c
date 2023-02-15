#include "test_me.h"

START_TEST(s_floor_1) {
  double num = 0.;
  ck_assert_ldouble_eq(s_floor(num), floor(num));
}
END_TEST

START_TEST(s_floor_2) {
  double num = 5.1;
  ck_assert_ldouble_eq(s_floor(num), floor(num));
}
END_TEST

START_TEST(s_floor_3) {
  double num = 0.144;
  ck_assert_ldouble_eq(s_floor(num), floor(num));
}
END_TEST

START_TEST(s_floor_4) {
  double num = 326088.32;
  ck_assert_ldouble_eq(s_floor(num), floor(num));
}
END_TEST

START_TEST(s_floor_5) {
  double num = 68.6238;
  ck_assert_ldouble_eq(s_floor(num), floor(num));
}
END_TEST

START_TEST(s_floor_6) {
  double num = -21.3;
  ck_assert_ldouble_eq(s_floor(num), floor(num));
}
END_TEST

START_TEST(s_floor_7) {
  double num = 65.739;
  ck_assert_ldouble_eq(s_floor(num), floor(num));
}
END_TEST

START_TEST(s_floor_8) {
  double num = 86.21;
  ck_assert_ldouble_eq(s_floor(num), floor(num));
}
END_TEST

START_TEST(s_floor_9) {
  double num = 231.32;
  ck_assert_ldouble_eq(s_floor(num), floor(num));
}
END_TEST

START_TEST(s_floor_10) {
  double num = -21.0;
  ck_assert_ldouble_eq(s_floor(num), floor(num));
}
END_TEST

START_TEST(s_floor_11) {
  double num = 5.99999999999;
  ck_assert_ldouble_eq(s_floor(num), floor(num));
}
END_TEST

START_TEST(s_floor_12) {
  double num = -5.99999999999;
  ck_assert_ldouble_eq(s_floor(num), floor(num));
}
END_TEST

START_TEST(s_floor_13) {
  double num = -0.000000000000000000000001;
  ck_assert_ldouble_eq(s_floor(num), floor(num));
}
END_TEST

START_TEST(s_floor_14) {
  double num = 5.000000000000000000000001;
  ck_assert_ldouble_eq(s_floor(num), floor(num));
}
END_TEST

START_TEST(s_floor_15) {
  double num = 5.000000000000000001;
  ck_assert_ldouble_eq(s_floor(num), floor(num));
}
END_TEST

START_TEST(s_floor_16) {
  double num = NAN;
  ck_assert_ldouble_nan(s_floor(num));
  ck_assert_ldouble_nan(floor(num));
}
END_TEST

START_TEST(s_floor_17) {
  double num = INFINITY;
  ck_assert_ldouble_eq(s_floor(num), floor(num));
}
END_TEST

START_TEST(s_floor_18) {
  double num = -NAN;
  ck_assert_ldouble_nan(s_floor(num));
  ck_assert_ldouble_nan(floor(num));
}
END_TEST

START_TEST(s_floor_19) {
  double num = -INFINITY;
  ck_assert_ldouble_eq(s_floor(num), floor(num));
}
END_TEST

START_TEST(s_floor_20) {
  double num = 1.;
  ck_assert_ldouble_eq(s_floor(num), floor(num));
}
END_TEST

START_TEST(s_floor_21) {
  srand(time(NULL));
  for (double num = s_EPS; num < 1e18 - 1;
       num *= (rand() % 10000) / 1000000. + 3.02) {
    ck_assert_ldouble_eq_tol(s_floor(num), floor(num), s_EPS);
  }
}

START_TEST(s_floor_22) {
  srand(time(NULL));
  for (double num = -1e18 + s_EPS + 1; num < -s_EPS;
       num /= (rand() % 10000) / 1000000. + 3.02) {
    ck_assert_ldouble_eq_tol(s_floor(num), floor(num), s_EPS);
  }
}
Suite *test_s_floor(void) {
  Suite *s = suite_create("\033[45m-=s_FLOOR=-\033[0m");
  TCase *tc = tcase_create("s_floor_tc");

  tcase_add_test(tc, s_floor_1);
  tcase_add_test(tc, s_floor_2);
  tcase_add_test(tc, s_floor_3);
  tcase_add_test(tc, s_floor_4);
  tcase_add_test(tc, s_floor_5);
  tcase_add_test(tc, s_floor_6);
  tcase_add_test(tc, s_floor_7);
  tcase_add_test(tc, s_floor_8);
  tcase_add_test(tc, s_floor_9);
  tcase_add_test(tc, s_floor_10);
  tcase_add_test(tc, s_floor_11);
  tcase_add_test(tc, s_floor_12);
  tcase_add_test(tc, s_floor_13);
  tcase_add_test(tc, s_floor_14);
  tcase_add_test(tc, s_floor_15);
  tcase_add_test(tc, s_floor_16);
  tcase_add_test(tc, s_floor_17);
  tcase_add_test(tc, s_floor_18);
  tcase_add_test(tc, s_floor_19);
  tcase_add_test(tc, s_floor_20);
  tcase_add_test(tc, s_floor_21);
  tcase_add_test(tc, s_floor_22);

  suite_add_tcase(s, tc);
  return s;
}
