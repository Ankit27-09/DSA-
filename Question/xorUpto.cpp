class Solution {
public:
    // Helper function to compute XOR from 1 to n
    int xorUpto(int n) {
        // Pattern repeats every 4 numbers:
        // n % 4 == 0 -> result = n
        // n % 4 == 1 -> result = 1
        // n % 4 == 2 -> result = n + 1
        // n % 4 == 3 -> result = 0
        if (n % 4 == 0) return n;
        if (n % 4 == 1) return 1;
        if (n % 4 == 2) return n + 1;
        return 0; // when (n % 4 == 3)
    }

    // Function to find XOR of all numbers in range [l, r]
    int findXOR(int l, int r) {
        // XOR(1…r) ^ XOR(1…l-1) gives XOR(l…r)
        return xorUpto(r) ^ xorUpto(l - 1);
    }
};