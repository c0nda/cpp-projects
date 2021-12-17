#include <iostream>
#include <random>
#include "testArrays.h"
#include <ctime>
#include <string>

double **random_double_array(int rows, int columns) {
    double **arr = create_2D_indep_array<double>(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::mt19937 gen(time(nullptr));
            std::uniform_real_distribution<> urd(0, 3);
            arr[i][j] = urd(gen);
        }
    }
    return arr;
}

void get_matrix_for_det(int **arr, int size, size_t r, size_t c, int **result) {
    size_t di = 0, dj; // смещение индексов строки и столбца
    for (size_t i = 0; i < size - 1; ++i) {
        if (r == i) {
            di = 1;
        }
        dj = 0;
        for (size_t j = 0; j < size - 1; ++j) {
            if (j == c) {
                dj = 1;
            }
            result[i][j] = arr[i + di][i + dj];
        }
    }
}

int determinant(int **arr, int size) {
    int det = 0;
    int deg = -1;

    if (size == 1) {
        return arr[0][0];
    }
    if (size == 2) {
        return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
    } else {
        int **result = create_2D_indep_array<int>(size - 1, size - 1);
        for (size_t j = 0; j < size; ++j) {
            get_matrix_for_det(arr, size, 0, j, result);
            det += deg * arr[0][j] * determinant(result, size - 1);
            deg = -deg;
        }
        delete_2D_indep_array(result, size - 1);
    }
    return det;
}

double **gauss_algorithm(double **matrix, size_t rows, size_t columns) {
    // прямой ход
    for (size_t n = 0; n < columns; ++n) {
        for (size_t i = n; i < rows; ++i) {
            if (matrix[i][n] != 0) {
                change2RowsOrColumns(matrix, rows, columns, 'r', n, i, n);
                break;
            }
        }
        for (size_t j = n + 1; j < rows; ++j) {
            if (matrix[j][n] != 0) {
                double cf = matrix[j][n] / matrix[n][n];
                for (size_t k = n; k < columns; ++k) {
                    matrix[j][k] -= cf * matrix[n][k];
                }
            }
        }
        for (size_t m = n; m < rows; ++m) {
            if (matrix[n][n] != 0) {
                matrix[n][m] /= matrix[n][n];
            }
        }
    }

    // обратный ход
//    for (size_t i = rows - 1; i >= 0 && i < rows; --i) {
//        double div = matrix[i][columns - 1];
//        for (size_t j = columns - 1; j >= 0 && j < columns; --j) {
//            if (matrix[i][j] != 0) {
//                matrix[i][j] /= div;
//            }
//        }
//        for (size_t n = i - 1; n >= 0 && n < rows; --n) {
//            double cf = matrix[n][i] / matrix[i][i];
//            for (size_t k = rows - 1; k >= 0 && k < columns; --k) {
//                matrix[n][k] -= cf * matrix[i][k];
//            }
//        }
//    }
    return matrix;
}