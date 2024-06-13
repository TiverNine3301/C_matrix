#include "s21_matrix.h"

int is_ptr_null(matrix_t *result) { return result == NULL; }

int is_size_correct(int rows, int columns) {
  if (rows <= 0 || columns <= 0) {
    return FALSE;
  }
  return TRUE;
}

int is_matrix_square(int rows, int columns) { return rows == columns; }

int copy_matrix(matrix_t *A, matrix_t *copy) {
  int error_code = OK;
  error_code = s21_create_matrix(A->rows, A->columns, copy);
  if (!error_code) {
    for (int i = 0; i < copy->rows; i++) {
      for (int j = 0; j < copy->columns; j++) {
        copy->matrix[i][j] = A->matrix[i][j];
      }
    }
  }
  return error_code;
}

void swap_rows(matrix_t *A, int row1, int row2) {
  double tmp;
  for (int i = 0; i < A->columns; i++) {
    tmp = A->matrix[row1][i];
    A->matrix[row1][i] = A->matrix[row2][i];
    A->matrix[row2][i] = tmp;
  }
}

void print_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      printf("%lf ", A->matrix[i][j]);
    }
    printf("\n");
  }
}

int remove_row_and_col(matrix_t *A, matrix_t *result, int row, int col) {
  int error_code = OK;
  error_code = s21_create_matrix(A->rows - 1, A->columns - 1, result);
  if (!error_code) {
    int is_row_removed = FALSE;
    for (int i = 0; i < A->rows; i++) {
      int is_col_removed = FALSE;
      for (int j = 0; j < A->columns; j++) {
        if (i != row && j != col) {
          result->matrix[i - is_row_removed][j - is_col_removed] =
              A->matrix[i][j];
        } else if (i == row) {
          is_row_removed = TRUE;
          continue;
        } else if (j == col) {
          is_col_removed = TRUE;
          continue;
        }
      }
    }
  }
  return error_code;
}

int is_matrix_correct(matrix_t *A) {
  if (is_ptr_null(A)) {
    return FALSE;
  }
  if (A->matrix == NULL) {
    return FALSE;
  }
  if (!is_size_correct(A->rows, A->columns)) {
    return FALSE;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (isnan(A->matrix[i][j])) {
        return FALSE;
      }
    }
  }
  return TRUE;
}

int is_matrices_compatible(matrix_t *A, matrix_t *B) {
  if (A->columns == B->rows) {
    return TRUE;
  }
  return FALSE;
}