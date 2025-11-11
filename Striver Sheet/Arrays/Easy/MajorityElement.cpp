// Question Link  -> https://leetcode.com/problems/majority-element/description/

// Optimised Approach using Boyer Moore Voting Algorithm

#include <iostream>
#include <vector>
using namespace std;

// -----------------------------------------------------------
// Class: Solution
// Purpose: Find the Majority Element using Boyer–Moore Algorithm
// -----------------------------------------------------------
class Solution {
public:
    /*
        Function: majorityElement
        -------------------------
        Given an integer array 'nums', find the element that appears
        more than ⌊ n/2 ⌋ times (the majority element).

        Approach: Boyer–Moore Voting Algorithm
        ---------------------------------------
        1. Maintain two variables:
           - candidate → stores the current majority candidate
           - votes → keeps count of balance votes

        2. Traverse the array:
           - If votes == 0 → choose current element as new candidate.
           - If current element == candidate → increment votes.
           - Else → decrement votes.

        3. The final candidate after the loop is the majority element.

        Intuition:
        ----------
        - Majority element appears more than n/2 times,
          so it cannot be completely canceled out by other elements.

        Time Complexity:  O(n)
            → One pass through the array.
        Space Complexity: O(1)
            → Constant extra space.
    */
    int majorityElement(vector<int>& nums) { 
        int votes = 0;
        int candidate = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (votes == 0) {
                candidate = nums[i];
                votes = 1;
            } 
            else if (nums[i] == candidate) {
                votes++;
            } 
            else {
                votes--;
            }
        }

        return candidate;
    }
};

// -----------------------------------------------------------
// Main function for demonstration
// -----------------------------------------------------------
int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    Solution sol;
    int result = sol.majorityElement(nums);

    cout << "Majority Element: " << result << endl;

    // Expected Output: "Majority Element: 2"
    return 0;
}


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// -----------------------------------------------------------
// Class: Solution
// Purpose: Find the Majority Element in an array
// Approach: Using unordered_map to count frequencies
// -----------------------------------------------------------
class Solution {
public:
    /*
        Function: majorityElement
        -------------------------
        Given an integer array 'nums', find the element that appears
        more than ⌊ n/2 ⌋ times (the majority element).

        Approach:
        ----------
        - Use an unordered_map<int, int> to store frequency counts.
        - Iterate through the array and increment the count for each number.
        - After counting, iterate through the map to find the element
          whose frequency is greater than n/2.

        Time Complexity:  O(n)
            → One pass to count + one pass to find majority.
        Space Complexity: O(n)
            → For storing the frequency map.
    */
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;  // key: number, value: frequency
        int ans = 0;

        // Step 1: Count the frequency of each number
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        // Step 2: Find the number with frequency > n/2
        for (auto [num, freq] : mp) {
            if (freq > nums.size() / 2) {
                ans = num;
                break;  // Can break early once found
            }
        }

        return ans;
    }
};

// -----------------------------------------------------------
// Main function for demonstration
// -----------------------------------------------------------
int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    Solution sol;
    int result = sol.majorityElement(nums);

    cout << "Majority Element: " << result << endl;

    // Expected Output: "Majority Element: 2"
    return 0;
}
