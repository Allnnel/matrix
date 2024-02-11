#include "../s21_matrix.h"
#include "tests.h"

START_TEST(create_matrix_1) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(1000, 20000, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(create_matrix_2) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(2, 2, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(create_matrix_3) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(1, 1, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(create_matrix_4) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(6, 8, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(create_matrix_5) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(1, 150, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(create_matrix_6) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(0, 0, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(create_matrix_7) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(1, 0, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(create_matrix_8) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(0, 1, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(create_matrix_9) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(-1, -1, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(res, 1);
}
END_TEST

// -----------------------------------------------------------------------------------------------------------
START_TEST(remove_matrix_1) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(5, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) res = 1;
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(remove_matrix_2) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(1, 1, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) res = 1;
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(remove_matrix_3) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(3, 8, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) res = 1;
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(remove_matrix_4) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(4, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) res = 1;
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(remove_matrix_5) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(1, 20, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) res = 1;
  ck_assert_int_eq(res, 0);
}
END_TEST
// -----------------------------------------------------------------------------------------------------------
START_TEST(equal_test_1) {
  matrix_t matrixA;
  matrix_t matrixB;
  s21_create_matrix(5, 5, &matrixA);
  s21_create_matrix(5, 5, &matrixB);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      matrixA.matrix[i][j] = i * 10 + j;
      matrixB.matrix[i][j] = i * 10 + j;
    }
  }
  int result = s21_eq_matrix(&matrixA, &matrixB);
  ck_assert(result == 1);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(equal_test_2) {
  matrix_t matrixA;
  matrix_t matrixB;
  s21_create_matrix(5, 5, &matrixA);
  s21_create_matrix(5, 5, &matrixB);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      matrixA.matrix[i][j] = i * 10 + j;
      matrixB.matrix[i][j] = -1;
    }
  }
  int result = s21_eq_matrix(&matrixA, &matrixB);
  ck_assert(result == 0);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(equal_test_3) {
  matrix_t matrixA;
  matrix_t matrixB;
  s21_create_matrix(2, 2, &matrixA);
  s21_create_matrix(5, 5, &matrixB);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (i < 2 && j < 2) {
        matrixA.matrix[i][j] = i * 10 + j;
      }
      matrixB.matrix[i][j] = i + j;
    }
  }
  int result = s21_eq_matrix(&matrixA, &matrixB);
  ck_assert(result == 0);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(equal_test_4) {
  matrix_t matrixA;
  matrix_t matrixB;
  s21_create_matrix(1, 1, &matrixA);
  s21_create_matrix(1, 1, &matrixB);
  matrixA.matrix[0][0] = 0.0000015;
  matrixB.matrix[0][0] = 0.0000015;
  int result = s21_eq_matrix(&matrixA, &matrixB);
  ck_assert(result == 1);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(equal_test_5) {
  matrix_t matrixA;
  matrix_t matrixB;
  s21_create_matrix(5, 5, &matrixA);
  s21_create_matrix(5, 5, &matrixB);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      matrixA.matrix[i][j] = (i + 1) * (j + 1) * 1e-6;
      matrixB.matrix[i][j] = (i + 1) * (j + 1) * 1e-6;
    }
  }
  int result = s21_eq_matrix(&matrixA, &matrixB);
  ck_assert(result == 1);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST
// -----------------------------------------------------------------------------------------------------------
START_TEST(sum_1) {
  int rows = 5, columns = 6;
  matrix_t A;
  matrix_t B;
  matrix_t current;
  matrix_t result;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &current);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (i + j + 1);
      B.matrix[i][j] = (i + j + 1);
      current.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
    }
  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++)
      ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_2) {
  int rows = 10, columns = 10;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t current = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &current);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 12345 + i * 10 + j;
      B.matrix[i][j] = 12345 + i * 10 + j;
      current.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
    }
  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++)
      ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_3) {
  int rows = 3, columns = 3;
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows - 1, columns, &B);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 12345 + i * 10 + j;
      if (i < rows - 1) B.matrix[i][j] = 12345 + i * 10 + j;
    }
  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_4) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 12345 + i * 10 + j;
    }
  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(sum_5) {
  int rows = 3, columns = 3;
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_6) {
  int rows = 10, columns = 10;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t current = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &current);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = rand() % 1000 + 1;
      B.matrix[i][j] = rand() % 1000 + 1;
      current.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
    }
  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++)
      ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST
