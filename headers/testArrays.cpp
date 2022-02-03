#include <iostream>
#include <random>
#include "testArrays.h"
#include <ctime>

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
            result[i][j] = arr[i + di][j + dj];
        }
    }
}

int determinant(int **arr, int size) {
    int det = 0;
    int deg = 1;

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