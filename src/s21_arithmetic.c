#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  if ((s21_control_matrix(A) != 0) || (s21_control_matrix(B) != 0))
    error = 1;
  else if ((A->rows != B->rows) || (B->columns != A->columns))
    error = 2;
  if (error == 0) {
    error = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; (error == 0) && (i != A->rows); i++)
      for (int y = 0; y != A->columns; y++)
        result->matrix[i][y] = A->matrix[i][y] + B->matrix[i][y];
  }
  return error;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  if ((s21_control_matrix(A) != 0) || (s21_control_matrix(B) != 0))
    error = 1;
  else if ((A->rows != B->rows) || (B->columns != A->columns))
    error = 2;
  if (error == 0) {
    error = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; (error == 0) && (i != A->rows); i++)
      for (int y = 0; y != A->columns; y++)
        result->matrix[i][y] = A->matrix[i][y] - B->matrix[i][y];
  }
  return error;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = 0;
  if ((s21_control_matrix(A) == 0)) {
    error = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; (error == 0) && (i != A->rows); i++)
      for (int y = 0; y != A->columns; y++)
        result->matrix[i][y] = A->matrix[i][y] * number;
  } else
    error = 1;
  return error;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  if ((s21_control_matrix(A) != 0) || (s21_control_matrix(B) != 0))
    error = 1;
  else if (A->columns != B->rows)
    error = 2;
  if (error == 0) {
    error = s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; (error == 0) && (i != A->rows); i++) {
      for (int y = 0; y != B->columns; y++) {
        double num = 0;
        for (int q = 0; q != A->columns; q++)
          num += A->matrix[i][q] * B->matrix[q][y];
        result->matrix[i][y] = num;
      }
    }
  }
  return error;
}