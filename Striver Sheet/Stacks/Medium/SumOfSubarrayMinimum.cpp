// Question Link -> https://leetcode.com/problems/sum-of-subarray-minimums/


// Optimised Approach by using the Stack based approach 
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
------------------------------------------------------------
PROBLEM: Sum of Subarray Minimums (LeetCode 907)
------------------------------------------------------------
Given an integer array 'arr', return the sum of the minimum
element of every subarray, modulo 1e9+7.

We use a Monotonic Stack approach (O(n)) to find for each
element:
    - The nearest smaller element to its LEFT (NSL)
    - The nearest smaller element to its RIGHT (NSR)

Then calculate each element's contribution to the final sum.
------------------------------------------------------------
*/

class Solution {
public:
    /*
    ------------------------------------------------------------
    Function: getNSL()
    Purpose : Finds index of Nearest Smaller element to the LEFT
    Example : For arr = [3, 1, 2, 4]
              NSL = [-1, -1, 1, 2]
    ------------------------------------------------------------
    */
    vector<int> getNSL(vector<int>& arr, int n) {
        stack<int> st;       // stack will store indices
        vector<int> nsl(n);  // result array for NSL indices

        for (int i = 0; i < n; i++) {
            // Pop all indices where arr[top] >= arr[i]
            // because they are not smaller than current element
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            // If stack is empty -> no smaller element to left
            // else -> top of stack is index of NSL
            nsl[i] = st.empty() ? -1 : st.top();

            // Push current index for future comparisons
            st.push(i);
        }

        return nsl;
    }

    /*
    ------------------------------------------------------------
    Function: getNSR()
    Purpose : Finds index of Nearest Smaller element to the RIGHT
    Example : For arr = [3, 1, 2, 4]
              NSR = [1, 4, 4, 4]
              (4 means "no smaller element to right", so n = 4)
    ------------------------------------------------------------
    */
    vector<int> getNSR(vector<int>& arr, int n) {
        stack<int> st;       // stack stores indices
        vector<int> nsr(n);  // result array for NSR indices

        for (int i = n - 1; i >= 0; i--) {
            // Pop all elements strictly greater than arr[i]
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            // If empty -> no smaller element to right
            // else -> top of stack is index of NSR
            nsr[i] = st.empty() ? n : st.top();

            // Push current index
            st.push(i);
        }

        return nsr;
    }

    /*
    ------------------------------------------------------------
    Function: sumSubarrayMins()
    Purpose : Calculates total sum of subarray minimums
    Formula : For each i,
              left = i - NSL[i]
              right = NSR[i] - i
              contribution = arr[i] * left * right
    ------------------------------------------------------------
    */
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;   // for modulo operations
        long long sum = 0;         // store total sum safely in long long

        // Step 1: Get NSL and NSR arrays
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        // Step 2: Calculate each element's contribution
        for (int i = 0; i < n; i++) {
            long long left = i - NSL[i];     // number of elements to the left including itself
            long long right = NSR[i] - i;    // number of elements to the right including itself

            // total number of subarrays where arr[i] is minimum
            long long totalWays = (left * right) % MOD;

            // contribution of arr[i]
            long long contribution = (arr[i] * totalWays) % MOD;

            // add to total sum with modulo
            sum = (sum + contribution) % MOD;
        }

        // Step 3: return final result
        return (int)sum;
    }
};

/*
------------------------------------------------------------
Driver code to test the function
------------------------------------------------------------
*/
int main() {
    Solution sol;

    // Example 1
    vector<int> arr1 = {3, 1, 2, 4};
    cout << "Example 1: [3,1,2,4]" << endl;
    cout << "Sum of Subarray Minimums = " << sol.sumSubarrayMins(arr1) << endl;
    // Expected Output: 17

    cout << "-----------------------------" << endl;

    // Example 2
    vector<int> arr2 = {11, 81, 94, 43, 3};
    cout << "Example 2: [11,81,94,43,3]" << endl;
    cout << "Sum of Subarray Minimums = " << sol.sumSubarrayMins(arr2) << endl;
    // Expected Output: 444

    return 0;
}

