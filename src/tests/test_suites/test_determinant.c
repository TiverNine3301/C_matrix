#include "../s21_matrix_test.h"

START_TEST(determinant_test_1) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1.123;
  double result;
  double correct = 1.123;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(result, correct, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_2) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(1, 0, &A), INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_test_3) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2;
  A.matrix[1][0] = 5, A.matrix[1][1] = 6;
  double result;
  double correct = -4;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(result, correct, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_4) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 4, A.matrix[1][1] = NAN, A.matrix[1][2] = 6;
  A.matrix[2][0] = 9, A.matrix[2][1] = 10, A.matrix[2][2] = 11;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_5) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 5, A.matrix[1][1] = 6, A.matrix[1][2] = 7;
  A.matrix[2][0] = 9, A.matrix[2][1] = 10, A.matrix[2][2] = 11;
  double result;
  double correct = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(result, correct, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_6) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 67, A.matrix[1][2] = 78;
  A.matrix[2][0] = 0, A.matrix[2][1] = 10, A.matrix[2][2] = 11;
  double result;
  double correct = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(result, correct, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_7) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 14, A.matrix[0][1] = 2, A.matrix[0][2] = 3.444;
  A.matrix[1][0] = 5, A.matrix[1][1] = 65.6, A.matrix[1][2] = 7;
  A.matrix[2][0] = 9, A.matrix[2][1] = 10, A.matrix[2][2] = 11;
  double result;
  double correct = 7277.2624;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(result, correct, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_8) {
  matrix_t A;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3,
  A.matrix[0][3] = 28;
  A.matrix[1][0] = 53.5, A.matrix[1][1] = -6, A.matrix[1][2] = 73,
  A.matrix[1][3] = 56.78;
  A.matrix[2][0] = 5, A.matrix[2][1] = 664, A.matrix[2][2] = -12,
  A.matrix[2][3] = 35;
  A.matrix[3][0] = 9, A.matrix[3][1] = -0.6, A.matrix[3][2] = 2.34,
  A.matrix[3][3] = 3;
  double result;
  double correct = 9080237.4048;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(result, correct, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_determinant() {
  Suite *suite = suite_create("\x1b[34m[s21_determinant]\x1b[0m");
  TCase *tcase_core = tcase_create("determinant_tc");
  tcase_add_test(tcase_core, determinant_test_1);
  tcase_add_test(tcase_core, determinant_test_2);
  tcase_add_test(tcase_core, determinant_test_3);
  tcase_add_test(tcase_core, determinant_test_4);
  tcase_add_test(tcase_core, determinant_test_5);
  tcase_add_test(tcase_core, determinant_test_6);
  tcase_add_test(tcase_core, determinant_test_7);
  tcase_add_test(tcase_core, determinant_test_8);

  suite_add_tcase(suite, tcase_core);
  return suite;
}