#include "../s21_matrix_test.h"

START_TEST(transpose_test_1) {
  matrix_t A, result, correct;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1.123;
  s21_create_matrix(1, 1, &correct);
  correct.matrix[0][0] = 1.123;
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &correct), EQUAL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(transpose_test_2) {
  matrix_t A, correct;
  s21_create_matrix(1, 1, &correct);
  correct.matrix[0][0] = 1.123006;
  ck_assert_int_eq(s21_create_matrix(1, 0, &A), INCORRECT_MATRIX);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(transpose_test_3) {
  matrix_t A, result, correct;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2;
  A.matrix[1][0] = 5, A.matrix[1][1] = 6;
  s21_create_matrix(2, 2, &correct);
  correct.matrix[0][0] = 1, correct.matrix[0][1] = 5;
  correct.matrix[1][0] = 2, correct.matrix[1][1] = 6;
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &correct), EQUAL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(transpose_test_4) {
  matrix_t A, result;
  s21_create_matrix(2, -2, &A);
  ck_assert_int_eq(s21_transpose(&A, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(transpose_test_5) {
  matrix_t A, result, correct;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 4, A.matrix[1][1] = NAN, A.matrix[1][2] = 6;
  A.matrix[2][0] = 9, A.matrix[2][1] = 10, A.matrix[2][2] = 11;
  s21_create_matrix(3, 3, &correct);
  correct.matrix[0][0] = 1, correct.matrix[0][1] = 2, correct.matrix[0][2] = 3;
  correct.matrix[1][0] = 4, correct.matrix[1][1] = 5, correct.matrix[1][2] = 6;
  correct.matrix[2][0] = 9, correct.matrix[2][1] = 10,
  correct.matrix[2][2] = 11;
  ck_assert_int_eq(s21_transpose(&A, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(transpose_test_6) {
  matrix_t A, result, correct;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 5, A.matrix[1][1] = 6, A.matrix[1][2] = 7;
  A.matrix[2][0] = 9, A.matrix[2][1] = 10, A.matrix[2][2] = 11;
  s21_create_matrix(3, 3, &correct);
  correct.matrix[0][0] = 1, correct.matrix[0][1] = 5, correct.matrix[0][2] = 9;
  correct.matrix[1][0] = 2, correct.matrix[1][1] = 6, correct.matrix[1][2] = 10;
  correct.matrix[2][0] = 3, correct.matrix[2][1] = 7, correct.matrix[2][2] = 11;
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &correct), EQUAL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(transpose_test_7) {
  matrix_t A, result, correct;
  s21_create_matrix(3, 4, &A);
  A.matrix[0][0] = 1.23455, A.matrix[0][1] = 2.23455, A.matrix[0][2] = 3.23455,
  A.matrix[0][3] = 4.23455;
  A.matrix[1][0] = 5.23455, A.matrix[1][1] = 6.23455, A.matrix[1][2] = 7.23455,
  A.matrix[1][3] = 8.23455;
  A.matrix[2][0] = 9.23455, A.matrix[2][1] = 10.23455,
  A.matrix[2][2] = 11.23455, A.matrix[2][3] = 12.23455767;
  s21_create_matrix(4, 3, &correct);
  correct.matrix[0][0] = 1.23455, correct.matrix[0][1] = 5.23455,
  correct.matrix[0][2] = 9.23455;
  correct.matrix[1][0] = 2.23455, correct.matrix[1][1] = 6.23455,
  correct.matrix[1][2] = 10.23455;
  correct.matrix[2][0] = 3.23455, correct.matrix[2][1] = 7.23455,
  correct.matrix[2][2] = 11.23455;
  correct.matrix[3][0] = 4.23455, correct.matrix[3][1] = 8.23455,
  correct.matrix[3][2] = 12.23455767;
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &correct), EQUAL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(transpose_test_8) {
  matrix_t A, result, correct;
  s21_create_matrix(1, 4, &A);
  A.matrix[0][0] = 1.23455, A.matrix[0][1] = 2.23455, A.matrix[0][2] = 3.23455,
  A.matrix[0][3] = 4.23455;
  s21_create_matrix(4, 1, &correct);
  correct.matrix[0][0] = 1.23455;
  correct.matrix[1][0] = 2.23455;
  correct.matrix[2][0] = 3.23455;
  correct.matrix[3][0] = 4.23455;
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &correct), EQUAL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(transpose_test_9) {
  matrix_t A, result, correct;
  s21_create_matrix(1, 4, &correct);
  correct.matrix[0][0] = 1.23455, correct.matrix[0][1] = 2.23455,
  correct.matrix[0][2] = 3.23455, correct.matrix[0][3] = 4.23455;
  s21_create_matrix(4, 1, &A);
  A.matrix[0][0] = 1.23455;
  A.matrix[1][0] = 2.23455;
  A.matrix[2][0] = 3.23455;
  A.matrix[3][0] = 4.23455;
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &correct), EQUAL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct);
}
END_TEST

Suite *suite_transpose() {
  Suite *suite = suite_create("\x1b[34m[s21_transpose_matrix]\x1b[0m");
  TCase *tcase_core = tcase_create("transpose_matrix_tc");
  tcase_add_test(tcase_core, transpose_test_1);
  tcase_add_test(tcase_core, transpose_test_2);
  tcase_add_test(tcase_core, transpose_test_3);
  tcase_add_test(tcase_core, transpose_test_4);
  tcase_add_test(tcase_core, transpose_test_5);
  tcase_add_test(tcase_core, transpose_test_6);
  tcase_add_test(tcase_core, transpose_test_7);
  tcase_add_test(tcase_core, transpose_test_8);
  tcase_add_test(tcase_core, transpose_test_9);

  suite_add_tcase(suite, tcase_core);
  return suite;
}