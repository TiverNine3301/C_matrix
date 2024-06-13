#include "../s21_matrix_test.h"

START_TEST(test_inverse_matrix_1) {
  matrix_t A, result, res_origin;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &res_origin);
  A.matrix[0][0] = 2, A.matrix[0][1] = 5, A.matrix[0][2] = 7;
  A.matrix[1][0] = 6, A.matrix[1][1] = 3, A.matrix[1][2] = 4;
  A.matrix[2][0] = 5, A.matrix[2][1] = -2, A.matrix[2][2] = -3;

  res_origin.matrix[0][0] = 1, res_origin.matrix[0][1] = -1,
  res_origin.matrix[0][2] = 1;
  res_origin.matrix[1][0] = -38, res_origin.matrix[1][1] = 41,
  res_origin.matrix[1][2] = -34;
  res_origin.matrix[2][0] = 27, res_origin.matrix[2][1] = -29,
  res_origin.matrix[2][2] = 24;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], res_origin.matrix[i][j],
                              ACCURACY);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(test_inverse_matrix_2) {
  matrix_t A, result, res_origin;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &res_origin);
  A.matrix[0][0] = 2, A.matrix[0][1] = 1.3, A.matrix[0][2] = 0.7;
  A.matrix[1][0] = -1, A.matrix[1][1] = 0, A.matrix[1][2] = 3;
  A.matrix[2][0] = 0.3, A.matrix[2][1] = -0.3, A.matrix[2][2] = 2;
  res_origin.matrix[0][0] = 45.0 / 289.0,
  res_origin.matrix[0][1] = -281.0 / 578.0,
  res_origin.matrix[0][2] = 195.0 / 289.0;
  res_origin.matrix[1][0] = 145.0 / 289.0,
  res_origin.matrix[1][1] = 379.0 / 578.0,
  res_origin.matrix[1][2] = -335.0 / 289.0;
  res_origin.matrix[2][0] = 15.0 / 289.0,
  res_origin.matrix[2][1] = 99.0 / 578.0,
  res_origin.matrix[2][2] = 65.0 / 289.0;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], res_origin.matrix[i][j],
                              ACCURACY);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(test_inverse_matrix_3) {
  matrix_t A, result, res_origin;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &res_origin);
  A.matrix[0][0] = 2.8, A.matrix[0][1] = 1.3, A.matrix[0][2] = 7.01;
  A.matrix[1][0] = -1.03, A.matrix[1][1] = -2.3, A.matrix[1][2] = 3.01;
  A.matrix[2][0] = 0, A.matrix[2][1] = -3, A.matrix[2][2] = 2;
  res_origin.matrix[0][0] = 44300.0 / 367429.0,
  res_origin.matrix[0][1] = -236300.0 / 367429.0,
  res_origin.matrix[0][2] = 200360.0 / 367429.0;
  res_origin.matrix[1][0] = 20600.0 / 367429.0,
  res_origin.matrix[1][1] = 56000.0 / 367429.0,
  res_origin.matrix[1][2] = -156483.0 / 367429.0;
  res_origin.matrix[2][0] = 30900.0 / 367429.0,
  res_origin.matrix[2][1] = 84000.0 / 367429.0,
  res_origin.matrix[2][2] = -51010.0 / 367429.0;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], res_origin.matrix[i][j],
                              ACCURACY);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(test_inverse_matrix_4) {
  matrix_t A, result, res_origin;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &res_origin);
  A.matrix[0][0] = 777;
  res_origin.matrix[0][0] = 1.0 / 777.0;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_double_eq_tol(res_origin.matrix[0][0], result.matrix[0][0],
                          ACCURACY);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(test_inverse_matrix_5) {
  matrix_t A, result;
  s21_create_matrix(-5, 5, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_inverse_matrix_6) {
  matrix_t A, result;
  s21_create_matrix(1, 2, &A);
  A.matrix[0][0] = 777;
  A.matrix[0][1] = 777;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_matrix_7) {
  matrix_t A, result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_inverse_matrix() {
  Suite *suite = suite_create("\x1b[34m[inverse_matrix]\x1b[0m");
  TCase *tcase_core = tcase_create("inverset_matrix_tc");
  tcase_add_test(tcase_core, test_inverse_matrix_1);
  tcase_add_test(tcase_core, test_inverse_matrix_2);
  tcase_add_test(tcase_core, test_inverse_matrix_3);
  tcase_add_test(tcase_core, test_inverse_matrix_4);
  tcase_add_test(tcase_core, test_inverse_matrix_5);
  tcase_add_test(tcase_core, test_inverse_matrix_6);
  tcase_add_test(tcase_core, test_inverse_matrix_7);

  suite_add_tcase(suite, tcase_core);
  return suite;
}