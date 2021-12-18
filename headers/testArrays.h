#ifndef INC_15_11_2021_TESTARRAYS_H
#define INC_15_11_2021_TESTARRAYS_H

double **random_double_array(int, int);

void get_matrix_for_det(int **, int, size_t, size_t, int **);

int determinant(int **, int);

double **gauss_algorithm(double **, size_t, size_t);

template<typename T>
void printArray(T **arr, size_t rows, size_t columns) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template<typename T>
void delete_2D_indep_array(T **ppi, size_t rows) {
    for (size_t i = 0; i < rows; ++i) {
        delete[] ppi[i];
    }
    delete[] ppi;
}

template<typename T>
T **create_2D_indep_array(size_t rows, size_t columns) {
    T **arr = new T *[rows];
    for (size_t i = 0; i < rows; ++i) {
        arr[i] = new T[columns];
    }
    return arr;
}

template<typename T>
T **create_2D_dep_array(size_t rows, size_t columns) {
    T *pi = new T[rows * columns]{0};
    T **ppi = new T *[rows];
    for (size_t i = 0, j = 0; i < rows * columns; i += columns, ++j) {
        ppi[j] = &pi[i];
    }
    return ppi;
}

template<typename T>
T **random_array(size_t rows, size_t columns, int num) {
    T **arr = create_2D_indep_array<T>(rows, columns);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            arr[i][j] = rand() % num;
        }
    }
    return arr;
}

template<typename T>
T **const_array(size_t rows, size_t columns, T cnst) {
    T **ppi = new T *[rows];
    for (size_t i = 0; i < rows; ++i) {
        ppi[i] = new T[columns];

        for (size_t j = 0; j < columns; ++j) {
            ppi[i][j] = cnst;
        }
    }
    return ppi;
}

template<typename T>
T **ematrix(size_t rows, size_t columns) {
    if (rows == columns) {
        T **ppi = create_2D_indep_array<T>(rows, columns);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) {
                if (i == j) {
                    ppi[i][j] = 1;
                } else {
                    ppi[i][j] = 0;
                }
            }
        }
        return ppi;
    } else {
        return nullptr;
    }
}

template<typename T>
T **t_matrix(T **arr, size_t rows, size_t columns) {
    T **trans = create_2D_indep_array<T>(columns, rows);
    for (size_t i = 0; i < columns; ++i) {
        for (size_t j = 0; j < rows; ++j) {
            trans[i][j] = arr[j][i];
        }
    }
    return trans;
}

template<typename T>
T **turn180(T **mirror, size_t rows, size_t columns) {
    for (size_t i = 0; i < rows / 2; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            std::swap(mirror[i][j], mirror[rows - 1 - i][columns - 1 - j]);
        }
    }
    return mirror;
}

template<typename T>
T **multiplyMatrixByNumber(T **matrix, size_t rows, size_t columns, int number) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            matrix[i][j] = matrix[i][j] * number;
        }
    }
    return matrix;
}

template<typename T>
T **create_multiplyMatrixByNumber(T **matrix, size_t rows, size_t columns, int number) {
    T **result = create_2D_indep_array<T>(rows, columns);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            result[i][j] = matrix[i][j] * number;
        }
    }
    return result;
}

template<typename T>
T **additionOfMatrices(T **matrix1, T **matrix2, size_t rows, size_t columns) {
    T **result = create_2D_indep_array<T>(rows, columns);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

template<typename T>
T **multiplyMatrixByMatrix(T **matrix1, T **matrix2, size_t rows1, size_t columns1, size_t rows2, size_t columns2) {
    T **result = create_2D_indep_array<T>(rows1, columns2);
    if (columns1 == rows2) {
        for (size_t n = 0; n < rows1; ++n) {
            for (size_t m = 0; m < columns2; ++m) {
                result[n][m] = 0;
                for (size_t k = 0; k < columns1; ++k) {
                    result[n][m] += matrix1[n][k] * matrix2[k][m];
                }
            }
        }
        return result;
    }
    return nullptr;
}

template<typename T>
T **change2RowsOrColumns(T **arr, size_t rows, size_t columns, char name, size_t num1, size_t num2, size_t elem) {
    if (name == 'c') {
        if (num1 < columns & num2 < columns) {
            for (size_t i = elem; i < rows; ++i) {
                std::swap(arr[i][num1], arr[i][num2]);
            }
        }
    }

    if (name == 'r') {
        if (num1 < rows & num2 < rows) {
            for (size_t i = elem; i < columns; ++i) {
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
