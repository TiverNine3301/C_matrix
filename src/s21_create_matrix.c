#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error_code = OK;

  if (is_ptr_null(result) || !is_size_correct(rows, columns)) {
    error_code = INCORRECT_MATRIX;
    result->matrix = NULL;
  }

  if (!error_code) {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
    }
    result->rows = rows;
    result->columns = columns;
  }
  return error_code;
}