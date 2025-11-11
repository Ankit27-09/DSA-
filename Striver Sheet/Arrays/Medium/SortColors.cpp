// Question Link -> https://leetcode.com/problems/sort-colors/description/

//Optimized Approach 
#include <iostream>
#include <vector>
using namespace std;

// -----------------------------------------------------------
// Class: Solution
// Purpose: Sort an array containing 0s, 1s, and 2s using
//          the Dutch National Flag Algorithm (one-pass, in-place)
// -----------------------------------------------------------
class Solution {
public:
    /*
        Function: sortColors
        --------------------
        Sorts the array nums (containing only 0s, 1s, and 2s)
        in-place using the Dutch National Flag algorithm.

        Idea:
        -----
        - Use three pointers: low, mid, and high.
        - low: boundary for 0s
        - mid: current element being inspected
        - high: boundary for 2s

        Rules:
        -------
        1. nums[mid] == 0 → swap(nums[low], nums[mid]), low++, mid++
        2. nums[mid] == 1 → mid++
        3. nums[mid] == 2 → swap(nums[mid], nums[high]), high--

        Time Complexity:  O(n)
        Space Complexity: O(1)
        In-place: ✅ Yes
    */
    void sortColors(vector<int>& nums) { 
        int low = 0;                  // Start of array
        int mid = 0;                  // Current element
        int high = nums.size() - 1;   // End of array

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
                // ⚠️ DO NOT increment mid here
                // because the swapped element (from high)
                // might be 0 or 1 and needs to be rechecked.
            }
        }
    }
};

// -----------------------------------------------------------
// Main function for demonstration
// -----------------------------------------------------------
int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    Solution sol;
    sol.sortColors(nums);

    cout << "Sorted colors: ";
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;

    // Expected Output: "Sorted colors: 0 0 1 1 2 2"
    return 0;
}




// Brute force approach 
#include <iostream>
#include <vector>
using namespace std;

// -----------------------------------------------------------
// Class: Solution
// Purpose: Sort Colors using counting approach
// -----------------------------------------------------------
class Solution {
public:
    /*
        Function: sortColors
        --------------------
        Sorts the array consisting of 0s, 1s, and 2s.
        Approach: Counting Sort (Two-pass)

        1. Count the number of 0s, 1s, and 2s.
        2. Clear the vector and push elements back in sorted order.

        Time Complexity:  O(n)
        Space Complexity: O(1) (technically O(n) if we count vector reallocation)
    */
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;

        // Count 0s, 1s, and 2s
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) count0++;
            else if (nums[i] == 1) count1++;
            else count2++;
        }

        // Clear the vector to rebuild it
        nums.clear();

        // Push 0s
        for (int i = 0; i < count0; i++) {
            nums.push_back(0);
        }

        // Push 1s
        for (int i = 0; i < count1; i++) {
            nums.push_back(1);
        }

        // Push 2s
        for (int i = 0; i < count2; i++) {
            nums.push_back(2);
        }
    }
};

// -----------------------------------------------------------
// Main function for demonstration
// -----------------------------------------------------------
int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    Solution sol;
    sol.sortColors(nums);

    cout << "Sorted colors: ";
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;

    // Expected Output: "Sorted colors: 0 0 1 1 2 2"
    return 0;
}
