#ifndef S21_MATRIX
#define S21_MATRIX

#define SUCCESS 1
#define FAILURE 0

#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

#define TRUE 1
#define FALSE 0

#define ACCURACY 1e-7

#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int is_ptr_null(matrix_t *result);
int is_size_correct(int rows, int columns);
int is_matrix_square(int rows, int columns);
int is_matrix_correct(matrix_t *A);
int is_matrices_compatible(matrix_t *A, matrix_t *B);
int copy_matrix(matrix_t *A, matrix_t *copy);
void swap_rows(matrix_t *A, int row1, int row2);
int remove_row_and_col(matrix_t *A, matrix_t *result, int row, int col);

void print_matrix(matrix_t *A);

#endif