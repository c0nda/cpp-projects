#include <iostream>
#include <fstream>

void sequence(const char *infilename, const char *outfilename) {
    std::ifstream inFile;
    inFile.open(infilename, std::ios_base::binary);
    std::ofstream outFile;
    outFile.open(outfilename, std::ios_base::binary);
    if (!inFile.is_open() || !outFile.is_open()) {
        std::cout << "Can't open file" << std::endl;
        return;
    }
    int counter = 1;
    char buffer1, buffer2;
    inFile.read(&buffer1, sizeof(char));
    while (inFile.peek() != EOF) {
        inFile.read(&buffer2, sizeof(char));
        if (buffer1 == buffer2) {
            ++counter;
        } else {
            outFile << counter;
            outFile << buffer1;
            counter = 1;
            buffer1 = buffer2;
        }
    }
    outFile << counter;
    outFile << buffer1;
}

void sequenceBytes(const char *infilename, const char *outfilename) {
    std::ifstream inFile;
    inFile.open(infilename, std::ios_base::binary);
    std::ofstream outFile;
    outFile.open(outfilename, std::ios_base::binary);
    if (!inFile.is_open() || !outFile.is_open()) {
        std::cout << "Can't open file" << std::endl;
        return;
    }

    int counter = 1;
    char null = '\0';
    char buffer1, buffer2;
    inFile.read(&buffer1, sizeof(char));
    while (inFile.peek() != '\r') {
        inFile.read(&buffer2, sizeof(char));
        if (buffer1 == buffer2) {
            ++counter;
        } else {
            outFile.write((char *) &null, sizeof(char));
            outFile.write((char *) &counter, sizeof(char));
            outFile.write(&buffer1, sizeof(char));
            counter = 1;
            buffer1 = buffer2;
        }
    }
    outFile.write((char *) &null, sizeof(char));
    outFile.write((char *) &counter, sizeof(char));
    outFile.write(&buffer1, sizeof(char));
}

int main() {
    return 0;
}
