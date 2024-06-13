#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error_code = OK;
  if (!is_matrix_correct(A)) {
    error_code = INCORRECT_MATRIX;
  }
  if (!error_code && !is_matrix_square(A->rows, A->columns)) {
    error_code = CALCULATION_ERROR;
  }
  if (!error_code) {
    error_code = s21_create_matrix(A->rows, A->columns, result);
  }
  if (!error_code) {
    if (A->rows == 1 && A->columns == 1) {
      result->matrix[0][0] = A->matrix[0][0];
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_t minor;
          double det;
          error_code = remove_row_and_col(A, &minor, i, j);
          if (!error_code) {
            error_code = s21_determinant(&minor, &det);
            if (!error_code) {
              if (det == 0) {
                error_code = CALCULATION_ERROR;
              } else {
                result->matrix[i][j] = pow(-1, (i + 1) + (j + 1)) * det;
              }
            }
          }
          s21_remove_matrix(&minor);
        }
      }
    }
  }
  return error_code;
}
