#include <iostream>
#include <fstream>
#include "testArrays.h"

// меняем местами длину и ширину картинки
//int main(int argc, char *argv[]) {
//    if (argc > 2) {
//        int width = 0, height = 0;
//        std::ifstream ifs;
//        ifs.open(argv[1], std::ios_base::binary);
//        if (ifs.is_open()) {
//            ifs.seekg(18);
//            ifs.read((char *) &width, sizeof(int));
//            ifs.read((char *) &height, sizeof(int));
//            std::cout << width << " " << height << std::endl;
//        }
//        std::ofstream ofs;
//        ofs.open(argv[2], std::ios_base::binary | std::ios_base::trunc);
//        int filesize = 0;
//        ifs.seekg(2);
//        ifs.read((char *) &filesize, sizeof(int));
//        int buffer[filesize];
//        ifs.seekg(std::ios::beg);
//        ifs.read((char *) &buffer, filesize * sizeof(char));
//        ofs.write((char *) &buffer, filesize * sizeof(char));
//        ofs.seekp(18);
//        ofs.write((char *) &height, sizeof(int));
//        ofs.write((char *) &width, sizeof(int));
//        ofs.close();
//        ifs.close();
//    } else {
//        std::cout << "Can't open file";
//    }
//    return 0;
//}

//std::string bin(int c) {
//    int rem, counter = 0;
//    std::string answer;
//    char letter[] = {'0', '1'};
//    while (c > 0) {
//        rem = c % 2;
//        for (int i = 0; i <= 1; ++i) {
//            if (rem == i) {
//                answer += letter[i];
//                break;
//            }
//        }
//        counter += 1;
//        c /= 2;
//    }
//
//    for (int i = 0; i < counter / 2; ++i) {
//        std::swap(answer[i], answer[counter - 1 - i]);
//    }
//    unsigned int len = answer.length();
//    if (len < 8) {
//        for (int i = 0; i < 8 - len; ++i) {
//            answer = '0' + answer;
//        }
//    }
//    return answer;
//}

// рисунок файла
//int main(int argc, char *argv[]) {
//    if (argc > 1) {
//        int counter = 0;
//        std::ifstream ifs;
//        ifs.open(argv[1], std::ios_base::binary);
//        if (ifs.is_open()) {
//            ifs.seekg(10);
//            int px = 0;
//            ifs.read((char *) &px, sizeof(int));
//            ifs.seekg(28);
//            int bpp = 0;
//            ifs.read((char *) &bpp, sizeof(int));
//            ifs.seekg(px);
//            int color2 = 0;
//            for (int i = 1; i <= 128; ++i) {
//                if (counter == 32) {
//                    std::cout << std::endl;
//                    counter = 0;
//                }
//                ifs.read((char *) &color2, sizeof(char));
//                std::string val_color2 = bin(color2);
//                for (int j = 0; j < 8; ++j){
//                    std::cout << val_color2[j];
//                }
//                counter += 8;
//            }
//            ifs.close();
//        } else {
//            std::cout << "Can't open file";
//        }
//    }
//    return 0;
//}

// порядок хранения цветов rgb
//int main(int argc, char *argv[]) {
//    if (argc > 3) {
//        std::ifstream red;
//        red.open(argv[1], std::ios_base::binary);
//        std::ifstream green;
//        green.open(argv[2], std::ios_base::binary);
//        std::ifstream blue;
//        blue.open(argv[3], std::ios_base::binary);
//        int px, buffer;
//        if (red.is_open()) {
//            red.seekg(10);
//            red.read((char *) &px, sizeof(int));
//            red.seekg(px + 3);
//            std::cout << "Full red: ";
//            for (int i = 0; i < 3; ++i) {
//                red.read((char *) &buffer, sizeof(char));
//                std::cout << buffer << " ";
//            }
//            red.close();
//        } else {
//            std::cout << "Can't open file" << std::endl;
//        }
//        std::cout << std::endl;
//
//        if (green.is_open()) {
//            green.seekg(10);
//            green.read((char *) &px, sizeof(int));
//            green.seekg(px + 3);
//            std::cout << "Full green: ";
//            for (int i = 0; i < 3; ++i) {
//                green.read((char *) &buffer, sizeof(char));
//                std::cout << buffer << " ";
//            }
//            green.close();
//        } else {
//            std::cout << "Can't open file" << std::endl;
//        }
//        std::cout << std::endl;
//
//        if (blue.is_open()) {
//            blue.seekg(10);
//            blue.read((char *) &px, sizeof(int));
//            blue.seekg(px + 3);
//            std::cout << "Full blue: ";
//            for (int i = 0; i < 3; ++i) {
//                blue.read((char *) &buffer, sizeof(char));
//                std::cout << buffer << " ";
//            }
//            blue.close();
//        } else {
//            std::cout << "Can't open file" << std::endl;
//        }
//    }
//    return 0;
//}

