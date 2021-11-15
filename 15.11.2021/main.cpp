#include <iostream>

void printArray(int **arr, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void deleteArray(int **arr, int rows){
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}
template <typename T> T& getElement(T** arr, size_t rows, size_t columns, size_t r, size_t c, bool& result){
    if (r >= rows || c >= columns){
        result = false;
        return arr[0][0];
    }
    return arr[r][c];
}

template <typename T> T** const_array(int rows, int columns, int cnst) {
    int **ppi = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        ppi[i] = new int[columns];

        for (int j = 0; j < columns; ++j) {
            ppi[i][j] = cnst;
        }
    }
    return ppi;
}

bool testConst_array(int **arr){
    printArray(arr, 3, 3);
    bool result = true;
    if (result && 3 == getElement(arr, 3, 3, 1, 1, result) && 3 == getElement(arr, 3, 3, 2, 0, result)){
        return true;
    }
    return false;
}

int main() {
    std::cout << testConst_array(const_array<int>(3, 3, 3)) << std::endl;
    return 0;
}
