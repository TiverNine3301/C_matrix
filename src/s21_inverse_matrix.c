#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (A == NULL || A->rows < 1 || A->columns < 1 || A->matrix == NULL)
    error = 1;
  else if (A->rows != A->columns)
    error = 2;
  else {
    double det = 0.0;
    matrix_t B;
    matrix_t C;
    error = s21_determinant(A, &det);
    if (fabs(det) < ACCURACY)
      error = 2;
    else {
      if (A->rows == 1) {
        s21_create_matrix(A->rows, A->columns, result);
        result->matrix[0][0] = 1. / A->matrix[0][0];
      } else {
        double new_det = 1. / det;
        error = s21_calc_complements(A, &B);
        error = s21_transpose(&B, &C);
        error = s21_mult_number(&C, new_det, result);
        s21_remove_matrix(&B);
        s21_remove_matrix(&C);
      }
    }
  }
  return error;
}
