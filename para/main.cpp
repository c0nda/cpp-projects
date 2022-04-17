#include <iostream>
#include <string>
#include <fstream>
#include "Para.h"
#include "BitBuffer.h"

void compression(const char *filename1, const char *filename2, unsigned int bits,
                 BinTree<Para<std::string, unsigned int>> &dict,
                 unsigned int freeCode, unsigned int maxCode) {
    std::ifstream inFile;
    inFile.open(filename1, std::ios_base::binary);
    std::ofstream outFile;
    outFile.open(filename2, std::ios_base::binary);
    if (!inFile.is_open() || !outFile.is_open()) {
        std::cout << "Can't open file" << std::endl;
    } else {
        std::string cur_seq;
        char next;
        BitBuffer buffer;
        inFile.read((char *) &next, sizeof(char));
        cur_seq = next;
        while (inFile.peek() != EOF) {
            inFile.read((char *) &next, sizeof(char));
            for (auto i = dict.rewind(); i != dict.fastForward(); i.moveNext()) {
                if (i.getCurValue().getWhat() == cur_seq + next) {
                    cur_seq += next;
                    break;
                } else {
                    for (auto j = dict.rewind(); j != dict.fastForward(); j.moveNext()) {
                        if (j.getCurValue().getWhat() == cur_seq) {
                            buffer.addBits(j.getCurValue().getTo(), bits);
                            break;
                        }
                    }
                    unsigned char byte = 0;
                    while (buffer.checkSize()) {
                        byte = buffer.getByte();
                        outFile.write((const char *) &byte, sizeof(char));
                    }
                    if (freeCode <= maxCode) {
                        dict.add(Para<std::string, unsigned int>(cur_seq + next, freeCode));
                    }
                    ++freeCode;
                    cur_seq = next;
                }
            }
        }
        for (auto j = dict.rewind(); j != dict.fastForward(); j.moveNext()) {
            if (j.getCurValue().getWhat() == cur_seq) {
                buffer.addBits(j.getCurValue().getTo(), bits);
                break;
            }
        }
        unsigned char byte = 0;
        while (buffer.checkSize()) {
            byte = buffer.getByte();
            outFile.write((const char *) &byte, sizeof(char));
        }
        if (freeCode <= maxCode) {
            dict.add(Para<std::string, unsigned int>(cur_seq + next, freeCode));
        }
        byte = buffer.getByte();
        outFile.write((const char *) &byte, sizeof(char));
    }
}

int main() {
    BinTree<Para<std::string, unsigned int>> dict;
    dict.add(Para<std::string, unsigned int>("a", 0));
    dict.add(Para<std::string, unsigned int>("b", 1));
    dict.add(Para<std::string, unsigned int>("c", 2));
    dict.add(Para<std::string, unsigned int>("e", 3));
    dict.add(Para<std::string, unsigned int>("d", 4));
    unsigned int bits = 3, freeCode = 5, maxCode = 7;
    compression("C:/Users/Georgiy Voroncov/CLionProjects/para/file1.txt",
                "C:/Users/Georgiy Voroncov/CLionProjects/para/file2.txt", bits, dict, freeCode, maxCode);
    return 0;
}
