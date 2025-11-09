#include <vector>
using namespace std;

class Solution {
public:
    // Recursive helper function to generate all subsets
    void solve(vector<int>& nums, vector<int>& temp, vector<vector<int>>& result, int index) {
        // Base case: If 'index' has reached the end of the nums array,
        // we have formed one possible subset.
        if (index >= nums.size()) {
            result.push_back(temp);  // Add the current subset (temp) to result
            return;
        }

        // -------------------------
        // 1️⃣ CHOICE 1: INCLUDE nums[index]
        // -------------------------
        // Add the current element to our temporary subset
        temp.push_back(nums[index]);

        // Explore further subsets including this element
        solve(nums, temp, result, index + 1);

        // -------------------------
        // 2️⃣ BACKTRACK (UNDO THE CHOICE)
        // -------------------------
        // Remove the last added element (to undo the previous choice)
        temp.pop_back();

        // -------------------------
        // 3️⃣ CHOICE 2: EXCLUDE nums[index]
        // -------------------------
        // Explore further subsets *without* including this element
        solve(nums, temp, result, index + 1);
    }

    // Main function that initializes variables and calls the recursive helper
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;  // To store all subsets
        vector<int> temp;            // Temporary list to build subsets
        int index = 0;               // Start recursion from index 0

        // Start recursive exploration
        solve(nums, temp, result, index);

        // Return all generated subsets
        return result;
    }
};
