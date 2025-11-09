#include <iostream>
using namespace std;

class Solution {
public:
    // ------------------------------------------------------------
    // Function: printPrimeFactors
    // Purpose: Print all prime factors of a given number n
    // ------------------------------------------------------------
    // Prime factors of n are the prime numbers that divide n exactly.
    // Example:
    //   n = 28 → Prime factors = 2, 2, 7
    //   Because 28 = 2 × 2 × 7
    // ------------------------------------------------------------
    void printPrimeFactors(int n) {
        // Step 1: Handle factor 2 separately
        // Why? Because it's the only even prime
        while (n % 2 == 0) {
            cout << 2 << " ";
            n /= 2; // keep dividing n by 2 until it's odd
        }

        // Step 2: Handle odd factors
        // We only need to check till sqrt(n)
        // Because if n has a factor > sqrt(n), the other factor is < sqrt(n)
        for (int i = 3; i * i <= n; i += 2) {
            // While i divides n, print i and divide n
            while (n % i == 0) {
                cout << i << " ";
                n /= i;
            }
        }

        // Step 3: If n is still > 2, then n itself is prime
        // Example: n = 29 (prime) → It won’t be divided by any i ≤ sqrt(29)
        if (n > 2) {
            cout << n << " ";
        }
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Prime factors of " << n << " are: ";
    sol.printPrimeFactors(n);
    cout << endl;

    return 0;
}
