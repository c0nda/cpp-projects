#include <iostream>
#include <fstream>
#include "testArrays.h"

std::string bin(int c) {
    int rem, counter = 0;
    std::string answer;
    char letter[] = {'0', '1'};
    while (c > 0) {
        rem = c % 2;
        for (int i = 0; i <= 1; ++i) {
            if (rem == i) {
                answer += letter[i];
                break;
            }
        }
        counter += 1;
        c /= 2;
    }

    for (int i = 0; i < counter / 2; ++i) {
        std::swap(answer[i], answer[counter - 1 - i]);
    }
    unsigned int len = answer.length();
    if (len < 8) {
        for (int i = 0; i < 8 - len; ++i) {
            answer = '0' + answer;
        }
    }
    return answer;
}

void file_copy_cout() {
    std::ofstream fs;
    fs.open("C:/Users/Georgiy Voroncov/Desktop/file1.txt", std::ios_base::trunc);
    if (fs.is_open()) {
        std::cout << "file opened" << std::endl;
        int **arr = create_2D_indep_array<int>(1000, 1000);
        for (int i = 0; i < 1000; ++i) {
            for (int j = 0; j < 1000; ++j) {
                arr[i][j] = rand() % 10;
                fs << arr[i][j] << " ";
            }
            fs << "\n";
        }
        fs.close();
        delete_2Darray(arr, 1000);
    }

    std::ifstream fs1;
    fs1.open("C:/Users/Georgiy Voroncov/Desktop/file1.txt");
    if (fs1.is_open()) {
        while (!fs1.eof()) {
            char c = fs1.get();
            std::cout << c;
        }
        fs1.close();
        std::cout << "file closed";
    }
}

void fileToImage(int num) {
    int counter = 0;
    std::ifstream fs;
    fs.open("C:/Users/Georgiy Voroncov/CLionProjects/22.11.2021/forimage.txt");
    if (fs.is_open()) {
        while (fs.peek() != EOF) {
            unsigned char c = fs.get();
            int size = (int) c;
            std::string bn = bin(size);
            unsigned long long len = bn.length();
            for (int i = 0; i < len; ++i) {
                if (bn[i] == '0') {
                    if (counter == num) {
                        std::cout << std::endl;
                        counter = 0;
                    }
                    std::cout << " ";
                }
                if (bn[i] == '1') {
                    if (counter == num) {
                        std::cout << std::endl;
                        counter = 0;
                    }
                    std::cout << "*";
                }
                ++counter;
            }
        }
        fs.close();
    }
}

int main() {
    fileToImage(20);
    return 0;
}