#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;
  if (A == NULL || B == NULL || A->rows <= 0 || A->columns <= 0 ||
      A->matrix == NULL || B->rows <= 0 || B->columns <= 0 ||
      B->matrix == NULL || A->rows != B->rows || A->columns != B->columns)
    result = FAILURE;
  else {
    for (int i = 0; i < A->rows && result; i++) {
      for (int j = 0; j < A->columns && result; j++) {
        if (fabs((A->matrix[i][j]) - (B->matrix[i][j])) > ACCURACY)
          result = FAILURE;
      }
    }
  }
  return result;
}