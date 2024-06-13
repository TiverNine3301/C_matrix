#include "../s21_matrix_test.h"

START_TEST(calc_complements_1) {
  matrix_t A, result, res_origin;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &res_origin);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  res_origin.matrix[0][0] = 0;
  res_origin.matrix[0][1] = 10;
  res_origin.matrix[0][2] = -20;
  res_origin.matrix[1][0] = 4;
  res_origin.matrix[1][1] = -14;
  res_origin.matrix[1][2] = 8;
  res_origin.matrix[2][0] = -8;
  res_origin.matrix[2][1] = -2;
  res_origin.matrix[2][2] = 4;
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(calc_complements_2) {
  matrix_t A, result, res_origin;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &res_origin);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  res_origin.matrix[0][0] = 3;
  res_origin.matrix[0][1] = -6;
  res_origin.matrix[1][0] = -4;
  res_origin.matrix[1][1] = 2;
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_double_eq_tol(res_origin.matrix[i][j], result.matrix[i][j],
                              ACCURACY);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(calc_complements_3) {
  matrix_t A, result;
  s21_create_matrix(-2, 2, &A);
  int check = s21_calc_complements(&A, &result);
  int check_origin = INCORRECT_MATRIX;
  ck_assert_uint_eq(check, check_origin);
}
END_TEST

START_TEST(calc_complements_4) {
  matrix_t A, result;
  s21_create_matrix(2, 4, &A);
  int check = s21_calc_complements(&A, &result);
  int check_origin = CALCULATION_ERROR;
  ck_assert_uint_eq(check, check_origin);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_calc_complements() {
  Suite *suite = suite_create("\x1b[34m[calc_complements]\x1b[0m");
  TCase *tcase_core = tcase_create("s21_calc_complements_tc");
  tcase_add_test(tcase_core, calc_complements_1);
  tcase_add_test(tcase_core, calc_complements_2);
  tcase_add_test(tcase_core, calc_complements_3);
  tcase_add_test(tcase_core, calc_complements_4);

  suite_add_tcase(suite, tcase_core);
  return suite;
}