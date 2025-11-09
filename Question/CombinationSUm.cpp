class Solution {
public:
    // Helper recursive function to find all combinations
    void solve(vector<int>& candidates, int target, vector<vector<int>>& result, int index, vector<int>& temp) {

        // ----------------------
        // Base Case: All elements processed
        // ----------------------
        // If we have considered all candidates (index reaches end of array)
        // then we check if the remaining target is zero.
        if (index == candidates.size()) {
            // If target == 0, current combination is valid
            if (target == 0) {
                // Add the current combination to the result
                result.push_back(temp);
            }
            // Return to previous recursive call
            return;
        }

        // ----------------------
        // Include current element
        // ----------------------
        // Only include the element if it does not exceed the remaining target
        if (candidates[index] <= target) {

            // Step 1: Choose the current element
            // Add it to the temporary combination
            temp.push_back(candidates[index]);

            // Step 2: Explore further with the updated target
            // Recurse with same index because we can reuse the same element multiple times
            solve(candidates, target - candidates[index], result, index, temp);

            // Step 3: Backtrack
            // Remove the last added element to undo the choice and try other possibilities
            temp.pop_back();
        }

        // ----------------------
        // Exclude current element
        // ----------------------
        // Move to the next index without including the current element
        // This explores combinations that do not contain candidates[index]
        solve(candidates, target, result, index + 1, temp);
    }

    // Main function to return all combinations
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Result vector to store all valid combinations
        vector<vector<int>> result;

        // Temporary vector to store current combination
        vector<int> temp;

        // Start recursion from index 0
        solve(candidates, target, result, 0, temp);

        // Return the result
        return result;
    }
};
