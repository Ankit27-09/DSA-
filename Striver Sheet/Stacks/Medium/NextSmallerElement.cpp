// Question link -> https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1

#include <iostream>
#include <vector>   
#include <stack>
using namespace std;

/*
🧠 Problem: Next Smaller Element to the Right
---------------------------------------------
For each element, find the next smaller element on its right.
If none exists, return -1.

Example:
Input:  arr = [4, 8, 5, 2, 25]
Output: [2, 5, 2, -1, -1]
*/

class Solution {
public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;               // stack to store indices
        vector<int> ans(n, -1);      // initialize answer with -1

        for (int i = 0; i < n; i++) {
            /*
            While stack not empty AND
            current element is smaller than element represented by top of stack,
            we found the "next smaller element" for that index.
            */
            while (!st.empty() && arr[st.top()] > arr[i]) {
                ans[st.top()] = arr[i];   // arr[i] is the next smaller for arr[st.top()]
                st.pop();                 // pop since we found its answer
            }

            // push current index to stack
            st.push(i);
        }

        // Remaining elements in stack → no smaller element to the right (remain -1)
        return ans;
    }
};

/*
📘 Time Complexity:
-------------------
Each element is pushed and popped at most once → O(n)

📗 Space Complexity:
--------------------
Stack and answer vector → O(n)
*/

int main() {
    Solution sol;
    vector<int> arr = {4, 8, 5, 2, 25};
    vector<int> result = sol.nextSmallerEle(arr);

    cout << "Next Smaller Elements: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}

/*
🔍 Dry Run Example:
-------------------
arr = [4, 8, 5, 2, 25]

i=0 → push(0) → st=[0]
i=1 → 8>4 → no → push(1) → st=[0,1]
i=2 → 5<8 ⇒ ans[1]=5, pop(1)
         → 5>4 ⇒ no → push(2) → st=[0,2]
i=3 → 2<5 ⇒ ans[2]=2, pop(2)
         → 2<4 ⇒ ans[0]=2, pop(0)
         → push(3) → st=[3]
i=4 → 25>2 → no → push(4) → st=[3,4]

Remaining → ans[3]=-1, ans[4]=-1

Final ans = [2, 5, 2, -1, -1]
*/

/*
📝 Revision Notes:
------------------
- Pattern → "Monotonic Increasing Stack"
- Pop when arr[i] < arr[st.top()]
- Update ans[st.top()] = arr[i]
- Each element processed once → O(n)
- Similar logic works for Next Greater (just reverse comparison)
*/
