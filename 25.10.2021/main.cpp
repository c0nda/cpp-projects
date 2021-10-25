#include <iostream>

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

    for (int i = 0; i <= n - 1; ++i){
        sum += array[i];
        if (array[i] == min){
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
    for (int i = 0; i < len; ++i){
        rand_values[len] = values[0 + rand() % 15]; // NOLINT(cert-msc30-c, cert-msc50-cpp)
        std::cout << rand_values[len] << " ";
    }

}

int main() {
//    minelemAndAverage();
    hex_array();
}
