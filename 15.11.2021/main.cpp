#include <iostream>
#include "testArrays.h"

void search_area(int **arr, int len, int wid, int l_place, int w_place, int **zeroes){
    if ((arr[l_place + 1][w_place] <= arr[l_place][w_place]) && (l_place + 1 < len)){
        zeroes[l_place + 1][w_place] = 1;
        search_area(arr, len, wid, l_place + 1, w_place, zeroes);
    }
    if ((arr[l_place - 1][w_place] <= arr[l_place][w_place]) && (l_place - 1 >= 0)){
        zeroes[l_place + 1][w_place] = 1;
        search_area(arr, len, wid, l_place - 1, w_place, zeroes);
    }
    if ((arr[l_place][w_place + 1] <= arr[l_place][w_place]) && (w_place + 1 < wid)){
        zeroes[l_place + 1][w_place] = 1;
        search_area(arr, len, wid, l_place, w_place + 1, zeroes);
    }
    if ((arr[l_place][w_place - 1] <= arr[l_place][w_place]) && (w_place - 1 >= 0)){
        zeroes[l_place + 1][w_place] = 1;
        search_area(arr, len, wid, l_place, w_place - 1, zeroes);
    }
    ++zeroes[l_place][w_place];
}

void water(int **arr, int len, int wid, int steps, int l_place, int w_place){
    int **zeroes = const_array(len, wid, 0);
    for (int i = 1; i <= steps; ++i){
        search_area(arr, len, wid, l_place, w_place, zeroes);
    }
    printArray(zeroes, len, wid);
    delete_2D_indep_array(zeroes, len);
}

void testConst_array(int rows, int columns, int cnst) {
    int **arr = const_array(rows, columns, cnst);
    int fail_count = 0, pass_count = 0;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            if (getElement(arr, rows, columns, r, c) == cnst) {
                ++pass_count;
            } else {
                ++fail_count;
            }
        }
    }
    std::cout << fail_count << " tests failed" << std::endl;
    std::cout << pass_count << " tests passed" << std::endl;
    delete_2D_indep_array(arr, rows);
    std::cout << std::endl;
}

void test_ematrix(int rows, int columns) {
    int **arr = ematrix<int>(rows, columns);
    if (arr != nullptr) {
        int fail_count = 0, pass_count = 0;
        for (int i = 0; i < rows; ++i) {
            if (getElement(arr, rows, columns, i, i) == 1) {
                ++pass_count;
            } else {
                ++fail_count;
            }
        }
        std::cout << fail_count << " tests failed" << std::endl;
        std::cout << pass_count << " tests passed" << std::endl;
        delete_2D_indep_array(arr, rows);
    } else {
        std::cout << "Test failed: input data is invalid" << std::endl;
    }
    std::cout << std::endl;
}


int main() {
//    int **ppi = create_2D_indep_array<int>(3, 3);
//    int counter = 1;
//    for (int i = 0; i < 3; ++i){
//        for (int j = 0; j < 3; ++j){
//            ppi[i][j] = counter;
//            ++counter;
//        }
//    }
//
//    water(ppi, 3, 3, 2, 1, 1);
//    delete_2Darray(ppi, 3);
//    std::cout << "============= Tests const_array =============" << std::endl;
//    testConst_array(4, 3, 3);
//    testConst_array(3, 4, 1);
//    testConst_array(1, 1, 0);
//    testConst_array(1, 10, 12);
//
//    std::cout << "============= Tests ematrix =============" << std::endl;
//    test_ematrix(10, 10);
//    test_ematrix(1, 1);
//    test_ematrix(11, 1);
//    test_ematrix(100, 100);
//    test_ematrix(0, 1);
//    int **arr = create_2D_indep_array<int>(3, 3);
//    for (int i = 0; i < 3; ++i){
//        for (int j = 0; j < 3; ++j){
//            arr[i][j] = rand() % 10;
//        }
//    }
//    printArray(arr, 3, 3);
//    std::cout << std::endl << std::endl;
//    water(arr, 3, 3, 3, 1, 1);

    double **arr = random_array<double>(4, 5, 3);
    printArray(arr, 4, 5);
    std::cout << std::endl;
    gauss_algorithm(arr, 4, 5);
    printArray(arr, 4, 5);
//    change2RowsOrColumns(arr, 4, 5, 'r', 0, 1, 1);
//    printArray(arr, 4, 5);
    delete_2D_indep_array(arr, 4);
    return 0;
}
