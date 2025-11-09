// Question Link -> https://leetcode.com/problems/4sum/description/

// ✅ Brute-force optimized (two-pointer) approach for 4-Sum problem
// Time Complexity: O(n³)
// Space Complexity: O(1) (ignoring output vector)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Step 1: Sort the array to handle duplicates and use two pointers
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        // Step 2: Fix the first element (nums[i])
        for (int i = 0; i < n; i++) {
            // Skip duplicate elements for i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Step 3: Fix the second element (nums[j])
            for (int j = i + 1; j < n; j++) {
                // Skip duplicate elements for j
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Step 4: Use two pointers for remaining two elements
                int p = j + 1;
                int q = n - 1;

                // Step 5: Find pairs that make up the target
                while (p < q) {
                    // Use long long to avoid integer overflow
                    long long sum = (long long)nums[i] + nums[j] + nums[p] + nums[q];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});

                        // Move both pointers
                        p++;
                        q--;

                        // Skip duplicates for p
                        while (p < q && nums[p] == nums[p - 1]) p++;
                        // Skip duplicates for q
                        while (p < q && nums[q] == nums[q + 1]) q--;
                    }
                    else if (sum < target) {
                        p++; // Need a larger sum
                    }
                    else {
                        q--; // Need a smaller sum
                    }
                }
            }
        }

        return ans;
    }
};
