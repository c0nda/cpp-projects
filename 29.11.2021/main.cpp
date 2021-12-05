#include <iostream>
#include <fstream>
#include "testArrays.h"

// копирования одного файла в другой
//int main(int argc, char* argv[]) {
//    char src_file_name[256], dest_file_name[256];
//    std::cout << "Input source file name: ";
//    std::cin.getline(src_file_name, 256);
//
//    std::ifstream inFile(src_file_name, std::ios_base::binary);
//    if (!inFile) {
//        std::cout << "Can not open file " << src_file_name << std::endl;
//        return 1;
//    }
//
//    std::cout << "Input destination file name: ";
//    std::cin.getline(dest_file_name, 256);
//
//    std::ofstream outFile(dest_file_name, std::ios_base::binary);
//    if (!outFile) {
//        std::cout << "Can not open file " << dest_file_name << std::endl;
//        inFile.close();
//        return 2;
//    }
//
//    int ch;
//    while ((ch = inFile.get()) != EOF) {
//        outFile.put(ch);
//    }
//
//    inFile.close();
//    outFile.close();
//    return 0;
//}

//запись двумерного массива в файл
//int main(int argc, char *argv[]) {
//    int c;
//    char space = ' ', newline = '\n';
//    int **arr = create_2D_indep_array<int>(3, 3);
//    for (int i = 0; i < 3; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            arr[i][j] = rand() % 10;
//        }
//    }
//    if (argc > 1) {
//        std::ofstream ofs;
//        ofs.open(argv[1], std::ios_base::trunc | std::ios_base::binary);
//        if (ofs.is_open()) {
//            for (int i = 0; i < 3; ++i) {
//                for (int j = 0; j < 3; ++j) {
//                    c = arr[i][j];
//                    ofs.write((char *) &c, sizeof(c));
//                    ofs.write((char *) &space, sizeof(space));
//                }
//                ofs.write((char *) &newline, sizeof(newline));
//            }
//            ofs.close();
//        } else {
//            std::cout << "Can't open file" << std::endl;
//        }
//    }
//    delete_2Darray(arr, 3);
//    return 0;
//}

//int main(int argc, char *argv[]){
//    if (argc > 1){
//        std::ifstream ifs;
//        ifs.open(argv[1], std::ios_base::binary){
//            if (ifs.is_open()){
//                ifs.read();
//            }
//        }
//    }
//    return 0;
//}