// -----------------------------------------------------------------------------------------------------------
START_TEST(sub_1) {
  int rows = 5, columns = 6;
  matrix_t A;
  matrix_t B;
  matrix_t current;
  matrix_t result;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &current);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (i + j + 1);
      B.matrix[i][j] = (i + j + 1);
      current.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
    }
  int res = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++)
      ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_2) {
  int rows = 10, columns = 10;
  matrix_t A;
  matrix_t B;
  matrix_t current;
  matrix_t result;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &current);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 12345 + i * 10 + j + j * 1234;
      B.matrix[i][j] = 12345 + i * 10 + j;
      current.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
    }
  int res = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++)
      ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_3) {
  int rows = 3, columns = 3;
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows - 1, columns, &B);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 12345 + i * 10 + j;
      if (i < rows - 1) B.matrix[i][j] = 12345 + i * 10 + j;
    }
  int res = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_4) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 12345 + i * 10 + j;
    }
  int res = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(sub_5) {
  int rows = 3, columns = 3;
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  int res = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_6) {
  int rows = 10, columns = 10;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t current = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &current);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = rand() % 1000 + 1;
      B.matrix[i][j] = rand() % 1000 + 1;
      current.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
    }
  int res = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++)
      ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST
// -----------------------------------------------------------------------------------------------------------
START_TEST(mult_matrix_1) {
  int rows = 3, columns = 2;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  matrix_t current = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &B);
  s21_create_matrix(rows, rows, &current);

  int sum = 0;
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      sum++;
      A.matrix[i][j] = sum;
    }
  sum = 0;
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++) {
      sum++;
      B.matrix[i][j] = sum;
    }
  current.matrix[0][0] = 9;
  current.matrix[0][1] = 12;
  current.matrix[0][2] = 15;
  current.matrix[1][0] = 19;
  current.matrix[1][1] = 26;
  current.matrix[1][2] = 33;
  current.matrix[2][0] = 29;
  current.matrix[2][1] = 40;
  current.matrix[2][2] = 51;

  int res = s21_mult_matrix(&A, &B, &result);
  ck_assert(res == 0);
  ck_assert_int_eq(s21_eq_matrix(&current, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_2) {
  int rowsA = 3, columnsA = 3, rowsB = 2, columnsB = 2;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(rowsA, columnsA, &A);
  s21_create_matrix(rowsB, columnsB, &B);

  for (int i = 0; i < rowsA; i++)
    for (int j = 0; j < columnsA; j++) {
      A.matrix[i][j] = 1;
      if (i < rowsB && j < columnsB) B.matrix[i][j] = 1;
    }
  int res = s21_mult_matrix(&A, &B, &result);
  ck_assert(res == 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_3) {
  int rows = 1, columns = 1;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  matrix_t current = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &B);
  s21_create_matrix(rows, rows, &current);

  A.matrix[0][0] = 1;
  B.matrix[0][0] = 1;
  current.matrix[0][0] = 1;

  int res = s21_mult_matrix(&A, &B, &result);
  ck_assert(res == 0);
  ck_assert_int_eq(s21_eq_matrix(&current, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_4) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(cols, rows, &mtx);

  matrix_t check = {0};
  s21_create_matrix(m.rows, mtx.columns, &check);

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), 1);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST
// -----------------------------------------------------------------------------------------------------------
START_TEST(transpose_1) {
  int rows = 1, columns = 1;
  matrix_t A = {0}, result = {0}, current = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &current);
  A.matrix[0][0] = 1;
  current.matrix[0][0] = 1;

  int res = s21_transpose(&A, &result);
  ck_assert(res == 0);
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++)
      ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_2) {
  int rows = 3, columns = 3;
  matrix_t A = {0}, result = {0}, current = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &current);

  int sum = 0;
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = sum++;

  current.matrix[0][0] = 0;
  current.matrix[0][1] = 3;
  current.matrix[0][2] = 6;
  current.matrix[1][0] = 1;
  current.matrix[1][1] = 4;
  current.matrix[1][2] = 7;
  current.matrix[2][0] = 2;
  current.matrix[2][1] = 5;
  current.matrix[2][2] = 8;

  int res = s21_transpose(&A, &result);
  ck_assert(res == 0);
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++)
      ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_3) {
  int rows = 2, columns = 3;
  matrix_t A = {0}, result = {0}, current = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &current);

  int sum = 0;
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = sum++;

  current.matrix[0][0] = 0;
  current.matrix[0][1] = 3;
  current.matrix[1][0] = 1;
  current.matrix[1][1] = 4;
  current.matrix[2][0] = 2;
  current.matrix[2][1] = 5;

  int res = s21_transpose(&A, &result);
  ck_assert(res == 0);
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++)
      ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_4) {
  int rows = 1, columns = 3;
  matrix_t A = {0}, result = {0}, current = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &current);

  int sum = 0;
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = 100 + sum++;

  current.matrix[0][0] = 100;
  current.matrix[1][0] = 101;
  current.matrix[2][0] = 102;

  int res = s21_transpose(&A, &result);
  ck_assert(res == 0);
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++)
      ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_5) {
  int rows = 3, columns = 1;
  matrix_t A = {0}, result = {0}, current = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &current);

  int sum = 0;
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = 100 + sum++;

  current.matrix[0][0] = 100;
  current.matrix[0][1] = 101;
  current.matrix[0][2] = 102;

  int res = s21_transpose(&A, &result);
  ck_assert(res == 0);
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++)
      ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_6) {
  matrix_t A = {0};
  matrix_t result = {0};

  int res = s21_transpose(&A, &result);
  ck_assert_int_eq(res, 1);
}
END_TEST
// -----------------------------------------------------------------------------------------------------------
START_TEST(calc_complements_1) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  matrix_t current = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &current);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  current.matrix[0][0] = 0;
  current.matrix[0][1] = 10;
  current.matrix[0][2] = -20;
  current.matrix[1][0] = 4;
  current.matrix[1][1] = -14;
  current.matrix[1][2] = 8;
  current.matrix[2][0] = -8;
  current.matrix[2][1] = -2;
  current.matrix[2][2] = 4;
  int res = s21_calc_complements(&A, &result);
  ck_assert(res == 0);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], current.matrix[i][j]);
    }
  s21_remove_matrix(&A);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_2) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  matrix_t current = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &current);
  A.matrix[0][0] = 0.73;
  A.matrix[0][1] = -0.19;
  A.matrix[0][2] = -0.12;
  A.matrix[1][0] = -0.07;
  A.matrix[1][1] = 0.72;
  A.matrix[1][2] = -0.17;
  A.matrix[2][0] = -0.12;
  A.matrix[2][1] = -0.15;
  A.matrix[2][2] = 0.92;
  current.matrix[0][0] = 0.6369;
  current.matrix[0][1] = 0.0848;
  current.matrix[0][2] = 0.0969;
  current.matrix[1][0] = 0.1928;
  current.matrix[1][1] = 0.6572;
  current.matrix[1][2] = 0.1323;
  current.matrix[2][0] = 0.1187;
  current.matrix[2][1] = 0.1325;
  current.matrix[2][2] = 0.5123;
  int res = s21_calc_complements(&A, &result);
  ck_assert(res == 0);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], current.matrix[i][j], 1e-6);
    }
  s21_remove_matrix(&A);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_3) {
  matrix_t A = {0};
  matrix_t result = {0};
  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(calc_complements_4) {
  matrix_t A = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(3, 4, &A);
  if (codec == 0) {
    int code = s21_calc_complements(&A, &result);
    ck_assert_int_eq(code, 2);
    s21_remove_matrix(&A);
  }
}
END_TEST

START_TEST(calc_complements_5) {
  int rows = 1, columns = 1;
  matrix_t A = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1123;
  if (codec == 0) {
    int code = s21_calc_complements(&A, &result);
    ck_assert_int_eq(code, 2);
  }
  s21_remove_matrix(&A);
}
END_TEST
// -----------------------------------------------------------------------------------------------------------
START_TEST(determimant_1) {
  int rows = 3, columns = 3;
  double result;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  int sum = 1;
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = sum++;
  double answer = 0.0;
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(result, answer);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determimant_2) {
  int rows = 3, columns = 3;
  double result;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 3.01;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 10;
  A.matrix[1][0] = -12;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 32.4;
  A.matrix[2][0] = 19;
  A.matrix[2][1] = -13.1;
  A.matrix[2][2] = 0.002;
  double answer = 3320.83648;
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(result, answer);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determimant_3) {
  int rows = 3, columns = 5;
  double result;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determimant_4) {
  double result;
  matrix_t A = {0};
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(determimant_5) {
  int rows = 2, columns = 2;
  double result;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -100.1;
  A.matrix[0][1] = 200.0001;
  A.matrix[1][0] = 1e-6;
  A.matrix[1][1] = 123.56789;
  double answer = -12369.145989000099999;
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(result, answer);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determimant_6) {
  int rows = 1, columns = 1;
  double result;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -100.1;
  double answer = -100.1;
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(result, answer);
  s21_remove_matrix(&A);
}
END_TEST
// -----------------------------------------------------------------------------------------------------------
START_TEST(inverse_1) {
  matrix_t A = {0}, C = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1.0;
  C.matrix[0][1] = -1.0;
  C.matrix[0][2] = 1.0;
  C.matrix[1][0] = -38.0;
  C.matrix[1][1] = 41.0;
  C.matrix[1][2] = -34.0;
  C.matrix[2][0] = 27.0;
  C.matrix[2][1] = -29.0;
  C.matrix[2][2] = 24.0;
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  matrix_t B = {0};
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(inverse_2) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  ck_assert_int_eq(codec, 0);
  m.matrix[0][0] = 1431.12312331;
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_double_eq(result.matrix[0][0], (1.0 / m.matrix[0][0]));
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&result);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_4) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(inverse_5) {
  const int size = 2;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 1;
  m.matrix[1][0] = 1;
  m.matrix[1][1] = 1;

  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, 2);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_6) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 4, &m);
  if (codec == 0) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, 2);
  }
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_7) {
  matrix_t m = {0};
  matrix_t expected = {0};
  int codec1, codec2;
  codec1 = s21_create_matrix(3, 3, &m);
  if (codec1 == 0) codec2 = s21_create_matrix(3, 3, &expected);

  if ((codec1 == 0) && (codec2 == 0)) {
    m.matrix[0][0] = 2;
    m.matrix[0][1] = 5;
    m.matrix[0][2] = 7;

    m.matrix[1][0] = 6;
    m.matrix[1][1] = 3;
    m.matrix[1][2] = 4;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = -2;
    m.matrix[2][2] = -3;

    expected.matrix[0][0] = 1;
    expected.matrix[0][1] = -1;
    expected.matrix[0][2] = 1;

    expected.matrix[1][0] = -38;
    expected.matrix[1][1] = 41;
    expected.matrix[1][2] = -34;

    expected.matrix[2][0] = 27;
    expected.matrix[2][1] = -29;
    expected.matrix[2][2] = 24;
    matrix_t result = {0};
    int code = s21_inverse_matrix(&m, &result);

    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
    ck_assert_int_eq(code, 0);
    s21_remove_matrix(&result);
  }
  s21_remove_matrix(&m);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(inverse_8) {
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  matrix_t res = {0};
  s21_inverse_matrix(&m, &res);

  matrix_t expected = {0};
  s21_create_matrix(size, size, &expected);
  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = -1;
  expected.matrix[0][2] = 1;
  expected.matrix[1][0] = -38;
  expected.matrix[1][1] = 41;
  expected.matrix[1][2] = -34;
  expected.matrix[2][0] = 27;
  expected.matrix[2][1] = -29;
  expected.matrix[2][2] = 24;

  ck_assert_int_eq(s21_eq_matrix(&expected, &res), SUCCESS);

  s21_remove_matrix(&expected);
  s21_remove_matrix(&res);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_9) {
  int rows = 4, columns = 4;
  matrix_t A = {0};
  matrix_t expected = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &expected);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i == j ? 1 : 0;
      expected.matrix[i][j] = A.matrix[i][j];
    }
  s21_inverse_matrix(&A, &result);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(expected.matrix[i][j], result.matrix[i][j], 1e-6);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}

