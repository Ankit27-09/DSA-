// Leetcode:-- 476 Number Compliment

// To find the number of bits we have standard formula 
// number_of_bits = (int)(log2(n)) + 1
// Then we can find the mask by (1<<number_of_bits)

#include <iostream>
using namespace std;
// 1st approach 
int main() {
    int n = 5;
    int number_of_bits = (int)(log2(n)) + 1;

    // Now we can iterate to find the flip binary 
    for(int i = 0; i < number_of_bits; i++) {
        n = n ^ (1 << i);
        // 1 left shift by 0 ---> 0 0 1
        // 1 left shift by 1 ---> 0 1 0
        // 1 left shift by 2 ---> 1 0 0
    }
    cout << n << endl;
    return 0;
}

// 2Approach 
int main() {
    int n = 5;
    int number_of_bits = (int)(log2(n)) + 1;
    int mask = (1 << number_of_bits) - 1; // to make all bits 1
    // for example 
    // n = 5 ---> 1 0 1
    // number_of_bits = 3
    // mask = (1<<3) - 1 = 8 - 1 = 7 ---> 1 1 1
    int ans = n ^ mask; // XOR operation to flip the bits
    cout << ans << endl;
    return 0;
}