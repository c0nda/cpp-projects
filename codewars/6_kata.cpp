#include <string>
#include <vector>
#include <cmath>

// Count the smiley faces!
int countSmileys(std::vector<std::string> arr) {
    int counter = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i].find('D') != std::string::npos || arr[i].find(')') != std::string::npos) {
            if (arr[i].find(':') != std::string::npos || arr[i].find(';') != std::string::npos) {
                if (arr[i].length() == 2 || arr[i].find('-') != std::string::npos || arr[i].find('~') != std::string::npos)
                    counter += 1;
            }
        }
    }
    return counter;
}

// Bit Counting
unsigned int countBits(unsigned long long n) {
    int counter = 0;
    while (n > 0) {
        if (n % 2) {
            ++counter;
        }
        n /= 2;
    }
    return counter;
}

// Find the missing term in an Arithmetic Progression
static long findMissing(std::vector<long> list){
    int frst, scnd;
    for (size_t i = 1; i < list.size() - 1; ++i){
        frst = list[i] - list[i - 1];
        scnd = list[i + 1] - list[i];
        if (frst != scnd){
            if (frst > scnd){
                return list[i - 1] + scnd;
            } else {
                return list[i] + frst;
            }
        }
    }
    return 0;
}

// Sum of Digits / Digital Root
int digital_root(int n){
    int tmp_sum = 0;
    while (n > 9) {
        while (n > 0) {
            tmp_sum += n % 10;
            n /= 10;
        }
        n = tmp_sum;
        tmp_sum = 0;
    }
    return n;
}

// Tribonacci Sequence
std::vector<int> tribonacci(const std::vector<int> &signature, int n) {
    std::vector<int> result;
    for (int j = 0; j < 3; ++j) {
        result.push_back(signature[j]);
    }
    if (n >= 3) {
        for (int i = 3; i < n; ++i) {
            result.push_back(result[i - 3] + result[i - 2] + result[i - 1]);
        }
    }
    if (n >= 0 && n < 3) {
        for (int i = 0; i < 3 - n; ++i){
            result.pop_back();
        }
    }
    return result;
}

// Does my number look big in this?
bool narcissistic(int value) {
    int sum = 0, len = 0, tmp1_value = value, tmp2_value = value;
    while (tmp1_value){
        ++len;
        tmp1_value /= 10;
    }

    while (tmp2_value) {
        sum += pow(tmp2_value % 10, len);
        tmp2_value /= 10;
    }
    if (value == sum){
        return true;
    }
    return false;
}

// Duplicate Encoder
std::string duplicate_encoder(const std::string& word){
    std::string lower_word, answer;
    size_t len = word.length();
    for (size_t i = 0; i < len; ++i){
        if (int(word[i]) < 97){
            lower_word+= char(int(word[i]) + 32);
        } else {
            lower_word += word[i];
        }
    }
    for (size_t i = 0; i < len; ++i){
        int counter = 0;
        for (size_t j = 0; j < len; ++j){
            if (lower_word[i] == lower_word[j]){
                counter += 1;
            }
        }
        if (counter > 1){
            answer += ')';
        } else {
            answer += '(';
        }
    }
    return answer;
}

// A disguised sequence (I)
class HiddenSeq
{
public:
    static unsigned long long fcn(int n) {
        return std::pow(2, n);
    }
};

// 1/n- Cycle
int cycle(int n) {
    if (n % 2 == 0 || n % 5 == 0) return -1;
    int len = 0, num = 1;
    while (num != 1 || len == 0){
        num *= 10;
        num %= n;
        ++len;
    }
    return len;
}