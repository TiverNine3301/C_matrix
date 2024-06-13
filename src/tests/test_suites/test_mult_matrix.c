#include "../s21_matrix_test.h"

START_TEST(mult_matrix_1) {
  matrix_t A, B, result, res_origin;
  int check_origin = 0;
  int check_1 = s21_create_matrix(5, 4, &A);
  int check_2 = s21_create_matrix(4, 4, &B);
  int check_4 = s21_create_matrix(5, 4, &res_origin);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[0][3] = -4;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[1][3] = 14;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  A.matrix[2][3] = -1;
  A.matrix[3][0] = 10;
  A.matrix[3][1] = 3;
  A.matrix[3][2] = 9;
  A.matrix[3][3] = -3;
  A.matrix[4][0] = -3;
  A.matrix[4][1] = 3;
  A.matrix[4][2] = 1;
  A.matrix[4][3] = 5;
  B.matrix[0][0] = 8;
  B.matrix[0][1] = 8;
  B.matrix[0][2] = 3;
  B.matrix[0][3] = 5;
  B.matrix[1][0] = -7;
  B.matrix[1][1] = 7;
  B.matrix[1][2] = 1;
  B.matrix[1][3] = 1;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 3;
  B.matrix[2][2] = 4;
  B.matrix[2][3] = -4;
  B.matrix[3][0] = 10;
  B.matrix[3][1] = 3;
  B.matrix[3][2] = 9;
  B.matrix[3][3] = -3;
  res_origin.matrix[0][0] = -10;
  res_origin.matrix[0][1] = 60;
  res_origin.matrix[0][2] = 3;
  res_origin.matrix[0][3] = -1;
  res_origin.matrix[1][0] = 195;
  res_origin.matrix[1][1] = 123;
  res_origin.matrix[1][2] = 163;
  res_origin.matrix[1][3] = -25;
  res_origin.matrix[2][0] = 23;
  res_origin.matrix[2][1] = 14;
  res_origin.matrix[2][2] = -8;
  res_origin.matrix[2][3] = 38;
  res_origin.matrix[3][0] = 92;
  res_origin.matrix[3][1] = 119;
  res_origin.matrix[3][2] = 42;
  res_origin.matrix[3][3] = 26;
  res_origin.matrix[4][0] = 12;
  res_origin.matrix[4][1] = 15;
  res_origin.matrix[4][2] = 43;
  res_origin.matrix[4][3] = -31;
  int check = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(check_4, check_origin);
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(mult_matrix_2) {
  matrix_t A, B, result, res_origin;
  int check_origin = 0;
  int check_1 = s21_create_matrix(2, 2, &A);
  int check_2 = s21_create_matrix(2, 4, &B);
  int check_4 = s21_create_matrix(2, 4, &res_origin);
  A.matrix[0][0] = 2.987654;
  A.matrix[0][1] = -5.3456;
  A.matrix[1][0] = 6.23;
  A.matrix[1][1] = -3.9292;
  B.matrix[0][0] = 4.838;
  B.matrix[0][1] = 8.0987;
  B.matrix[0][2] = 8.09;
  B.matrix[0][3] = -987;
  B.matrix[1][0] = -8;
  B.matrix[1][1] = -0.921;
  B.matrix[1][2] = -0.91;
  B.matrix[1][3] = 21;
  res_origin.matrix[0][0] = 57.219070052;
  res_origin.matrix[0][1] = 29.1194110498;
  res_origin.matrix[0][2] = 29.03461686;
  res_origin.matrix[0][3] = -3061.072098;
  res_origin.matrix[1][0] = 61.57434;
  res_origin.matrix[1][1] = 54.0736942;
  res_origin.matrix[1][2] = 53.976272;
  res_origin.matrix[1][3] = -6231.5232;
  int check = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(check_4, check_origin);
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t A, B, result, res_origin;
  int check_origin = 0;
  int check_1 = s21_create_matrix(3, 3, &A);
  int check_2 = s21_create_matrix(3, 3, &B);
  int check_4 = s21_create_matrix(3, 3, &res_origin);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 9;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 7;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = 7;
  A.matrix[2][2] = 0;
  B.matrix[0][0] = 0;
  B.matrix[0][1] = 9;
  B.matrix[0][2] = 8;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 9;
  B.matrix[1][2] = 9;
  B.matrix[2][0] = 1;
  B.matrix[2][1] = 9;
  B.matrix[2][2] = 6;
  res_origin.matrix[0][0] = 1;
  res_origin.matrix[0][1] = 90;
  res_origin.matrix[0][2] = 87;
  res_origin.matrix[1][0] = 7;
  res_origin.matrix[1][1] = 99;
  res_origin.matrix[1][2] = 77;
  res_origin.matrix[2][0] = 0;
  res_origin.matrix[2][1] = 81;
  res_origin.matrix[2][2] = 79;
  int check = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(check_4, check_origin);
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(mult_matrix_4) {
  matrix_t A, B, result;
  int check_origin = 2;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(4, 2, &B);
  int check = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_5) {
  matrix_t A, B, result;
  int check_origin = 0;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 12, &B);
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = i + j;
    }
  }
  int check = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_int_eq(result.matrix[i][j], 0.0);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_6) {
  matrix_t A, B, result;
  int check_origin = 1;
  s21_create_matrix(-12, 3, &A);
  s21_create_matrix(3, 12, &B);
  int check = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(check, check_origin);
  s21_remove_matrix(&B);
}
END_TEST

Suite *suite_mult_matrix() {
  Suite *suite = suite_create("\x1b[34m[mult_matrix]\x1b[0m");
  TCase *tcase_core = tcase_create("s21_mult_matrix_tc");
  tcase_add_test(tcase_core, mult_matrix_1);
  tcase_add_test(tcase_core, mult_matrix_2);
  tcase_add_test(tcase_core, mult_matrix_3);
  tcase_add_test(tcase_core, mult_matrix_4);
  tcase_add_test(tcase_core, mult_matrix_5);
  tcase_add_test(tcase_core, mult_matrix_6);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
