#include <iostream>
#include <algorithm>

void minelemAndAverage() {
    double average, sum = 0;
    const int n = 10;
    int array[n] = {};
    int pos;
    for (int i = 0; i <= n; ++i) {
        array[i] = rand(); // NOLINT(cert-msc30-c, cert-msc50-cpp)
        std::cout << array[i] << std::endl;
    }
    int min = array[0];

    for (int i = 0; i <= n - 1; ++i) {
        if (min > array[i]) {
            min = array[i];
        }
    }
    std::cout << "Min: " << min << std::endl;

    for (int i = 0; i <= n - 1; ++i) {
        sum += array[i];
        if (array[i] == min) {
            pos = i;
            std::cout << pos << " ";
        }
    }
    average = double(sum) / n;
    std::cout << average;
}

void hex_array() {
    int len;
    std::cin >> len;
    char rand_values[] = {};
    char values[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    for (int i = 0; i < len; ++i) {
        rand_values[len] = values[0 + rand() % 15]; // NOLINT(cert-msc30-c, cert-msc50-cpp)
        std::cout << rand_values[len] << " ";
    }

}

void reverse_array() {
    int swap;
    const int n = 4;
    int array[n];
    for (int i = 0; i <= n - 1; ++i) {
        array[i] = rand() % 100; // NOLINT(cert-msc30-c, cert-msc50-cpp)
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < n / 2; ++i) {
        swap = array[i];
        array[i] = array[n - 1 - i];
        array[n - 1 - i] = swap;
    }
    for (int i = 0; i <= n - 1; ++i) {
        std::cout << array[i] << " ";
    }
}

void moreLessAvg() {
    int swap;
    double avg, sum = 0;
    const int len = 10;
    int array[len];
    for (int i = 0; i <= len - 1; ++i) {
        array[i] = rand() % 100; // NOLINT(cert-msc30-c, cert-msc50-cpp)
        std::cout << array[i] << " ";
        sum += array[i];
    }

    std::cout << std::endl;

    avg = sum / double(len);
    for (int i = 0; i <= len - 1; ++i) {
        if (array[i] > avg) {
            for (int j = len - 1; j > i; --j) {
                if (array[j] < avg) {
                    swap = array[i];
                    array[i] = array[j];
                    array[j] = swap;
                    break;
                }
            }
        }
    }
    for (int i = 0; i <= len - 1; ++i) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl << avg;
}

void most_common_el() {
    int max, most_common, counter = 1;
    int values[10] = {1, 6, 9, 8, 7, 8, 7, 7, 2, 10};
    std::sort(values, values + 10);
    for (int i = 0; i < 10; ++i) {
        if (values[i + 1] == values[i]){
            counter += 1;
        } else{
            if (counter >= max){
                max = counter;
                most_common = values[i];
            }
            counter = 1;
        }
    }
    std::cout << most_common << " repeats " << max << " times";
}

// упорядочено попарно
void couples() {
    const int n = 5;
    int array1[n] = {22, 21, 8, 6, 3};
    int array2[n] = {0, 2, 4, 6, 8};
    int answer[n * 2];
    int j = 0;

    for (int i = 0; i <= n - 1; ++i) {
        if (array1[i] >= array2[i]) {
            answer[i + j] = array2[i];
            answer[i + 1 + j] = array1[i];
        } else {
            answer[i + j] = array1[i];
            answer[i + 1 + j] = array2[i];
        }
        ++j;
    }
    for (int i = 0; i <= n * 2 - 1; ++i) {
        std::cout << answer[i] << " ";
    }
}

void rand_for_2array() {
    int array[3][4];
    for (int i = 0; i <= 2; ++i) {
        for (int j = 0; j <= 3; ++j) {
            array[i][j] = rand() % 100; // NOLINT(cert-msc30-c, cert-msc50-cpp)
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

void t_matrix(){
    const int n = 4;
    const int k = 3;
    int array[n][k];
    for (int i = 0; i <= n - 1; ++i) {
        for (int j = 0; j <= k - 1; ++j) {
            array[i][j] = rand() % 100; // NOLINT(cert-msc30-c, cert-msc50-cpp)
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (int j = 0; j <= k - 1; ++j){
        for (int i = 0; i <= n - 1; ++i){
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
//    minelemAndAverage();
//    hex_array();
//    reverse_array();
//    moreLessAvg();
//    most_common_el();
//    couples();
//    rand_for_2array();
//    most_common_el();
//    t_matrix();
}