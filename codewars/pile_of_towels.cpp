/*
6 kata

In my bathroom, there is a pile of n towels. A towel either has the color red or blue. We will represent the pile as sequence of red and blue.
The leftmost towel is at the bottom of the pile, the rightmost towel is at the top of the pile.
As the week goes by, I use t towels. Whenever I grab a new one it's always the towel at the top of the pile. All used towels are placed in a basket.
At the end of the week, I wash all used towels in the basket and put them on top of the existing pile again.
But my favorite color is blue, so I want to use blue towels as often as possible.
Therefore, when the washed towels are placed on the pile again, the blue towels are always on top of the red towels.

You are given an initial pile of towels as a sequence of the strings "red" and "blue".
On top of that, you receive a sequence of non-negative integers.
The first integer describes the number of used towels t in the first week, the second integer describes the number of used towels t in the second week and so forth.

My question is:
How will my pile of towels look like in the end, if I use t towels every week and place them on top of the the pile according to the rule defined above?
 */

#include <string>
#include <vector>

std::vector<std::string> sort_the_pile(std::vector<std::string> pile_of_towels, const std::vector<unsigned> &weekly_used_towels) {
    unsigned int size = pile_of_towels.size();
    unsigned int max_elem = 0;
    for (unsigned int weekly_used_towel : weekly_used_towels){
        if (max_elem < weekly_used_towel){
            max_elem = weekly_used_towel;
        }
    }
    for (unsigned int j = 0; j < max_elem; ++j) {
        for (unsigned int i = 1; i < max_elem - j; ++i) {
            if (pile_of_towels[size - i] > pile_of_towels[size - 1 - i]) {
                std::swap(pile_of_towels[size - i], pile_of_towels[size - 1 - i]);
            }
        }
    }
    return pile_of_towels;
}