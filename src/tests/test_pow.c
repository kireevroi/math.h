#include "test_me.h"

START_TEST(s21_pow_0) {
  double a = 0.;
  double b = 0.;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_1) {
  double a = 0.;
  double b = -5.;
  ck_assert_ldouble_infinite(s21_pow(a, b));
  ck_assert_ldouble_infinite(pow(a, b));
}
END_TEST

START_TEST(s21_pow_2) {
  double a = 3.46;
  double b = -4.5;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_3) {
  double a = -6.;
  double b = 2.2;
  ck_assert_ldouble_nan(s21_pow(a, b));
  ck_assert_ldouble_nan(pow(a, b));
}
END_TEST

START_TEST(s21_pow_4) {
  double a = -5.;
  double b = -3.5;
  ck_assert_ldouble_nan(s21_pow(a, b));
  ck_assert_ldouble_nan(pow(a, b));
}
END_TEST

START_TEST(s21_pow_5) {
  double a = 32.3;
  double b = NAN;
  ck_assert_ldouble_nan(s21_pow(a, b));
  ck_assert_ldouble_nan(pow(a, b));
}
END_TEST

START_TEST(s21_pow_6) {
  double a = 0.321;
  double b = -NAN;
  ck_assert_ldouble_nan(s21_pow(a, b));
  ck_assert_ldouble_nan(pow(a, b));
}
END_TEST

START_TEST(s21_pow_7) {
  double a = -NAN;
  double b = 1.;
  ck_assert_ldouble_nan(s21_pow(a, b));
  ck_assert_ldouble_nan(pow(a, b));
}
END_TEST

START_TEST(s21_pow_8) {
  double a = NAN;
  double b = 36.32;
  ck_assert_ldouble_nan(s21_pow(a, b));
  ck_assert_ldouble_nan(pow(a, b));
}
END_TEST

START_TEST(s21_pow_9) {
  double a = NAN;
  double b = NAN;
  ck_assert_ldouble_nan(s21_pow(a, b));
  ck_assert_ldouble_nan(pow(a, b));
}
END_TEST

START_TEST(s21_pow_10) {
  double a = NAN;
  double b = 10.;
  ck_assert_ldouble_nan(s21_pow(a, b));
  ck_assert_ldouble_nan(pow(a, b));
}
END_TEST

START_TEST(s21_pow_11) {
  double a = 3.;
  double b = NAN;
  ck_assert_ldouble_nan(s21_pow(a, b));
  ck_assert_ldouble_nan(pow(a, b));
}
END_TEST

START_TEST(s21_pow_12) {
  double a = 1.;
  double b = 3.;
  ck_assert_ldouble_eq(s21_pow(a, b), pow(a, b));
}
END_TEST

START_TEST(s21_pow_13) {
  double a = 1.;
  double b = NAN;
  ck_assert_ldouble_eq(s21_pow(a, b), pow(a, b));
}
END_TEST

START_TEST(s21_pow_14) {
  double a = 1.;
  double b = -NAN;
  ck_assert_ldouble_eq(s21_pow(a, b), pow(a, b));
}
END_TEST

START_TEST(s21_pow_15) {
  double a = 45.;
  double b = 0.;
  ck_assert_ldouble_eq(s21_pow(a, b), pow(a, b));
}
END_TEST

START_TEST(s21_pow_16) {
  double a = NAN;
  double b = 0.;
  ck_assert_ldouble_eq(s21_pow(a, b), pow(a, b));
}
END_TEST

START_TEST(s21_pow_17) {
  double a = -NAN;
  double b = 0.;
  ck_assert_ldouble_eq(s21_pow(a, b), pow(a, b));
}
END_TEST

START_TEST(s21_pow_18) {
  double a = -INFINITY;
  double b = 0.;
  ck_assert_ldouble_eq(s21_pow(a, b), pow(a, b));
}
END_TEST

