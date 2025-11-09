// Check if Bit is Set or Not in C++

// So set bit means 1 and unset bit means 0
// To check if a bit is set or not, we can use the AND (&) operator
// At any position, if we AND a number with 1, we get the same bit
// At any position, if we AND a number with 0, we get 0
// if we want to check the bit at k position is set or not, we can do the following 
// 1. right shift the number by k positions
// 2. AND the result with 1

#include <iostream>
using namespace std;

bool isKthBitSet(int n, int k) {
    return (n >> k) & 1; // right shift n by k and AND with 1
}