#include <iostream>

void integral_image(int *arr, int rows, int columns) {
    std::cout << arr[0] << " ";
    for (int j = 1; j < columns; ++j) {
        arr[j] += arr[j - 1];
        std::cout << arr[j] << " ";
    }
    std::cout << std::endl;

    for (int i = 1; i < rows; ++i) {
        arr[columns * i] += arr[columns * (i - 1)];
        std::cout << arr[columns * i] << " ";
    }

    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < columns; ++j) {
            arr[columns * i + j] += arr[columns * i + j - 1] + arr[columns * (i - 1) + j];
            std::cout << arr[columns * i + j] << " ";
        }
    }
}

//int search_elem(int *arr, int rows, int columns) {
//    int n;
//    std::cin >> n;
//    for (int j = 0; j < rows; ++j){
//        if (n < arr[columns * j + j]) {
//            continue;
//        }
//        if (n == arr[columns * j + j]) {
//            std::cout << n << " was found";
//            return 0;
//        } else {
//            for (int m = 0; m < j; ++m) {
//                if (arr[columns * m + j] < n) {
//                    continue;
//                }
//                if (arr[columns * m + j] > n) {
//                    break;
//                } else {
//                    std::cout << n << " was found";
//                    return 0;
//                }
//            }
//            for (int k = 0; k < j; ++k) {
//                if (arr[columns * j + k] < n) {
//                    continue;
//                }
//                if (arr[columns * j + k] > n) {
//                    break;
//                } else {
//                    std::cout << n << " was found";
//                    return 0;
//                }
//            }
//            if (n == arr[columns *  || n == arr[i - 1][j + 1]) {
//                return 1;
//            }
//            break;
//        }
//    }
//    return 0;
//}

int main() {
    int *p;
    int array[2][3] = {{1, 7, 4},
                       {9, 4, 8}};
    p = &array[0][0];
    integral_image(p, 2, 3);
    return 0;
}
