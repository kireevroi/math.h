#ifndef SRC_TESTS_ME_H
#define SRC_TESTS_ME_H

#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "../s_math.h"

Suite *test_s_abs(void);
Suite *test_s_acos(void);
Suite *test_s_asin(void);
Suite *test_s_atan(void);
Suite *test_s_ceil(void);
Suite *test_s_cos(void);
Suite *test_s_exp(void);
Suite *test_s_fabs(void);
Suite *test_s_floor(void);
Suite *test_s_fmod(void);
Suite *test_s_log(void);
Suite *test_s_pow(void);
Suite *test_s_sin(void);
Suite *test_s_sqrt(void);
Suite *test_s_tan(void);

#endif  // SRC_TESTS_ME_H
