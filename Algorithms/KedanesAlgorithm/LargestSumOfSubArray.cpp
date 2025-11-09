#include <iostream> 
using namespace std;


// 1. Approach where the time complexity is O(n2);

// class Solution {
//     public:
//         int maxSubArray(vector<int>& nums) {
//             int maxi = INT_MIN;
//             int n = nums.size();
//             for(int i = 0; i < n; i++) {
//                 int prefixSum = 0;
//                 for(int j = i; j < n; j++) {
//                     prefixSum += nums[j];
//                     maxi = max(prefixSum, maxi);
//                 }
//             }
//             return maxi;
//         }
//     };

// 2. Approach where the time complexity is O(n) using Kadane's algorithm
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            // Initialize the maximum subarray sum to the smallest possible integer
            int maxi = INT_MIN; 
            
            // This variable keeps track of the sum of the current subarray
            int prefixSum = 0; 
            
            // Iterate through each element of the array
            for (int i = 0; i < nums.size(); i++) { 
                
                // Add the current element to the running sum
                prefixSum += nums[i]; 
                
                // Update the maximum subarray sum found so far
                maxi = max(maxi, prefixSum); 
    
                // If the running sum becomes negative, reset it to 0
                // This is because a negative sum would decrease the sum of future elements
                if (prefixSum < 0) { 
                    prefixSum = 0;
                }
            }
            
            // Return the maximum subarray sum found
            return maxi; 
        }
    };
    