Suite *test_matrix() {
  Suite *s = suite_create("create");
  TCase *tc = tcase_create("create");

  tcase_add_test(tc, create_matrix_1);
  tcase_add_test(tc, create_matrix_2);
  tcase_add_test(tc, create_matrix_3);
  tcase_add_test(tc, create_matrix_4);
  tcase_add_test(tc, create_matrix_5);
  tcase_add_test(tc, create_matrix_6);
  tcase_add_test(tc, create_matrix_7);
  tcase_add_test(tc, create_matrix_8);
  tcase_add_test(tc, create_matrix_9);

  tcase_add_test(tc, remove_matrix_1);
  tcase_add_test(tc, remove_matrix_2);
  tcase_add_test(tc, remove_matrix_3);
  tcase_add_test(tc, remove_matrix_4);
  tcase_add_test(tc, remove_matrix_5);

  tcase_add_test(tc, equal_test_1);
  tcase_add_test(tc, equal_test_2);
  tcase_add_test(tc, equal_test_3);
  tcase_add_test(tc, equal_test_4);
  tcase_add_test(tc, equal_test_5);

  tcase_add_test(tc, sum_1);
  tcase_add_test(tc, sum_2);
  tcase_add_test(tc, sum_3);
  tcase_add_test(tc, sum_4);
  tcase_add_test(tc, sum_5);
  tcase_add_test(tc, sum_6);

  tcase_add_test(tc, sub_1);
  tcase_add_test(tc, sub_2);
  tcase_add_test(tc, sub_3);
  tcase_add_test(tc, sub_4);
  tcase_add_test(tc, sub_5);
  tcase_add_test(tc, sub_6);

  tcase_add_test(tc, mult_matrix_1);  // -
  tcase_add_test(tc, mult_matrix_2);
  tcase_add_test(tc, mult_matrix_3);
  tcase_add_test(tc, mult_matrix_4);

  tcase_add_test(tc, transpose_1);
  tcase_add_test(tc, transpose_2);
  tcase_add_test(tc, transpose_3);
  tcase_add_test(tc, transpose_4);
  tcase_add_test(tc, transpose_5);
  tcase_add_test(tc, transpose_6);

  tcase_add_test(tc, calc_complements_1);  // ++
  tcase_add_test(tc, calc_complements_2);
  tcase_add_test(tc, calc_complements_3);
  tcase_add_test(tc, calc_complements_4);
  tcase_add_test(tc, calc_complements_5);

  tcase_add_test(tc, determimant_1);
  tcase_add_test(tc, determimant_2);
  tcase_add_test(tc, determimant_3);
  tcase_add_test(tc, determimant_4);
  tcase_add_test(tc, determimant_5);
  tcase_add_test(tc, determimant_6);

  tcase_add_test(tc, inverse_8);
  tcase_add_test(tc, inverse_1);
  tcase_add_test(tc, inverse_5);

  tcase_add_test(tc, inverse_7);
  tcase_add_test(tc, inverse_6);
  tcase_add_test(tc, inverse_4);
  tcase_add_test(tc, inverse_2);
  tcase_add_test(tc, inverse_9);

  suite_add_tcase(s, tc);

  return s;
}
