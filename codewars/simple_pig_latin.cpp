/*
 5 kata
Move the first letter of each word to the end of it, then add "ay" to the end of the word. Leave punctuation marks untouched.
 pigIt('Pig latin is cool'); // igPay atinlay siay oolcay
 */

#include <string>

std::string pig_it(std::string str) {
    int counter = 0;
    char first;
    std::string answer;
    size_t len = str.length();
    for (size_t i = 0; i < len + 1; ++i) {
        if (str[i] >= 'A' && str[i] <= 'z') {
            if (counter == 0) {
                first = str[i];
            } else {
                answer += str[i];
            }
            ++counter;
        } else {
            if (counter > 0) {
                answer += first;
                answer += "ay";
                answer += str[i];
                counter = 0;
            } else {
                answer += str[i];
            }
        }
    }
    answer.pop_back();
    return answer;
}