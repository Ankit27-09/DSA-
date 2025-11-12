// Question Link -> https://leetcode.com/problems/move-zeroes/

// Optimised approach 

#include <iostream>
#include <vector>
using namespace std;

/*
    ---------------------------------------------------------
                     MOVE ZEROES TO END
    ---------------------------------------------------------
    🔹 Problem:
       Given an array 'nums', move all 0's to the end 
       while maintaining the relative order of non-zero elements.

    🔹 Example:
        Input : [0, 1, 0, 3, 12]
        Output: [1, 3, 12, 0, 0]

    🔹 Approach: (Brute Force)
        - Create a new array of the same size initialized with 0.
        - Traverse the original array and copy only non-zero elements
          to the front of the new array.
        - Finally, copy all elements from the new array back into nums[].

    🔹 Time Complexity:  O(n)
    🔹 Space Complexity: O(n)  (since we use an extra array)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Create a result array filled with 0s
        vector<int> result(nums.size(), 0);

        // Pointer to track the next position for non-zero elements
        int idx = 0;

        // Step 1: Copy all non-zero elements into result[]
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                result[idx] = nums[i];
                idx++;
            }
        }

        // Step 2: Copy back the result array to original nums[]
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = result[i];
        }
    }
};

int main() {
    // Example array
    vector<int> nums = {0, 1, 0, 3, 12};

    // Create Solution object
    Solution sol;

    cout << "Original Array: ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    // Call moveZeroes()
    sol.moveZeroes(nums);

    cout << "Array after moving zeroes: ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    /*
        🔹 Dry Run Example:
            nums = [0, 1, 0, 3, 12]
            result = [0, 0, 0, 0, 0]

            i=0 → nums[0]=0 → skip
            i=1 → nums[1]=1 → result[0]=1
            i=2 → nums[2]=0 → skip
            i=3 → nums[3]=3 → result[1]=3
            i=4 → nums[4]=12 → result[2]=12

            result = [1, 3, 12, 0, 0]
            copy → nums = [1, 3, 12, 0, 0]
    */

    return 0;
}

/*
    ---------------------------------------------------------
                     COMPLEXITY ANALYSIS
    ---------------------------------------------------------
    ✅ Time Complexity: O(n)
       - First loop → O(n)
       - Second loop → O(n)
       - Total → O(2n) ≈ O(n)

    ✅ Space Complexity: O(n)
       - We used an extra array 'result' of size n
*/
