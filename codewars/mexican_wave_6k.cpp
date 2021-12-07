/*
 In this simple Kata your task is to create a function that turns a string into a Mexican Wave.
 You will be passed a string and you must return that string in an array where an uppercase letter is a person standing up.
 wave("hello") => []string{"Hello", "hEllo", "heLlo", "helLo", "hellO"}
 */

#include <vector>
#include <cctype>
#include <string>

std::vector<std::string> wave(std::string y) {
    std::vector<std::string> waves;
    size_t len = y.length();
    for (size_t i = 0; i < len; ++i) {
        if (y[i] != ' ') {
            std::string tmp = y;
            tmp[i] = std::toupper(tmp[i]);
            waves.push_back(tmp);
        }
    }
    return waves;
}
