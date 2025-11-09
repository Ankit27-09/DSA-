#include <bits/stdc++.h>
using namespace std;

/*
🔹 Problem: Next Greater Element II
Given a circular array `nums`, for each element, you need to find the next greater element.
If it doesn't exist, return -1 for that position.

Example:
Input:  [1, 2, 1]
Output: [2, -1, 2]
Explanation:
  - For 1, the next greater is 2
  - For 2, there is no greater element, so -1
  - For last 1, we wrap around circularly — next greater is again 2
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;              // Stack to store indices of elements (not values)
        vector<int> ans(n, -1);     // Initialize answer array with -1 (default for "no greater element")

        /*
         🔹 Idea:
         Since the array is circular, we traverse the array twice (2*n - 1 iterations).
         We use modulo operator (%) to wrap around indices circularly.

         🔹 Why traverse twice?
         Because for elements near the end, their "next greater" might appear at the beginning
         (due to circular nature).
        */
        for (int i = 0; i < 2 * n - 1; i++) {

            // Current element (use modulo for circular behavior)
            int curr = nums[i % n];

            /*
             🔹 While stack is not empty AND the current element is greater than
             the element represented by index on top of the stack:
               → we found the "next greater element" for that index.
            */
            while (!st.empty() && nums[st.top()] < curr) {
                ans[st.top()] = curr; // Update answer for that index
                st.pop();              // Remove that index since we’ve found its next greater element
            }

            /*
             🔹 Push the current index (mod n ensures valid index within [0, n-1]).
             Note: We push every index in the first traversal (n elements).
             In the second traversal, we don’t push again since all possible next
             greater elements would already be discovered.
            */
            st.push(i % n);
        }

        return ans;
    }
};

// 🔹 Driver code for testing
int main() {
    Solution sol;

    // Example 1
    vector<int> nums = {1, 2, 1};
    vector<int> result = sol.nextGreaterElements(nums);

    cout << "Next Greater Elements: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    /*
     Output:
     Next Greater Elements: 2 -1 2
    */

    return 0;
}

/*
==================== 🔁 DRY RUN EXAMPLE ====================

Input: nums = [1, 2, 1]
We iterate i = 0 to 2*n - 2 = 4 (since 2*n - 1 = 5 iterations total)

i=0 → curr = nums[0] = 1
  stack = []
  push(0)
  stack = [0]

i=1 → curr = nums[1] = 2
  nums[st.top()] = nums[0] = 1 < 2 → ans[0] = 2
  pop() → stack = []
  push(1)
  stack = [1]

i=2 → curr = nums[2 % 3] = nums[2] = 1
  nums[1] = 2 > 1 → no pop
  push(2)
  stack = [1, 2]

i=3 → curr = nums[3 % 3] = nums[0] = 1
  nums[2] = 1 < 1 → no (equal, not strictly greater)
  push(0)
  stack = [1, 2, 0]

i=4 → curr = nums[4 % 3] = nums[1] = 2
  nums[st.top()] = nums[0] = 1 < 2 → ans[0] = 2, pop()
  nums[st.top()] = nums[2] = 1 < 2 → ans[2] = 2, pop()
  stack = [1]
  push(1)
  stack = [1, 1] (not harmful since 2nd traversal)

Final ans = [2, -1, 2]
============================================================
*/
