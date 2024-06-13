#include "../s21_matrix_test.h"

START_TEST(s21_mult_num_test_1) {
  matrix_t A, result, correct;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1.123;
  double num = 2;
  s21_create_matrix(1, 1, &correct);
  correct.matrix[0][0] = 2.246;
  ck_assert_int_eq(s21_mult_number(&A, num, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &correct), EQUAL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(s21_mult_num_test_2) {
  matrix_t A, correct;
  s21_create_matrix(1, 1, &correct);
  correct.matrix[0][0] = 1.123006;
  ck_assert_int_eq(s21_create_matrix(1, 0, &A), INCORRECT_MATRIX);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(s21_mult_num_test_3) {
  matrix_t A, result, correct;
  double num = 2.6;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2;
  A.matrix[1][0] = 5, A.matrix[1][1] = 6;
  s21_create_matrix(2, 2, &correct);
  correct.matrix[0][0] = 2.6, correct.matrix[0][1] = 5.2;
  correct.matrix[1][0] = 13, correct.matrix[1][1] = 15.6;
  ck_assert_int_eq(s21_mult_number(&A, num, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &correct), EQUAL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(s21_mult_num_test_4) {
  matrix_t A, result;
  double num = 2.6;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 4, A.matrix[1][1] = NAN, A.matrix[1][2] = 6;
  A.matrix[2][0] = 9, A.matrix[2][1] = 10, A.matrix[2][2] = 11;
  ck_assert_int_eq(s21_mult_number(&A, num, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_num_test_5) {
  matrix_t A, result, correct;
  double num = 0.01;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 5, A.matrix[1][1] = 6, A.matrix[1][2] = 7;
  A.matrix[2][0] = 9, A.matrix[2][1] = 10, A.matrix[2][2] = 11;
  s21_create_matrix(3, 3, &correct);
  correct.matrix[0][0] = 0.01, correct.matrix[0][1] = 0.02,
  correct.matrix[0][2] = 0.03;
  correct.matrix[1][0] = 0.05, correct.matrix[1][1] = 0.06,
  correct.matrix[1][2] = 0.07;
  correct.matrix[2][0] = 0.09, correct.matrix[2][1] = 0.1,
  correct.matrix[2][2] = 0.11;
  ck_assert_int_eq(s21_mult_number(&A, num, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &correct), EQUAL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(s21_mult_num_test_6) {
  matrix_t A, result, correct;
  double num = 100;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.23455, A.matrix[0][1] = 2.23455, A.matrix[0][2] = 3.23455;
  A.matrix[1][0] = 5.23455, A.matrix[1][1] = 6.23455, A.matrix[1][2] = 7.23455;
  A.matrix[2][0] = 9.23455, A.matrix[2][1] = 10.23455,
  A.matrix[2][2] = 11.23455;
  s21_create_matrix(3, 3, &correct);
  correct.matrix[0][0] = 123.455, correct.matrix[0][1] = 223.455,
  correct.matrix[0][2] = 323.455;
  correct.matrix[1][0] = 523.455, correct.matrix[1][1] = 623.455,
  correct.matrix[1][2] = 723.455;
  correct.matrix[2][0] = 923.455, correct.matrix[2][1] = 1023.455,
  correct.matrix[2][2] = 1123.455;
  ck_assert_int_eq(s21_mult_number(&A, num, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &correct), EQUAL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct);
}
END_TEST

Suite *suite_mult_num() {
  Suite *suite = suite_create("\x1b[34m[s21_s21_mult_num_matrix]\x1b[0m");
  TCase *tcase_core = tcase_create("s21_mult_num_matrix_tc");
  tcase_add_test(tcase_core, s21_mult_num_test_1);
  tcase_add_test(tcase_core, s21_mult_num_test_2);
  tcase_add_test(tcase_core, s21_mult_num_test_3);
  tcase_add_test(tcase_core, s21_mult_num_test_4);
  tcase_add_test(tcase_core, s21_mult_num_test_5);
  tcase_add_test(tcase_core, s21_mult_num_test_6);

  suite_add_tcase(suite, tcase_core);
  return suite;
}