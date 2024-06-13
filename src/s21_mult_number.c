#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error_code = OK;

  if (!is_matrix_correct(A)) {
    error_code = INCORRECT_MATRIX;
  } else if (isnan(number)) {
    error_code = CALCULATION_ERROR;
  } else {
    error_code = s21_create_matrix(A->rows, A->columns, result);
    if (!error_code) {
      for (int i = 0; i < A->rows && error_code == OK; i++) {
        for (int j = 0; j < A->columns && error_code == OK; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
          if (isinf(result->matrix[i][j])) {
            error_code = CALCULATION_ERROR;
          }
        }
      }
    }
  }

  return error_code;
}