// Given a non-negative number n . The problem is to set the rightmost unset bit in the binary representation of n.

// In this problem, we have to remove the last set bit of a number.
// For example, if the number is 12 (1100 in binary), then the output should be 8 (1000 in binary) as the last set bit is removed.

// we know if N = 40 (101000 in binary)
// then N-1 = 39 (100111 in binary)
// Now, if we do AND of N and N-1, we get 32 (100000 in binary) which is the number after removing the last set bit of N.

#include <iostream>
using namespace std;
int removeLastSetBit(int n) {
    return n & (n - 1);
}