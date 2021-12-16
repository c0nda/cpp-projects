#include <iostream>
#include <random>
#include "testArrays.h"
#include <ctime>

double **random_double_array(int rows, int columns){
    double **arr = create_2D_indep_array<double>(rows, columns);
    for (int i = 0; i < rows; ++i){
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
        delete_2Darray(result, size - 1);
    }
    return det;
}