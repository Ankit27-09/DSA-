// Intro TO Dynamic Programming
/*
Dynamic Programming (DP) Introduction
Last Updated : 23 Jul, 2025
Dynamic Programming is a commonly used algorithmic technique used to optimize recursive solutions when same subproblems are called again.

The core idea behind DP is to store solutions to subproblems so that each is solved only once.
To solve DP problems, we first write a recursive solution in a way that there are overlapping subproblems in the recursion tree (the recursive function is called with the same parameters multiple times)
To make sure that a recursive value is computed only once (to improve time taken by algorithm), we store results of the recursive calls.
There are two ways to store the results, one is top down (or memoization) and other is bottom up (or tabulation).
*/
#include <iostream>
using namespace std;
#include <vector>
// Example: Fibonacci Series using Dynamic Programming
// This function calculates the nth Fibonacci number using a bottom-up dynamic programming approach

int fibonacci(int n, vector<int> &fib) {
    // Base case
    if (n <= 1) {
        return n;
    }
    // step 3
    if(fib[n] != -1) {
        return fib[n]; // Return the stored value if it exists
    }
    // step 2
    fib[n] = fibonacci(n - 1, fib) + fibonacci(n - 2, fib); // Recursive call with memoization
    return fib[n]; // Return the computed Fibonacci number
 
}

int main() {
    int n;
    cin >> n; // Input the value of n
    vector<int> fib(n + 1);
    // step 1 
    for(int i = 0; i <= n; i++) {
        fib[i] = -1; // Initialize the vector to store Fibonacci numbers
    }
    cout << fibonacci(n, fib) << " "; // Example call to the fibonacci function
    return 0;
}

