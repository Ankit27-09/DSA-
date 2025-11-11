//  Question Link -> https://leetcode.com/problems/two-sum/description/

#include <iostream>
#include <vector>
using namespace std;

// -----------------------------------------------------------
// Class: Solution2
// Purpose: Solve the "Two Sum" problem using a brute-force approach
// -----------------------------------------------------------
class Solution2 {
public:
    /*
        Function: twoSum
        -----------------
        Given an array of integers (nums) and a target integer (target),
        return the indices of the two numbers such that they add up to target.

        Approach:
        ----------
        - Use two nested loops to check every possible pair (i, j).
        - For each pair, check if nums[i] + nums[j] == target.
        - If true, store both indices in a vector and return it.

        Time Complexity:  O(n^2)
            → Because for each element, we check every other element.

        Space Complexity: O(1)
            → No extra data structures used (except the answer vector).
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans; // to store the indices of the two numbers that sum to target

        // Outer loop: pick the first number
        for (int i = 0; i < nums.size(); i++) {
            // Inner loop: pick the second number after i
            for (int j = i + 1; j < nums.size(); j++) {

                // Check if the two numbers add up to the target
                if (nums[i] + nums[j] == target) {

                    // Store their indices
                    ans.push_back(i);
                    ans.push_back(j);

                    // Once we found the pair, we can return immediately
                    // because the problem guarantees exactly one valid answer
                    return ans;
                }
            }
        }

        // If no such pair found (shouldn't happen per problem statement)
        return ans;
    }
};

// -----------------------------------------------------------
// Main function for demonstration (optional)
// -----------------------------------------------------------
int main() {
    // Example input
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Create an object of Solution2
    Solution2 sol;

    // Call the twoSum function
    vector<int> result = sol.twoSum(nums, target);

    // Print the result
    cout << "Indices of numbers that add up to " << target << " are: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    // Expected output: "Indices of numbers that add up to 9 are: 0 1"
    return 0;
}


// Optimized Approach
#include <iostream>  // Includes all standard C++ libraries
#include <unordered_map>
#include <vector>
using namespace std;

// -----------------------------------------------------------
// Class: Solution
// Purpose: Solve the "Two Sum" problem using an optimized approach
//          with an unordered_map (Hash Map)
// -----------------------------------------------------------
class Solution {
public:
    /*
        Function: twoSum
        -----------------
        Given an array of integers (nums) and a target integer (target),
        return the indices of the two numbers such that they add up to target.

        Approach:
        ----------
        - Use an unordered_map (hash map) to store elements we have already seen.
          Key   → number (nums[i])
          Value → index (i)
        
        - For each element nums[i]:
            1. Compute its complement → findVal = target - nums[i].
            2. Check if the complement already exists in the map.
               - If yes, return both indices (the index of the complement and i).
               - If not, store the current number with its index in the map.
        
        - This way, each element is processed once → giving O(n) time complexity.

        Time Complexity:  O(n)
            → Each lookup and insertion in unordered_map is O(1) on average.
        
        Space Complexity: O(n)
            → We store up to n elements in the map.
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;  // Stores {value : index}
        vector<int> ans;             // To store and return the indices

        // Traverse the array once
        for (int i = 0; i < nums.size(); i++) {
            int findVal = target - nums[i]; // The complement we are looking for

            // Step 1: Check if the complement exists in the map
            if (mp.find(findVal) != mp.end()) {
                // Found! Return indices of complement and current number
                ans.push_back(mp[findVal]); // index of complement
                ans.push_back(i);            // current index
                return ans;                  // We can return immediately
            }

            // Step 2: Otherwise, store the current number with its index
            mp[nums[i]] = i;
        }

        // If no pair found (shouldn't happen per problem constraints)
        return ans;
    }
};

// -----------------------------------------------------------
// Main function for demonstration (optional)
// -----------------------------------------------------------
int main() {
    // Example input
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Create an object of Solution
    Solution sol;

    // Call the optimized twoSum function
    vector<int> result = sol.twoSum(nums, target);

    // Print the result
    cout << "Indices of numbers that add up to " << target << " are: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    // Expected output: "Indices of numbers that add up to 9 are: 0 1"
    return 0;
}