START_TEST(s21_pow_19) {
  double a = -0.;
  double b = 5.;
  ck_assert_ldouble_eq(s21_pow(a, b), pow(a, b));
}
END_TEST

START_TEST(s21_pow_20) {
  double a = -0.;
  double b = 79.;
  ck_assert_ldouble_eq(s21_pow(a, b), pow(a, b));
}
END_TEST

START_TEST(s21_pow_21) {
  double a = -0;
  double b = 6.6;
  ck_assert_ldouble_eq(s21_pow(a, b), pow(a, b));
}
END_TEST

START_TEST(s21_pow_22) {
  double a = -0;
  double b = 6.;
  ck_assert_ldouble_eq(s21_pow(a, b), pow(a, b));
}
END_TEST

START_TEST(s21_pow_23) {
  double a = 1.0;
  double b = -INFINITY;
  ck_assert_ldouble_eq(s21_pow(a, b), pow(a, b));
}
END_TEST

START_TEST(s21_pow_24) {
  double a = 1.0;
  double b = INFINITY;
  ck_assert_ldouble_eq(s21_pow(a, b), pow(a, b));
}
END_TEST

START_TEST(s21_pow_25) {
  double a = 1.0;
  double b = -6.;
  ck_assert_ldouble_eq(s21_pow(a, b), pow(a, b));
}
END_TEST

START_TEST(s21_pow_26) {
  double a = 0.55;
  double b = -INFINITY;
  ck_assert_ldouble_infinite(s21_pow(a, b));
  ck_assert_ldouble_infinite(pow(a, b));
}
END_TEST

START_TEST(s21_pow_27) {
  double a = 0.55;
  double b = INFINITY;
  ck_assert_ldouble_eq(s21_pow(a, b), pow(a, b));
}
END_TEST

START_TEST(s21_pow_28) {
  double a = 1.5;
  double b = INFINITY;
  ck_assert_ldouble_infinite(s21_pow(a, b));
  ck_assert_ldouble_infinite(pow(a, b));
}
END_TEST

START_TEST(s21_pow_29) {
  double a = 1.55;
  double b = -INFINITY;
  ck_assert_ldouble_eq(s21_pow(a, b), pow(a, b));
}
END_TEST

START_TEST(s21_pow_30) {
  double a = -INFINITY;
  double b = -3.;
  ck_assert_ldouble_eq(s21_pow(a, b), pow(a, b));
}
END_TEST

START_TEST(s21_pow_31) {
  double a = -INFINITY;
  double b = -4.;
  ck_assert_ldouble_eq(s21_pow(a, b), pow(a, b));
}
END_TEST

START_TEST(s21_pow_32) {
  double a = INFINITY;
  double b = -3.;
  ck_assert_ldouble_eq(s21_pow(a, b), pow(a, b));
}
END_TEST

START_TEST(s21_pow_33) {
  double a = INFINITY;
  double b = 4.;
  ck_assert_ldouble_infinite(s21_pow(a, b));
  ck_assert_ldouble_infinite(pow(a, b));
}
END_TEST

START_TEST(s21_pow_34) {
  double a = -NAN;
  double b = 1.5;
  ck_assert_ldouble_nan(s21_pow(a, b));
  ck_assert_ldouble_nan(pow(a, b));
}
END_TEST

START_TEST(s21_pow_35) {
  double a = INFINITY;
  double b = 1.5;
  ck_assert_ldouble_infinite(s21_pow(a, b));
  ck_assert_ldouble_infinite(pow(a, b));
}
END_TEST

START_TEST(s21_pow_36) {
  double a = -INFINITY;
  double b = 1.5;
  ck_assert_ldouble_infinite(s21_pow(a, b));
  ck_assert_ldouble_infinite(pow(a, b));
}
END_TEST

