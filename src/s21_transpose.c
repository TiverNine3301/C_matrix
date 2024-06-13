#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error_code = OK;
  if (!is_matrix_correct(A)) {
    error_code = INCORRECT_MATRIX;
  } else {
    error_code = s21_create_matrix(A->columns, A->rows, result);
    if (!error_code) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    }
  }
  return error_code;
}