// Question Link -> https://leetcode.com/problems/sum-of-subarray-ranges/description/


//Better APproach using stack 
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:

    // ------------------ NEXT SMALLER TO LEFT (NSL) ------------------
    vector<int> getNSL(vector<int>& arr, int n) {
        stack<int> st;        // Stack to store indices
        vector<int> nsl(n);   // Store index of NSL for each element

        for (int i = 0; i < n; i++) {
            // Pop until we find a smaller element
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            // If stack empty -> no smaller element to left → use -1
            nsl[i] = st.empty() ? -1 : st.top();

            // Push current index
            st.push(i);
        }
        return nsl;
    }

    // ------------------ NEXT SMALLER TO RIGHT (NSR) ------------------
    vector<int> getNSR(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> nsr(n);

        for (int i = n - 1; i >= 0; i--) {
            // Pop until we find smaller element
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            // If none found → use n (out of bounds)
            nsr[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return nsr;
    }

    // ------------------ NEXT LARGER TO LEFT (NLL) ------------------
    vector<int> getNLL(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> nll(n);

        for (int i = 0; i < n; i++) {
            // Pop until we find a larger element
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            // If stack empty → no larger element to left
            nll[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return nll;
    }

    // ------------------ NEXT LARGER TO RIGHT (NLR) ------------------
    vector<int> getNLR(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> nlr(n);

        for (int i = n - 1; i >= 0; i--) {
            // Pop until we find a larger element
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }

            // If no larger element to right → use n
            nlr[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return nlr;
    }

    // ------------------ MAIN FUNCTION ------------------
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        // Get indices of smaller and larger elements
        vector<int> nsl = getNSL(nums, n);
        vector<int> nsr = getNSR(nums, n);
        vector<int> nll = getNLL(nums, n);
        vector<int> nlr = getNLR(nums, n);

        long long totalMax = 0, totalMin = 0;

        // Calculate contributions
        for (int i = 0; i < n; i++) {
            // For MAX contribution
            long long leftMax = i - nll[i];   // distance to left
            long long rightMax = nlr[i] - i;  // distance to right
            long long countMax = leftMax * rightMax;  // total subarrays where nums[i] is max
            totalMax += (long long)nums[i] * countMax;

            // For MIN contribution
            long long leftMin = i - nsl[i];
            long long rightMin = nsr[i] - i;
            long long countMin = leftMin * rightMin;
            totalMin += (long long)nums[i] * countMin;
        }

        // Final result = total contribution as max - total contribution as min
        return totalMax - totalMin;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3};
    cout << "Sum of Subarray Ranges: " << obj.subArrayRanges(nums) << endl;
    return 0;
}


// Time complexity -> O(N2)
// Space complexity -> O(1)
#include <iostream>
#include <vector>
#include <algorithm>  // for max() and min()
using namespace std;

class Solution {
public:
    // Function to calculate the sum of all subarray ranges
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;  // To store the total sum of ranges

        // Outer loop: choose each index as the starting point
        for (int i = 0; i < nums.size(); i++) {
            int largest = nums[i];   // current max in subarray
            int smallest = nums[i];  // current min in subarray

            // Inner loop: extend the subarray till the end
            for (int j = i; j < nums.size(); j++) {
                // Update largest and smallest for current subarray [i..j]
                largest = max(largest, nums[j]);
                smallest = min(smallest, nums[j]);

                // Add the range (max - min) of this subarray to total sum
                sum += (long long)(largest - smallest);
            }
        }

        return sum;  // Return the final result
    }
};

// Driver code to test the function
int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 2, 3};

    // Call the function
    long long result = sol.subArrayRanges(nums);

    // Output the result
    cout << "Sum of Subarray Ranges = " << result << endl;

    return 0;
}
