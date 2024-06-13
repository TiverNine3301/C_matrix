#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = OK;
  if (!is_matrix_correct(A) || !is_matrix_correct(B)) {
    error_code = INCORRECT_MATRIX;
  }
  if (!error_code && (A->rows != B->rows || A->columns != B->columns)) {
    error_code = CALCULATION_ERROR;
  }
  if (!error_code) {
    error_code = s21_create_matrix(A->rows, A->columns, result);
  }
  if (!error_code) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return error_code;
}