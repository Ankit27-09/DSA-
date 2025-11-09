// Question Link -> https://leetcode.com/problems/next-greater-element-i/description/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

/*
🧠 Problem: Next Greater Element I
---------------------------------
For each element in nums1, find its next greater element in nums2.
If it does not exist, return -1.

Example:
nums1 = [4,1,2]
nums2 = [1,3,4,2]
Output = [-1, 3, -1]
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;                       // will store indices of elements in nums2
        unordered_map<int, int> mpp;         // map to store {element -> next greater element}
        vector<int> ans(nums1.size(), -1);   // result array initialized with -1

        // Step 1️⃣: Process nums2 to find next greater for each element
        for (int i = 0; i < nums2.size(); i++) {
            // while stack not empty AND current element > element at top index
            while (!st.empty() && nums2[st.top()] < nums2[i]) {
                // the next greater for nums2[st.top()] is nums2[i]
                mpp[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            // push current index to stack
            st.push(i);
        }

        // Step 2️⃣: Build answer for nums1 using the map
        for (int i = 0; i < nums1.size(); i++) {
            if (mpp.find(nums1[i]) != mpp.end())
                ans[i] = mpp[nums1[i]];   // if found, use mapped value
            else
                ans[i] = -1;              // otherwise, remains -1
        }

        return ans;
    }
};

/*
📘 Time Complexity:
-------------------
- Processing nums2 → Each element pushed/popped at most once → O(n)
- Building ans → O(m)
Total = O(n + m)

📗 Space Complexity:
--------------------
- Stack → O(n)
- Map (mpp) → O(n)
- Answer vector → O(m)
Total = O(n + m)
*/

int main() {
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> res = sol.nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements: ";
    for (int x : res)
        cout << x << " ";
    cout << endl;

    return 0;
}

/*
🔍 Dry Run Example:
-------------------
nums2 = [1,3,4,2]
Stack process:
i=0 → st=[0]  (1)
i=1 → 3>1 ⇒ mpp[1]=3; pop(0); st=[1]
i=2 → 4>3 ⇒ mpp[3]=4; pop(1); st=[2]
i=3 → 2<4 ⇒ push(3); st=[2,3]

mpp = {1:3, 3:4}

Now nums1 = [4,1,2]
→ 4 → not in mpp → -1
→ 1 → in mpp → 3
→ 2 → not in mpp → -1
Result = [-1, 3, -1]
*/

