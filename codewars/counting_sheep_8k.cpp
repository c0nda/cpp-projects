/*
Consider an array/list of sheep where some sheep may be missing from their place.
We need a function that counts the number of sheep present in the array (true means present).
 */

#include <vector>

using namespace std;

int count_sheep(vector<bool> arr)
{
    int counter = 0;
    for (int i = 0; i < arr.size(); ++i){
        if (arr[i]){
            counter += 1;
        }
    }
    return counter;
}

