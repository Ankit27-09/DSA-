#include <iostream>
using namespace std;

class Solution {
public:
    // Helper function: computes (mid ^ n) safely
    // Uses long long to avoid overflow for large values
    long long power(int mid, int n) {
        long long result = 1;

        // Multiply 'mid' n times
        for (int i = 0; i < n; i++) {
            result *= mid;

            // If result grows too large, return a cap value
            // (1e18 chosen because it fits in long long, prevents overflow)
            if (result > 1e18) return 1e18;
        }

        return result;
    }

    // Function to find the integer n-th root of m using Binary Search
    int nthRoot(int n, int m) {
        int start = 1;       // smallest possible root
        int end = m;         // largest possible root (since root cannot exceed m)

        while (start <= end) {
            // Midpoint calculation (avoid overflow with start + (end - start)/2)
            int mid = start + (end - start) / 2;

            // Compute mid^n
            long long midPower = power(mid, n);

            // Case 1: mid^n == m → we found the exact integer root
            if (midPower == m) {
                return mid;  
            }
            // Case 2: mid^n < m → root must be bigger, search in right half
            else if (midPower < m) {
                start = mid + 1;
            }
            // Case 3: mid^n > m → root must be smaller, search in left half
            else {
                end = mid - 1;
            }
        }

        // If no integer root exists (e.g., sqrt(10)), return -1
        return -1;
    }
};

// Driver Code for testing
int main() {
    Solution sol;

    int n = 3, m = 27; // Example: cube root of 27
    int root = sol.nthRoot(n, m);

    if (root != -1)
        cout << "The " << n << "-th root of " << m << " is: " << root << endl;
    else
        cout << m << " does not have an exact integer " << n << "-th root." << endl;

    return 0;
}
