#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = OK;

  if (!is_matrix_correct(A) || !is_matrix_correct(B)) {
    error_code = INCORRECT_MATRIX;
  }
  if (!error_code && !is_matrices_compatible(A, B)) {
    error_code = CALCULATION_ERROR;
  }
  if (!error_code) {
    error_code = s21_create_matrix(A->rows, B->columns, result);
  }

  if (!error_code) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int l = 0; l < A->columns; l++) {
          result->matrix[i][j] += A->matrix[i][l] * B->matrix[l][j];
        }
      }
    }
  }
  return error_code;
}