#include <iostream>
#include "testArrays.h"

void testConst_array(int rows, int columns, int cnst) {
    int **arr = const_array(rows, columns, cnst);
    int fail_count = 0, pass_count = 0;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            if (getElement(arr, 4, 3, r, c) == 3) {
                ++pass_count;
            } else {
                ++fail_count;
            }
        }
    }
    std::cout << fail_count << " tests failed" << std::endl;
    std::cout << pass_count << " tests passed" << std::endl;
    delete_2Darray(arr, 4);
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
        delete_2Darray(arr, rows);
    } else {
        std::cout << "Test failed: input data is invalid" << std::endl;
    }
    std::cout << std::endl;
}


int main() {
//    int **ppi = create_2D_indep_array<int>(3, 2);
//    int counter = 1;
//    for (int i = 0; i < 3; ++i) {
//        for (int j = 0; j < 2; ++j) {
//            ppi[i][j] = counter;
//            ++counter;
//        }
//    }

    std::cout << "============= Tests const_array =============" << std::endl;
    testConst_array(4, 3, 3);

    std::cout << "============= Tests ematrix =============" << std::endl;
    test_ematrix(10, 10);
    return 0;
}
