#include "../s21_matrix_test.h"

START_TEST(eq_test_1) {
  matrix_t A, B;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1.123;
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 1.123;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), EQUAL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_2) {
  matrix_t A, B;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1.12345;
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 1.123006;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), NOT_EQUAL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_3) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2;
  A.matrix[1][0] = 5, A.matrix[1][1] = 6;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1, B.matrix[0][1] = 2;
  B.matrix[1][0] = 5, B.matrix[1][1] = 6;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), EQUAL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_4) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2;
  A.matrix[1][0] = 5, A.matrix[1][1] = 6;
  s21_create_matrix(2, 3, &B);
  B.matrix[0][0] = 1, B.matrix[0][1] = 2, B.matrix[0][2] = 3;
  B.matrix[1][0] = 4, B.matrix[1][1] = 5, B.matrix[1][2] = 6;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), NOT_EQUAL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_5) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 4, A.matrix[1][1] = 5, A.matrix[1][2] = 6;
  A.matrix[2][0] = 9, A.matrix[2][1] = 10, A.matrix[2][2] = 11;
  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 1, B.matrix[0][1] = 2, B.matrix[0][2] = 3;
  B.matrix[1][0] = 4, B.matrix[1][1] = 5, B.matrix[1][2] = 6;
  B.matrix[2][0] = 9, B.matrix[2][1] = 10, B.matrix[2][2] = 11;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), EQUAL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_6) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 5, A.matrix[1][1] = 6, A.matrix[1][2] = 7;
  A.matrix[2][0] = 9, A.matrix[2][1] = 10, A.matrix[2][2] = 11;
  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 1, B.matrix[0][1] = 2, B.matrix[0][2] = 3;
  B.matrix[1][0] = 4, B.matrix[1][1] = 5, B.matrix[1][2] = 6;
  B.matrix[2][0] = 7, B.matrix[2][1] = 8, B.matrix[2][2] = 9;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), NOT_EQUAL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_7) {
  matrix_t A, B;
  s21_create_matrix(3, 4, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3,
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 5, A.matrix[1][1] = 6, A.matrix[1][2] = 7,
  A.matrix[1][3] = 8;
  A.matrix[2][0] = 9, A.matrix[2][1] = 10, A.matrix[2][2] = 11,
  A.matrix[2][3] = 12;
  s21_create_matrix(4, 3, &B);
  B.matrix[0][0] = 1, B.matrix[0][1] = 2, B.matrix[0][2] = 3;
  B.matrix[1][0] = 4, B.matrix[1][1] = 5, B.matrix[1][2] = 6;
  B.matrix[2][0] = 7, B.matrix[2][1] = 8, B.matrix[2][2] = 9;
  B.matrix[3][0] = 10, B.matrix[3][1] = 11, B.matrix[3][2] = 12;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), NOT_EQUAL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_8) {
  matrix_t A, B;
  s21_create_matrix(3, 4, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3,
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 5, A.matrix[1][1] = 6, A.matrix[1][2] = 7,
  A.matrix[1][3] = 8;
  A.matrix[2][0] = 9, A.matrix[2][1] = 10, A.matrix[2][2] = 11,
  A.matrix[2][3] = 12;
  s21_create_matrix(3, 4, &B);
  B.matrix[0][0] = 1, B.matrix[0][1] = 2, B.matrix[0][2] = 3,
  B.matrix[0][3] = 4;
  B.matrix[1][0] = 5, B.matrix[1][1] = 6, B.matrix[1][2] = 7,
  B.matrix[1][3] = 8;
  B.matrix[2][0] = 9, B.matrix[2][1] = 10, B.matrix[2][2] = 11,
  B.matrix[2][3] = 12;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), EQUAL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_9) {
  matrix_t A, B;
  s21_create_matrix(3, 4, &A);
  A.matrix[0][0] = 1.23455, A.matrix[0][1] = 2.23455, A.matrix[0][2] = 3.23455,
  A.matrix[0][3] = 4.23455;
  A.matrix[1][0] = 5.23455, A.matrix[1][1] = 6.23455, A.matrix[1][2] = 7.23455,
  A.matrix[1][3] = 8.23455;
  A.matrix[2][0] = 9.23455, A.matrix[2][1] = 10.23455,
  A.matrix[2][2] = 11.23455, A.matrix[2][3] = 12.23455767;
  s21_create_matrix(3, 4, &B);
  B.matrix[0][0] = 1.23455, B.matrix[0][1] = 2.23455, B.matrix[0][2] = 3.23455,
  B.matrix[0][3] = 4.23455;
  B.matrix[1][0] = 5.23455, B.matrix[1][1] = 6.23455, B.matrix[1][2] = 7.23455,
  B.matrix[1][3] = 8.23455;
  B.matrix[2][0] = 9.23455, B.matrix[2][1] = 10.23455,
  B.matrix[2][2] = 11.23455, B.matrix[2][3] = 12.234557678;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), EQUAL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_10) {
  matrix_t A, B;
  s21_create_matrix(3, 4, &A);
  A.matrix[0][0] = 1.23455, A.matrix[0][1] = 2.23455, A.matrix[0][2] = 3.23455,
  A.matrix[0][3] = 4.23455;
  A.matrix[1][0] = 5.23455, A.matrix[1][1] = 6.23455, A.matrix[1][2] = 7.23455,
  A.matrix[1][3] = 8.23455;
  A.matrix[2][0] = 9, A.matrix[2][1] = 10.23455, A.matrix[2][2] = 11.23455,
  A.matrix[2][3] = 12.23455367;
  s21_create_matrix(3, 4, &B);
  B.matrix[0][0] = 1.23455, B.matrix[0][1] = 2.23455, B.matrix[0][2] = 3.23455,
  B.matrix[0][3] = 4.23455;
  B.matrix[1][0] = 5.23455, B.matrix[1][1] = 6.23455, B.matrix[1][2] = 7.23455,
  B.matrix[1][3] = 8.23455;
  B.matrix[2][0] = 9.23455, B.matrix[2][1] = 10.23455,
  B.matrix[2][2] = 11.23455, B.matrix[2][3] = 12.234557678;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), NOT_EQUAL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_11) {
  matrix_t A, B;
  s21_create_matrix(3, 4, &A);
  A.matrix[0][0] = 1.23455, A.matrix[0][1] = 2.23455, A.matrix[0][2] = 3.23455,
  A.matrix[0][3] = 4.23455;
  A.matrix[1][0] = -5.23455, A.matrix[1][1] = 6.23455, A.matrix[1][2] = 7.23455,
  A.matrix[1][3] = 8.23455;
  A.matrix[2][0] = 9, A.matrix[2][1] = 10.23455, A.matrix[2][2] = 11.23455,
  A.matrix[2][3] = 12.23455767;
  s21_create_matrix(3, 4, &B);
  B.matrix[0][0] = 1.23455, B.matrix[0][1] = 2.23455, B.matrix[0][2] = 3.23455,
  B.matrix[0][3] = 4.23455;
  B.matrix[1][0] = 5.23455, B.matrix[1][1] = 6.23455, B.matrix[1][2] = 7.23455,
  B.matrix[1][3] = 8.23455;
  B.matrix[2][0] = 9.23455, B.matrix[2][1] = 10.23455,
  B.matrix[2][2] = 11.23455, B.matrix[2][3] = 12.234557678;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), NOT_EQUAL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *suite_eq() {
  Suite *suite = suite_create("\x1b[34m[s21_eq_matrix]\x1b[0m");
  TCase *tcase_core = tcase_create("eq_matrix_tc");
  tcase_add_test(tcase_core, eq_test_1);
  tcase_add_test(tcase_core, eq_test_2);
  tcase_add_test(tcase_core, eq_test_3);
  tcase_add_test(tcase_core, eq_test_4);
  tcase_add_test(tcase_core, eq_test_5);
  tcase_add_test(tcase_core, eq_test_6);
  tcase_add_test(tcase_core, eq_test_7);
  tcase_add_test(tcase_core, eq_test_8);
  tcase_add_test(tcase_core, eq_test_9);
  tcase_add_test(tcase_core, eq_test_10);
  tcase_add_test(tcase_core, eq_test_11);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
