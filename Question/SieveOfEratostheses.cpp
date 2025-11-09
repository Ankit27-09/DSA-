// for a prime the number having factors 1 and itself only.
// The Sieve of Eratosthenes is an efficient algorithm to find all prime numbers up to a specified integer n.
/*

Given a number n, find all prime numbers less than or equal to n.

Examples:

Input: n = 10
Output: [2, 3, 5, 7]
Explanation: The prime numbers up to 10 obtained by Sieve of Eratosthenes are [2, 3, 5, 7].

The Sieve of Eratosthenes efficiently finds all primes up to n by repeatedly marking multiples of each prime as non-prime, starting from 2. 
This avoids redundant checks and quickly filters out all composite numbers.
Step By Step Implementations:

Initialize a Boolean array prime[0..n] and set all entries to true, except for 0 and 1 (which are not primes).
For each number p from 2 up to √n:
If p is marked as prime(true):
Mark all multiples of p as not prime(false), starting from p * p (since smaller multiples have already been marked by smaller primes).
After the loop ends, all the remaining true entries in prime represent prime numbers.
*/

// Time complexity: O(n log log n)
// Space complexity: O(n)
#include <iostream>
using namespace std;
#include <vector>

vector<int> sieve(int n) {
    vector<bool> prime(n + 1, true); // Step 1: Initialize a boolean array of size n+1 with all entries as true
    prime[0] = prime[1] = false; // 0 and 1 are not prime numbers

    for (int p = 2; p * p <= n; p++) { // Step 2: Iterate from 2 to √n
        if (prime[p]) { // If p is still marked as prime
            for (int multiple = p * p; multiple <= n; multiple += p) { // Step 3: Mark multiples of p as not prime
                prime[multiple] = false;
            }
        }
    }

    vector<int> primes; // To store the list of prime numbers
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            primes.push_back(i); // Collecting all prime numbers
        }
    }

    return primes; // Return the list of prime numbers
}
int main() {
    int n = 35;
    vector<int> res = sieve(n);

    for(int elem: res) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}