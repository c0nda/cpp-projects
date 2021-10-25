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


int main() {
    minelemAndAverage();
}
