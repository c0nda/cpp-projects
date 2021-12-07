// createPhoneNumber(int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}) // => returns "(123) 456-7890"

#include <string>

std::string createPhoneNumber(const int arr [10]){
    std::string nums = "0123456789";
    std::string number;
    for (int i = 0; i < 10; ++i){
        number += nums[arr[i]];
    }
    number = "(" + number.substr(0, 3) + ") " + number.substr(3, 3) + "-" + number.substr(6, 4);
    return number;
}