START_TEST(s21_pow_37) {
  double a = INFINITY;
  double b = INFINITY;
  ck_assert_ldouble_infinite(s21_pow(a, b));
  ck_assert_ldouble_infinite(pow(a, b));
}
END_TEST

START_TEST(s21_pow_38) {
  double a = 1.3;
  double b = 1.5;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_39) {
  double a = 3.213;
  double b = 12.99;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_40) {
  double a = 1.213;
  double b = 12.99;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), powl(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_41) {
  double a = 1.3;
  double b = 1.5;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_42) {
  double a = 21.287287;
  double b = 6.453;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_43) {
  double a = 0.;
  double b = 5.;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_44) {
  double a = 32.3;
  double b = 3.;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_45) {
  double a = 0.321;
  double b = 3.;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_46) {
  double a = -3.;
  double b = -5.;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_47) {
  double a = -3.;
  double b = 3.3;
  ck_assert_ldouble_nan(s21_pow(a, b));
  ck_assert_ldouble_nan(pow(a, b));
}
END_TEST

START_TEST(s21_pow_48) {
  double a = -4.;
  double b = -5.;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_49) {
  double a = -39.213;
  double b = -2.0;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_50) {
  double a = -3.;
  double b = 2.;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_51) {
  double a = -3.;
  double b = 2.0000000005;
  ck_assert_ldouble_nan(s21_pow(a, b));
  ck_assert_ldouble_nan(pow(a, b));
}
END_TEST

START_TEST(s21_pow_52) {
  double a = -3.;
  double b = 3.;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_53) {
  double a = -3.;
  double b = -3.3;
  ck_assert_ldouble_nan(s21_pow(a, b));
  ck_assert_ldouble_nan(pow(a, b));
}
END_TEST

START_TEST(s21_pow_54) {
  double a = 21.287287;
  double b = 7.453;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_55) {
  double a = 32.3;
  double b = 3.;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_56) {
  double a = 5.3;
  double b = 12.99;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_57) {
  srand(time(NULL));
  for (double num = S21_EPS; num <= 100. - S21_EPS; num += 1.06) {
    double a = (rand() % 100) + rand() % 10 * S21_EPS;
    if (pow(a, num) < 1e9) {
      long double x = S21_EPS;
      ck_assert_ldouble_eq_tol(s21_pow(a, num), pow(a, num), x);
    }
  }
}
END_TEST
START_TEST(s21_pow_58) {
  double a = 34.000008;
  double b = 6.360001;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_59) {
  double a = 0.000004;
  double b = 95.400001;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_60) {
  double a = -1.;
  double b = INFINITY;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_61) {
  double a = -1.;
  double b = -INFINITY;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_62) {
  double a = -1.;
  double b = 1.;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_63) {
  double a = -INFINITY;
  double b = -2.;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_64) {
  double a = -INFINITY;
  double b = -1.;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_65) {
  double a = -INFINITY;
  double b = 2.;
  ck_assert_ldouble_infinite(s21_pow(a, b));
  ck_assert_ldouble_infinite(pow(a, b));
}
END_TEST

START_TEST(s21_pow_66) {
  double a = -INFINITY;
  double b = 1.;
  ck_assert_ldouble_infinite(s21_pow(a, b));
  ck_assert_ldouble_infinite(pow(a, b));
}
END_TEST

START_TEST(s21_pow_67) {
  double a = 0.;
  double b = 2.;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_68) {
  double a = 0.;
  double b = 1.1;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_69) {
  double a = 0.;
  double b = -2.;
  ck_assert_ldouble_infinite(s21_pow(a, b));
  ck_assert_ldouble_infinite(pow(a, b));
}
END_TEST

START_TEST(s21_pow_70) {
  double a = -INFINITY;
  double b = -3.3;
  ck_assert_ldouble_eq(s21_pow(a, b), pow(a, b));
}
END_TEST

