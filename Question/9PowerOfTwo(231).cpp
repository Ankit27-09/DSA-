// 1. Approach is by checking the number of set bits 
// A number is a power of two iff its binary representation has exactly one set bit (1).

// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         // Negative numbers and 0 cannot be powers of two
//         if (n <= 0) return false;

//         int count = 0; // count of set bits

//         while (n > 0) {
//             // Check last bit
//             if ((n & 1) == 1) {
//                 count++;
//             }
//             // Shift right to check next bit
//             n >>= 1;
//         }

//         // If only one bit was set, it's a power of 2
//         return count == 1;
//     }
// };

// 2. Approach is by doing the  N and N - 1
// Like if N is 16 --> 10000
// N - 1 would be right most side bit would be 0 and after then their reverse 

class Solution {
public:
    bool isPowerOfTwo(int n) { 
       // Edge case: negative numbers and 0 are not powers of two
        if (n <= 0) return false;

        // A power of two has only one set bit.
        // So, n & (n-1) will be 0 for powers of two.
        return (n & (n - 1)) == 0;
        return false;
    }
};