/*
Given an array of integers, find the one that appears an odd number of times.
There will always be only one integer that appears an odd number of times.
 */

#include <vector>
#include <algorithm>

int findOdd(const std::vector<int>& numbers){
    std::vector<int> cnumbers;
    cnumbers = numbers;
    int counter = 1;
    std::sort(cnumbers.begin(), cnumbers.end());
    for (unsigned int i = 0; i <= cnumbers.size() - 1; ++i){
        if (cnumbers[i + 1] == cnumbers[i]){
            counter += 1;
        } else {
            if (counter % 2 != 0){
                return cnumbers[i];
            } else {
                counter = 1;
            }
        }
    }
    return 0;
}