#include "../s21_matrix_test.h"

START_TEST(sub_matrix_1) {
  matrix_t result, B, A;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  B.matrix[0][0] = 3;
  B.matrix[0][1] = 3;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 3;
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      ck_assert_int_eq(result.matrix[i][j], -2);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_2) {
  matrix_t result, B, A;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  B.matrix[0][0] = 0;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 0;
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      ck_assert_int_eq(result.matrix[i][j], 0);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_3) {
  matrix_t result, B, A;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  B.matrix[0][0] = 3;
  B.matrix[0][1] = 3;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 3;
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = 2;
  ck_assert_int_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_matrix_4) {
  matrix_t result, res_origin, B, A;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  s21_create_matrix(4, 4, &res_origin);
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
  res_origin.matrix[0][0] = -6;
  res_origin.matrix[0][1] = -3;
  res_origin.matrix[0][2] = 4;
  res_origin.matrix[0][3] = -9;
  res_origin.matrix[1][0] = 13;
  res_origin.matrix[1][1] = -4;
  res_origin.matrix[1][2] = 3;
  res_origin.matrix[1][3] = 13;
  res_origin.matrix[2][0] = -2;
  res_origin.matrix[2][1] = -5;
  res_origin.matrix[2][2] = -7;
  res_origin.matrix[2][3] = 3;
  res_origin.matrix[3][0] = 0;
  res_origin.matrix[3][1] = 0;
  res_origin.matrix[3][2] = 0;
  res_origin.matrix[3][3] = 0;
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = 0;
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

START_TEST(sub_matrix_5) {
  matrix_t result, res_origin, B, A;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &res_origin);
  A.matrix[0][0] = 2.987654;
  A.matrix[0][1] = -5.3456;
  A.matrix[1][0] = 6.23;
  A.matrix[1][1] = -3.9292;
  B.matrix[0][0] = 4.838;
  B.matrix[0][1] = 8.0987;
  B.matrix[1][0] = -8;
  B.matrix[1][1] = -0.921;
  res_origin.matrix[0][0] = -1.850346;
  res_origin.matrix[0][1] = -13.4443;
  res_origin.matrix[1][0] = 14.23;
  res_origin.matrix[1][1] = -3.0082;
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = 0;
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

START_TEST(sub_matrix_6) {
  matrix_t result, res_origin, B, A;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &res_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 4 * i;
    }
  }
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = 2 * i;
    }
  }
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      res_origin.matrix[i][j] = i * 2;
    }
  }
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = 0;
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

START_TEST(sub_matrix_7) {
  matrix_t result, res_origin, B, A;
  s21_create_matrix(5, 4, &A);
  s21_create_matrix(5, 4, &B);
  s21_create_matrix(5, 4, &res_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i;
      res_origin.matrix[i][j] = i;
    }
  }
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_int_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}
END_TEST

START_TEST(sub_matrix_8) {
  matrix_t result, B, A;
  s21_create_matrix(-2, 2, &A);
  s21_create_matrix(2, 2, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_matrix_9) {
  matrix_t result, B, A;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(-2, 2, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_sub_matrix() {
  Suite *suite = suite_create("\x1b[34m[s21_s21_sub_matrix]\x1b[0m");
  TCase *tcase_core = tcase_create("s21_sub_matrix_tc");
  tcase_add_test(tcase_core, sub_matrix_1);
  tcase_add_test(tcase_core, sub_matrix_2);
  tcase_add_test(tcase_core, sub_matrix_3);
  tcase_add_test(tcase_core, sub_matrix_4);
  tcase_add_test(tcase_core, sub_matrix_5);
  tcase_add_test(tcase_core, sub_matrix_6);
  tcase_add_test(tcase_core, sub_matrix_7);
  tcase_add_test(tcase_core, sub_matrix_8);
  tcase_add_test(tcase_core, sub_matrix_9);

  suite_add_tcase(suite, tcase_core);
  return suite;
}