// поменяли местами каналы красного и синего цвета(это не работает)
//int main(int argc, char *argv[]) {
//    if (argc > 2) {
//        std::ifstream ifs;
//        ifs.open(argv[1], std::ios_base::binary);
//        std::ofstream ofs;
//        ofs.open(argv[2], std::ios_base::binary);
//        if (ifs.is_open() && ofs.is_open()) {
//            int px, size;
//            ifs.seekg(2);
//            ifs.read((char *) &size, sizeof(int));
//            ifs.seekg(10);
//            ifs.read((char *) &px, sizeof(int));
//            ifs.seekg(px);
//            ofs.seekp(px);
//            char buffer[3];
//            for (int i = 0; i < (size - px) / 3; ++i) {
//                ifs.read((char *) &buffer[0], sizeof(char));
//                ifs.read((char *) &buffer[1], sizeof(char));
//                ifs.read((char *) &buffer[2], sizeof(char));
//                std::swap(buffer[0], buffer[2]);
//                ofs.write(buffer, 3 * sizeof(char));
//            }
//            ifs.close();
//            ofs.close();
//        } else {
//            std::cout << "Can't open file" << std::endl;
//        }
//    }
//    return 0;
//}


//int main(int argc, char *argv[]) {
//    if (argc > 2) {
//        std::ifstream ifs;
//        std::ofstream ofs;
//        ifs.open(argv[1], std::ios_base::binary);
//        ofs.open(argv[2], std::ios_base::binary);
//        int width, height, px, bpp;
//        ifs.seekg(18);
//        ifs.read((char *) &width, sizeof(int));
//        ifs.read((char *) &height, sizeof(int));
//        ifs.seekg(28);
//        ifs.read((char *) &bpp, sizeof(int));
//        ifs.seekg(10);
//        ifs.read((char *) &px, sizeof(int));
//        ifs.seekg(px);
//        unsigned char **bytes = create_2D_indep_array<unsigned char>(width, height);
//        unsigned char first;
//        ifs.seekg(px);
//        ifs.read((char *) &first, bpp);
//        for (size_t i = 0; i < width; ++i) {
//            for (size_t j = 0; j < height; ++j) {
//                ifs.read((char *) &bytes[i][j], bpp);
//                if (first == bytes[i][j]) {
//                    std::cout << 0 << " ";
//                } else {
//                    std::cout << 1 << " ";
//                }
//            }
//        }
//        ifs.close();
//        ofs.close();
//        delete_2Darray(bytes, width);
//    }
//    return 0;
//}

int main(int argc, char *argv[]) {
    if (argc > 2) {
        std::ifstream ifs;
        std::fstream ofs;
        ifs.open(argv[1], std::ios_base::binary);
        ofs.open(argv[2], std::ios_base::binary | std::ios_base::in | std::ios_base::out);
        if (ifs.is_open() && ofs.is_open()) {
            int width1, height1, width2, height2;
            ifs.seekg(18);
            ifs.read((char *) &width1, sizeof(int));
            ifs.read((char *) &height1, sizeof(int));
            ofs.seekp(18);
            ofs.read((char *) &width2, sizeof(int));
            ofs.read((char *) &height2, sizeof(int));
            if (width1 % 32 != 0) {
                width1 = width1 + 32 - (width1 % 32);
            }
            if (width2 % 32 != 0) {
                width2 = width2 + 32 - (width2 % 32);
            }
            std::cout << width1 << " " << height1 << " " << width2 << " " << height2 << std::endl;

            width1 = width1 / 8;
            width2 = width2 / 8;
            std::cout << width1 << " " << height1 << " " << width2 << " " << height2 << std::endl;
            char buffer[width1];
            for (int i = 1; i < height1; ++i) {
                ifs.seekg((-1) * width1 * i, std::ios::end);
                ifs.read((char *) &buffer, width1 * sizeof(char));
                ofs.seekp((-1) * width2 * i, std::ios::end);
                ofs.write(buffer, width1 * sizeof(char));
            }
            ifs.close();
            ofs.close();
        }
    }
    return 0;
}
