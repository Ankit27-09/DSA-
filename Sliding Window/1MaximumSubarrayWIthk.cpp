// https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

#include <iostream>  // includes all standard libraries
using namespace std;
#include <vector>

class Solution {
public:
    // Function to find the maximum sum of any subarray of size k
    int maxSubarraySum(vector<int>& arr, int k) {
        // Two pointers for sliding window
        int i = 0;   // window start
        int j = 0;   // window end

        int maxi = INT_MIN;  // store the maximum sum found
        int sum = 0;         // current window sum

        // Traverse the array with j as the right end of the window
        while (j < arr.size()) {
            // Step 1: Add current element to the window sum
            sum += arr[j];

            // Step 2: If window size < k, just expand window (increase j)
            if ((j - i + 1) < k) {
                j++;
            }

            // Step 3: If window size == k, process this window
            else if ((j - i + 1) == k) {
                // Update maximum sum if current window sum is larger
                maxi = max(maxi, sum);

                // Before sliding the window:
                // remove the element at index i (leftmost element)
                sum -= arr[i];

                // Move window forward
                i++;
                j++;
            }
        }

        return maxi;
    }
};

int main() {
    // Example usage
    Solution sol;

    // Input array
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;

    // Function call
    int result = sol.maxSubarraySum(arr, k);

    // Output the result
    cout << "Maximum sum of subarray of size " << k << " is: " << result << endl;

    return 0;
}
