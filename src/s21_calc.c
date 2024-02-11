#include "s21_matrix.h"
int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (s21_control_matrix(A) != 0)
    error = 1;
  else if (s21_create_matrix(A->columns, A->rows, result) != 0)
    error = 1;
  if (error == 0) {
    for (int i = 0; i != A->rows; i++)
      for (int y = 0; y != A->columns; y++)
        result->matrix[y][i] = A->matrix[i][y];
  }
  return error;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (s21_control_matrix(A) != 0)
    error = 1;
  else if ((A->rows != A->columns) || (A->rows == 1))
    error = 2;
  if (error == 0) {
    double num = 0;
    matrix_t matrix_minor = {};
    error = s21_create_matrix(A->rows, A->columns, result);
    if (error == 0)
      s21_create_matrix(A->rows - 1, A->columns - 1, &matrix_minor);
    for (int i = 0; (error == 0) && (i != A->rows); i++)
      for (int y = 0; y != A->columns; y++) {
        s21_minorr(i, y, A, &matrix_minor);
        s21_determinant(&matrix_minor, &num);
        result->matrix[i][y] =
            num * pow(-1, i + y);  // значение минора умноженное на -1^(i+j).
      }
    if (error == 0) s21_remove_matrix(&matrix_minor);
  }
  return error;
}

// минор строчки матрицы
int s21_minorr(int rows, int columns, matrix_t *A, matrix_t *matrix_minor) {
  int error = 0;
  int minor_rows = 0;
  for (int i = 0; i != A->rows; i++) {
    if (i == rows) continue;
    int minor_columns = 0;
    for (int y = 0; y != A->columns; y++) {
      if (y == columns) continue;
      matrix_minor->matrix[minor_rows][minor_columns] = A->matrix[i][y];
      minor_columns++;
    }
    minor_rows++;
  }
  return error;
}

// определитель матрицы - перемножить
int s21_determinant(matrix_t *A, double *result) {
  int error = 0;
  if (s21_control_matrix(A) != 0)
    error = 1;
  else if (A->rows != A->columns)
    error = 2;
  if (error == 0) *result = s21_multiply(A);
  return error;
}

double s21_multiply(matrix_t *A) {
  double result = 0;
  matrix_t B = {0};
  if (A->rows == 1) {
    result = A->matrix[0][0];
  } else {
    s21_create_matrix(A->rows - 1, A->columns - 1, &B);
    for (int i = 0; i != A->rows; i++) {
      s21_minorr(0, i, A, &B);
      result += (pow(-1, i) * A->matrix[0][i] * s21_multiply(&B));
    }
    s21_remove_matrix(&B);
  }
  return result;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = 0;
  double num = 0.0;
  if (s21_control_matrix(A) != 0) error = 1;
  // Определитель |A| != 0 -> обратная матрица существует
  else if (A->columns != A->rows || (s21_determinant(A, &num) != 0) || num == 0)
    error = 2;
  if (error == 0) {
    if (A->columns != 1) {
      // Поиск определителя:
      matrix_t minor = {0};
      s21_calc_complements(A, &minor);
      // Построение матрицы миноров:
      matrix_t transpose_minor = {0};
      s21_transpose(&minor, &transpose_minor);
      // Матрица алгебраических дополнений будет равна:
      s21_mult_number(&transpose_minor, 1 / num, result);
      s21_remove_matrix(&minor);
      s21_remove_matrix(&transpose_minor);
    } else {
      error = s21_create_matrix(1, 1, result);
      if (error == 0) result->matrix[0][0] = 1.0 / A->matrix[0][0];
    }
  }
  return error;
}
