#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int error_code = OK;
  matrix_t copy;
  if (!is_matrix_correct(A)) {
    error_code = INCORRECT_MATRIX;
  } else if (!is_matrix_square(A->rows, A->columns)) {
    error_code = CALCULATION_ERROR;
  } else {
    copy_matrix(A, &copy);
    int not_a_zero = 0;
    int not_a_zero_index = -1;
    *result = 1;
    int sign = 1;
    for (int i = 0; i < copy.columns; i++) {
      for (int j = 0; j < copy.rows; j++) {
        if (copy.matrix[j][i] != 0) {
          not_a_zero = 1;
          not_a_zero_index = j;
        }
      }

      if (!not_a_zero) {
        *result = 0;
        break;
      }
      if (copy.matrix[i][i] == 0) {
        swap_rows(&copy, not_a_zero_index, i);
        sign *= -1;
      }
      for (int j = i + 1; j < copy.rows; j++) {
        if (copy.matrix[j][i] != 0) {
          double multiplier = 1 / copy.matrix[i][i] * copy.matrix[j][i];
          for (int k = i; k < copy.columns; k++) {
            copy.matrix[j][k] -= copy.matrix[i][k] * multiplier;
          }
        }
      }
    }
    for (int i = 0; i < copy.columns; i++) {
      *result *= copy.matrix[i][i];
    }

    *result *= sign;
    s21_remove_matrix(&copy);
  }

  return error_code;
}
