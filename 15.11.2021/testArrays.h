#ifndef INC_15_11_2021_TESTARRAYS_H
#define INC_15_11_2021_TESTARRAYS_H

template<typename T>
void printArray(T **arr, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

template<typename T>
void delete_2Darray(T **ppi, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] ppi[i];
    }
    delete[] ppi;
}

template<typename T>
T **create_2D_indep_array(int rows, int columns) {
    T **arr = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[columns];
    }
    return arr;
}

template<typename T>
T **create_2D_dep_array(int rows, int columns) {
    T *pi = new int[rows * columns]{0};
    T **ppi = new int *[rows];
    for (int i = 0, j = 0; i < rows * columns; i += columns, ++j) {
        ppi[j] = &pi[i];
    }
    return ppi;
}


template<typename T>
T **const_array(int rows, int columns, T cnst) {
    int **ppi = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        ppi[i] = new int[columns];

        for (int j = 0; j < columns; ++j) {
            ppi[i][j] = cnst;
        }
    }
    return ppi;
}

template<typename T>
T **matrix_111(int rows, int columns) {
    T **ppi = create_2D_indep_array<T>(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (i == j) {
                ppi[i][j] = 1;
            } else {
                ppi[i][j] = 0;
            }
        }
    }
    return ppi;
}

template<typename T>
T **t_matrix(T **arr, int rows, int columns) {
    T **trans = create_2D_indep_array<T>(columns, rows);
    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < rows; ++j) {
            trans[i][j] = arr[j][i];
        }
    }
    return trans;
}

template<typename T>
T **turn180(T **mirror, int rows, int columns) {
    for (int i = 0; i < rows / 2; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::swap(mirror[i][j], mirror[rows - 1 - i][columns - 1 - j]);
        }
    }
    return mirror;
}

template<typename T>
T **multiplyMatrixByNumber(T **matrix, int rows, int columns, int number) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = matrix[i][j] * number;
        }
    }
    return matrix;
}

template<typename T>
T **create_multiplyMatrixByNumber(T **matrix, int rows, int columns, int number) {
    T **result = create_2D_indep_array<T>(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result[i][j] = matrix[i][j] * number;
        }
    }
    return result;
}

template<typename T>
T **create_multiplyMatrixByNumber(T **matrix1, T **matrix2, int rows, int columns) {
    T **result = create_2D_indep_array<T>(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

template<typename T>
T **multiplyMatrixByMatrix(T **matrix1, T **matrix2, int rows1, int columns1, int rows2, int columns2) {
    T **result = create_2D_indep_array<T>(rows1, columns2);
    if (columns1 == rows2) {
        for (int n = 0; n < rows1; ++n) {
            for (int m = 0; m < columns2; ++m) {
                result[n][m] = 0;
                for (int k = 0; k < columns1; ++k) {
                    result[n][m] += matrix1[n][k] * matrix2[k][m];
                }
            }
        }
        return result;
    }
    return nullptr;
}

template<typename T>
T **change2RowsOrColumns(T** arr, int rows, int columns, char name, int num1, int num2) {
    if (name == 'c') {
        if (num1 < columns & num2 < columns) {
            for (int i = 0; i < rows; ++i) {
                std::swap(arr[i][num1], arr[i][num2]);
            }
        }
    }

    if (name == 'r') {
        if (num1 < rows & num2 < rows) {
            for (int i = 0; i < columns; ++i) {
                std::swap(arr[num1][i], arr[num2][i]);
            }
        }
    }
    return arr;
}

template<typename T>
T &getElement(T **arr, size_t rows, size_t columns, size_t r, size_t c) {
    if (r >= rows || c >= columns) {
        return arr[0][0];
    }
    return arr[r][c];
}

#endif
