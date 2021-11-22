#include <iostream>
#include <fstream>
#include "testArrays.h"

int main() {
    std::ofstream fs;
    fs.open("C:/Users/Georgiy Voroncov/Desktop/file1.txt", std::ios_base::trunc);
    if (fs.is_open()) {
        std::cout << "file opened" << std::endl;
        int **arr = create_2D_indep_array<int>(2, 3);
        for (int i = 0; i < 2; ++i){
            for (int j = 0; j < 3; ++j){
                arr[i][j] = rand() % 10;
                fs << arr[i][j] << " ";
            }
            fs << "\n";
        }
        fs.close();
    }

    std::ifstream fs1;
    fs1.open("C:/Users/Georgiy Voroncov/Desktop/file1.txt");
    if (fs1.is_open()){
        while (!fs1.eof()){
            char c = fs1.get();
            std::cout << c;
        }
        fs1.close();
    }
    return 0;
}