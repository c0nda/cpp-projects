#include "protTestArrays.h"

template <typename T> void delete_2Darray(T **ppi, int rows){
    for (int i = 0; i < rows; ++i){
        delete[] ppi[i];
    }
    delete[] ppi;
}

template <typename T> T** create_2D_indep_array(int rows, int columns){
    T **arr = new int*[rows];
    for (int i = 0; i < rows; ++i){
        arr[i] = new int[columns];
    }
    return arr;
}

template <typename T> T** create_2D_dep_array(int rows, int columns){
    T *pi = new int[rows * columns]{0};
    T **ppi = new int*[rows];
    for (int i = 0, j = 0; i < rows * columns; i += columns, ++j){
            ppi[j] = &pi[i];
        }
    return ppi;
}


template <typename T> T** const_array(int rows, int columns, T cnst) {
    int **ppi = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        ppi[i] = new int[columns];

        for (int j = 0; j < columns; ++j) {
            ppi[i][j] = cnst;
        }
    }
    return ppi;
}

template <typename T> T** matrix_111(int rows, int columns){
    T **ppi = create_2D_indep_array<T>(rows, columns);
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < columns; ++j){
            if (i == j){
                ppi[i][j] = 1;
            } else{
                ppi[i][j] = 0;
            }
        }
    }
    return ppi;
}

template <typename T> T** t_matrix(T** arr, int rows, int columns){
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < columns; ++j){
            arr[i][j] = arr[j][i];
        }
    }
    return arr;
}