Suite *test_s21_pow(void) {
  Suite *s = suite_create("\033[45m-=S21_POW=-\033[0m");
  TCase *tc = tcase_create("s21_pow_tc");

  tcase_add_test(tc, s21_pow_0);
  tcase_add_test(tc, s21_pow_1);
  tcase_add_test(tc, s21_pow_2);
  tcase_add_test(tc, s21_pow_3);
  tcase_add_test(tc, s21_pow_4);
  tcase_add_test(tc, s21_pow_5);
  tcase_add_test(tc, s21_pow_6);
  tcase_add_test(tc, s21_pow_7);
  tcase_add_test(tc, s21_pow_8);
  tcase_add_test(tc, s21_pow_9);
  tcase_add_test(tc, s21_pow_10);
  tcase_add_test(tc, s21_pow_11);
  tcase_add_test(tc, s21_pow_12);
  tcase_add_test(tc, s21_pow_13);
  tcase_add_test(tc, s21_pow_14);
  tcase_add_test(tc, s21_pow_15);
  tcase_add_test(tc, s21_pow_16);
  tcase_add_test(tc, s21_pow_17);
  tcase_add_test(tc, s21_pow_18);
  tcase_add_test(tc, s21_pow_19);
  tcase_add_test(tc, s21_pow_20);
  tcase_add_test(tc, s21_pow_21);
  tcase_add_test(tc, s21_pow_22);
  tcase_add_test(tc, s21_pow_23);
  tcase_add_test(tc, s21_pow_24);
  tcase_add_test(tc, s21_pow_25);
  tcase_add_test(tc, s21_pow_26);
  tcase_add_test(tc, s21_pow_27);
  tcase_add_test(tc, s21_pow_28);
  tcase_add_test(tc, s21_pow_29);
  tcase_add_test(tc, s21_pow_30);
  tcase_add_test(tc, s21_pow_31);
  tcase_add_test(tc, s21_pow_32);
  tcase_add_test(tc, s21_pow_33);
  tcase_add_test(tc, s21_pow_34);
  tcase_add_test(tc, s21_pow_35);
  tcase_add_test(tc, s21_pow_36);
  tcase_add_test(tc, s21_pow_37);
  tcase_add_test(tc, s21_pow_38);
  tcase_add_test(tc, s21_pow_39);
  tcase_add_test(tc, s21_pow_40);
  tcase_add_test(tc, s21_pow_41);
  tcase_add_test(tc, s21_pow_42);
  tcase_add_test(tc, s21_pow_43);
  tcase_add_test(tc, s21_pow_44);
  tcase_add_test(tc, s21_pow_45);
  tcase_add_test(tc, s21_pow_46);
  tcase_add_test(tc, s21_pow_47);
  tcase_add_test(tc, s21_pow_48);
  tcase_add_test(tc, s21_pow_49);
  tcase_add_test(tc, s21_pow_50);
  tcase_add_test(tc, s21_pow_51);
  tcase_add_test(tc, s21_pow_52);
  tcase_add_test(tc, s21_pow_53);
  tcase_add_test(tc, s21_pow_54);
  tcase_add_test(tc, s21_pow_55);
  tcase_add_test(tc, s21_pow_56);
  tcase_add_test(tc, s21_pow_57);
  tcase_add_test(tc, s21_pow_58);
  tcase_add_test(tc, s21_pow_59);
  tcase_add_test(tc, s21_pow_60);
  tcase_add_test(tc, s21_pow_61);
  tcase_add_test(tc, s21_pow_62);
  tcase_add_test(tc, s21_pow_63);
  tcase_add_test(tc, s21_pow_64);
  tcase_add_test(tc, s21_pow_65);
  tcase_add_test(tc, s21_pow_66);
  tcase_add_test(tc, s21_pow_67);
  tcase_add_test(tc, s21_pow_68);
  tcase_add_test(tc, s21_pow_69);
  tcase_add_test(tc, s21_pow_70);

  suite_add_tcase(s, tc);
  return s;
}