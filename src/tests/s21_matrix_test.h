#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"

#define RESET "\x1b[0m"
#define YELLOW_BG "\x1b[103m"
#define BLACK "\x1b[30m"
#define WHITE "\x1b[97m"

#define RED_BG "\x1b[41m"
#define GREEN_BG "\x1b[42m"
#define WHITE_BG "\x1b[47m"
#define GRAY_BG "\x1b[100m"

#define EQUAL 1
#define NOT_EQUAL 0

#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

Suite *suite_eq();
Suite *suite_transpose();
Suite *suite_determinant();
Suite *suite_mult_num();
Suite *suite_sum_matrix();
Suite *suite_sub_matrix();
Suite *suite_mult_matrix();
Suite *suite_calc_complements();
Suite *suite_inverse_matrix();

void run();
