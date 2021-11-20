#include <iostream>
#include "testArrays.h"

//bool testConst_array(int **arr){
//    printArray(arr, 3, 3);
//    bool result = true;
//    if (result && 3 == getElement(arr, 3, 3, 1, 1, result) && 3 == getElement(arr, 3, 3, 2, 0, result)){
//        return true;
//    }
//    return false;
//}

int main() {
    int **ppi = create_2D_indep_array<int>(3, 3);
    int counter = 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ppi[i][j] = counter;
            ++counter;
        }
    }


    printArray(change2RowsOrColumns(ppi, 3, 3, 'c', 0, 1), 3, 3);
    delete_2Darray(ppi, 3);
    return 0;
}
