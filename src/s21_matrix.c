#include "s21_matrix.h"
int s21_control_matrix(matrix_t *A) {
  int error = 0;
  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0)
    error = 1;
  return error;
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = 0;
  if (rows > 0 && columns > 0 &&
      (result->matrix = (double **)calloc(rows, sizeof(double *)))) {
    result->rows = rows;
    result->columns = columns;
    for (int i = 0; (error == 0) && (i != rows); i++)
      if (!(result->matrix[i] = (double *)calloc(columns, sizeof(double)))) {
        error = 1;
        for (int y = 0; y < i; y++) free(result->matrix[y]);
        free(result->matrix);
      }
  } else
    error = 1;
  return error;
}

void s21_remove_matrix(matrix_t *A) {
  if (A->matrix != NULL) {
    for (int i = 0; i != A->rows; i++) free(A->matrix[i]);
    free(A->matrix);
    A->matrix = NULL;
  }
  A->rows = 0;
  A->columns = 0;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int error = SUCCESS;
  if ((s21_control_matrix(A) == 0) && (s21_control_matrix(B) == 0) &&
      (A->columns == B->columns) && (A->rows == B->rows)) {
    for (int i = 0; (error == SUCCESS) && (i != A->rows); i++)
      for (int y = 0; (error == SUCCESS) && (y != A->columns); y++)
        if (fabs(A->matrix[i][y] - B->matrix[i][y]) > 1e-6) error = FAILURE;
  } else
    error = FAILURE;
  return error;
}
