#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

// Reverse words
std::string reverse_words(std::string str) {
    size_t len = str.length();
    std::string buffer, answer;
    for (size_t i = 0; i < len; ++i) {
        if (str[i] != ' ') {
            buffer += str[i];
            continue;
        } else {
            if (!buffer.empty()) {
                size_t buf_len = buffer.length();
                for (size_t j = 0; j < buf_len / 2; ++j) {
                    std::swap(buffer[j], buffer[buf_len - 1 - j]);
                }
                answer += buffer;
                answer += ' ';
                buffer.clear();
            } else {
                answer += ' ';
            }
        }
    }
    if (!buffer.empty()) {
        size_t buf_len = buffer.length();
        for (size_t j = 0; j < buf_len / 2; ++j) {
            std::swap(buffer[j], buffer[buf_len - 1 - j]);
        }
        answer += buffer;
    }
    return answer;
}

// Get the Middle Character
std::string get_middle(const std::string& input) {
    size_t len = input.length();
    if (len % 2) {
        return input.substr(len / 2, 1);
    }
    return input.substr(len / 2 - 1, 2);
}

// Exes and Ohs
bool XO(const std::string& str){
    long long x = std::count(str.cbegin(), str.cend(), 'x') + std::count(str.cbegin(), str.cend(), 'X');
    long long o = std::count(str.cbegin(), str.cend(), 'o') + std::count(str.cbegin(), str.cend(), 'O');
    if (x == o) return true;
    return false;
}

// Complementary DNA
std::string DNAStrand(const std::string& dna){
    std::string answer;
    for (size_t i = 0; i < dna.length(); ++i){
        if (dna[i] == 'T'){
            answer += 'A';
            continue;
        }
        if (dna[i] == 'A'){
            answer += 'T';
            continue;
        }
        if (dna[i] == 'C'){
            answer += 'G';
            continue;
        }
        if (dna[i] == 'G'){
            answer += 'C';
            continue;
        }
    }
    return answer;
}

// Isograms
bool is_isogram(std::string str) {
    for (size_t i = 0; i < str.length(); ++i){
        for (size_t j = i + 1; j < str.length(); ++j){
            if (str[i] == str[j] || str[i] == char(int(str[j]) - 32) || str[i] == char(int(str[j]) + 32)){
                return false;
            }
        }
    }
    return true;
}

// Anagram Detection
bool isAnagram(std::string test, std::string original){
    if (test.length() != original.length()){
        return false;
    }
    for (size_t i = 0; i < test.length(); ++i){
        if (int(test[i]) < 97){
            test[i] = char(int(test[i]) + 32);
        }
        if (int(original[i]) < 97){
            original[i] = char(int(original[i]) + 32);
        }
    }
    for (size_t i = 0; i < test.length(); ++i){
        if (original.find(test[i]) != std::string::npos){
            original.erase(original.find(test[i]), 1);
        }
    }
    if (original.empty()){
        return true;
    }
    return false;
}

// Are the numbers in order?
bool isAscOrder(std::vector<int> arr)
{
    if (arr.size() == 1){
        return true;
    }
    for (size_t i = 0; i < arr.size() - 1; ++i){
        if (arr[i] > arr[i + 1]){
            return false;
        }
    }
    return true;
}

// Shortest Word
int find_short(std::string str){
    int counter = 0, min = 10000;
    for (size_t i = 0; i < str.length(); ++i){
        if (str[i] != ' '){
            ++counter;
        }
        if (str[i] == ' '){
            if (counter < min){
                min = counter;
            }
            counter = 0;
        }
    }
    if (counter < min){
        min = counter;
    }
    return min;
}

// Sum of two lowest positive integers
long long sumTwoSmallestNumbers(std::vector<int> numbers){
    long long min1 = 2000000000, min2 = 2000000000;
    for (size_t i = 0; i < numbers.size(); ++i){
        if (numbers[i] < min1){
            min1 = numbers[i];
        }
    }
    for (size_t i = 0; i < numbers.size(); ++i){
        if (numbers[i] < min2 && numbers[i] > min1){
            min2 = numbers[i];
        }
    }
    return min1 + min2;
}

// You're a square!
bool is_square(int n){
    int sq = int(sqrt(n));
    if (sq * sq == n){
        return true;
    }
    return false;
}

