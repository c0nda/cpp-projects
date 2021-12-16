#include <string>
#include <iostream>

// Basic Mathematical Operations
int basicOp(char op, int val1, int val2) {
    if (op == '+') {
        return val1 + val2;
    }
    if (op == '-') {
        return val1 - val2;
    }
    if (op == '*') {
        return val1 * val2;
    }
    if (op == '/') {
        return val1 / val2;
    }
    return 0;
}

// Reversed Strings
std::string reverseString (std::string str )
{
    size_t len = str.length();
    for (size_t i = 0; i < len / 2; ++i){
        std::swap(str[i], str[len - 1 - i]);
    }
    return str;
}

// Remove String Spaces
std::string no_space(std::string x){
    std::string answer;
    size_t len = x.length();
    for (size_t i = 0; i < len; ++i){
        if (x[i] != ' '){
            answer += x[i];
        }
    }
    return answer;
}

// Grasshopper - Summation
int summation(int num){
    return (1 + num) * num / 2;
}

// Century From Year
int centuryFromYear(int year) {
    if (year % 100){
        return year / 100 + 1;
    } else {
        return year / 100;
    }
}

// Even or Odd
std::string even_or_odd(int number) {
    if (number % 2){
        return "Odd";
    }
    return "Even";
}

// Opposite number
int opposite(int number) {
    return -number;
}

// Convert boolean values to strings 'Yes' or 'No'.
std::string bool_to_word(bool value){
    if (value) return "Yes";
    return "No";
}

// Twice as old
int twice_as_old(int dad, int son) {
    return abs(dad - 2 * son);
}

// Convert a Number to a String!
std::string number_to_string(int num) {
    return std::to_string(num);
}