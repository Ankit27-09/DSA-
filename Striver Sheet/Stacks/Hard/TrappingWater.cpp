// Question Link: https://leetcode.com/problems/trapping-rain-water/

#include <iostream>
#include <vector>
using namespace std;
#include <stack>

/*
    Problem: Trapping Rain Water (LeetCode #42)
    -------------------------------------------
    Given an array 'height', compute how much water
    can be trapped after it rains.

    Approach:
    =========
    Use a stack to keep track of indices of the bars.

    - Traverse the array:
        - While the current height is greater than the height at the top of the stack:
            - Pop the top element (this is the bottom of a water trap).
            - If the stack becomes empty, break (no left boundary).
            - Otherwise:
                * Calculate the distance between the current index and the new top of stack.
                * Find the bounded height using min(left, right) - bottom.
                * Add the trapped water for this section.
        - Push the current index to the stack.

    Complexity:
    -----------
    Time:  O(n)
    Space: O(n)
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;   // stack stores indices of bars
        int water = 0;   // total trapped water

        for (int i = 0; i < n; i++) {
            // While current bar is taller than the top of stack
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();  // this is the bottom of the water pit
                st.pop();

                // If the stack becomes empty, no left boundary exists
                if (st.empty()) break;

                // Now st.top() is the index of the left boundary
                int left = st.top();
                int right = i;

                // Distance between left and right boundary minus one
                int width = right - left - 1;

                // Height of water trapped is determined by the smaller of the two boundaries
                int boundedHeight = min(height[left], height[right]) - height[top];

                // Add trapped water for this section
                water += width * boundedHeight;
            }

            // Push current bar index onto the stack
            st.push(i);
        }

        return water;
    }
};

// ----------------------------------------------------
// Example usage
// ----------------------------------------------------
int main() {
    Solution sol;
    vector<int> height = {4, 2, 0, 3, 2, 5};
    cout << "Total trapped water: " << sol.trap(height) << endl;
    return 0;
}

/*
-------------------------------------
Dry Run: height = [4,2,0,3,2,5]
-------------------------------------
Step 1: push(0) → stack = [0]
Step 2: push(1) → stack = [0,1]
Step 3: push(2) → stack = [0,1,2]
Step 4: height[3]=3 > height[2]=0 → pop(2)
        left = 1, right = 3
        width = 1, boundedHeight = min(2,3) - 0 = 2
        water += 2*1 = 2
        Now height[3]=3 > height[1]=2 → pop(1)
        left = 0, right = 3
        width = 2, boundedHeight = min(4,3) - 2 = 1
        water += 2*1 = 2
        total = 4
Step 5: push(3) → stack = [0,3]
Step 6: push(4) → stack = [0,3,4]
Step 7: height[5]=5 > height[4]=2 → pop(4)
        left = 3, right = 5
        width = 1, boundedHeight = min(3,5) - 2 = 1
        water += 1
        height[5]=5 > height[3]=3 → pop(3)
        left = 0, right = 5
        width = 4, boundedHeight = min(4,5) - 3 = 1
        water += 4
        total water = 4+1+4 = 9
-------------------------------------
OUTPUT:
Total trapped water: 9
-------------------------------------
*/
