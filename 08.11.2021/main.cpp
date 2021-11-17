#include <iostream>

void printArray(int **arr, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}


void din_array(int start, int end) {
    int counter = start;
    for (int i = 0; i < end - start + 1; ++i) {
        int *p = new int[i];
        p[i] = counter;
        ++counter;
        std::cout << p[i] << " ";
        delete[] p;
    }
}


void straight_snake_array_indep() {

    int rows, columns;
    std::cin >> rows >> columns;
    int **ppi = new int *[rows];

    int counter = 1;

    for (int i = 0; i < rows; ++i) {

        ppi[i] = new int[columns];

        for (int j = 0; j < columns; ++j) {
            if (i % 2 == 0) {
                ppi[i][j] = counter;
                ++counter;
            } else {
                ppi[i][j] = counter + columns - 1;
                --counter;
            }
        }
        counter = columns * (i + 1) + 1;
    }

    printArray(ppi, rows, columns);

    for (int i = 0; i < rows; ++i) {
        delete[] ppi[i];
    }

    delete[] ppi;
}

void straight_snake_array_dep() {

    int rows, columns;
    std::cin >> rows >> columns;

    int *pi = new int[rows * columns];
    int **ppi = new int *[rows];

    for (int i = 0, j = 0; i < rows * columns; i += columns, ++j) {
        ppi[j] = &pi[i];
    }

    int counter = 1;

    for (int i = 0; i < rows; ++i) {

        for (int j = 0; j < columns; ++j) {
            if (i % 2 == 0) {
                ppi[i][j] = counter;
                ++counter;
            } else {
                ppi[i][j] = counter + columns - 1;
                --counter;
            }
        }
        counter = columns * (i + 1) + 1;
    }

    printArray(ppi, rows, columns);

    for (int i = 0; i < rows; ++i) {
        delete[] ppi[i];
    }

    delete[] pi;
    delete[] ppi;
}


void diagonal_snake_array_indep() {
    int rows, columns, counter = 1;

    std::cin >> rows >> columns;
    int **ppi = new int *[rows];

    for (int i = 0; i < rows; ++i) {
        ppi[i] = new int[columns];
    }

    for (int sum = 1; sum <= rows + columns - 1; ++sum) {
        for (int i = 0, j = sum - 1; i < sum; ++i, --j) {
            if (sum % 2 == 0) {
                if (i < rows && j < columns) {
                    ppi[i][j] = counter;
                    ++counter;
                } else {
                    continue;
                }
            } else {
                if (j < rows && i < columns) {
                    ppi[j][i] = counter;
                    ++counter;
                } else {
                    continue;
                }
            }
        }
    }

    printArray(ppi, rows, columns);

    for (int i = 0; i < rows; ++i) {
        delete[] ppi[i];
    }

    delete[] ppi;
}

void diagonal_snake_array_dep() {
    int rows, columns, counter = 1;

    std::cin >> rows >> columns;

    int *pi = new int[rows * columns];
    int **ppi = new int *[rows];

    for (int i = 0, j = 0; i < rows * columns; i += columns, ++j) {
        ppi[j] = &pi[i];
    }

    for (int sum = 1; sum <= rows + columns - 1; ++sum) {
        for (int i = 0, j = sum - 1; i < sum; ++i, --j) {
            if (sum % 2 == 0) {
                if (i < rows && j < columns) {
                    ppi[i][j] = counter;
                    ++counter;
                } else {
                    continue;
                }
            } else {
                if (j < rows && i < columns) {
                    ppi[j][i] = counter;
                    ++counter;
                } else {
                    continue;
                }
            }
        }
    }

    printArray(ppi, rows, columns);

    for (int i = 0; i < rows; ++i) {
        delete[] ppi[i];
    }

    delete[] ppi;
    delete[] pi;
}

void circle_snake() {
    int rows, columns, counter = 1, min_value, min_name, max_name;
    bool stop = true;
    std::cin >> rows >> columns;

    int **ppi = new int *[rows];

    for (int i = 0; i < rows; ++i) {
        ppi[i] = new int[columns];
    }
    if (rows >= columns) {
        min_value = columns / 2 + columns % 2;
        min_name = columns;
        max_name = rows;
    } else {
        min_value = rows / 2 + rows % 2;
        min_name = rows;
        max_name = columns;
    }

    if (columns > rows) {
        std::swap(max_name, min_name);
    }

    for (int i = 0; i < min_value; ++i) {

        if (counter > rows * columns) break;
        for (int j = i; j < columns - i; ++j) {
            ppi[i][j] = counter;
            ++counter;
        }
        if (counter > rows * columns) break;
        for (int k = 1 + i; k < rows - i; ++k) {
            ppi[k][min_name - 1 - i] = counter;
            ++counter;
        }
        if (counter > rows * columns) break;
        for (int m = columns - 2 - i; m >= i; --m) {
            ppi[max_name - 1 - i][m] = counter;
            ++counter;
        }
        if (counter > rows * columns) break;
        for (int n = rows - 2 - i; n >= i + 1; --n) {
            ppi[n][i] = counter;
            ++counter;
        }
        if (counter > rows * columns) break;
    }

    printArray(ppi, rows, columns);

    for (int i = 0; i < rows; ++i) {
        delete[] ppi[i];
    }
    delete[] ppi;
}

int main() {
//    int start, end;
//    std::cin >> start >> end;
//    din_array(start, end);
//    straight_snake_array_indep();
//    straight_snake_array_dep();
//    diagonal_snake_array_indep();
//    diagonal_snake_array_dep();
//    circle_snake();
    return 0;
}
