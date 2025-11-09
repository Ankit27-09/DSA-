// Question link -> https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
🧠 Problem: Next Greater Element
--------------------------------
Given an array 'arr', for each element, find the next greater element to its right.
If no such element exists, return -1 for that position.

Example:
---------
Input: arr = [4, 5, 2, 25]
Output: [5, 25, 25, -1]
Explanation:
- For 4 → next greater element is 5
- For 5 → next greater element is 25
- For 2 → next greater element is 25
- For 25 → there is no greater element to its right, so -1
*/

class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // Create a vector 'ans' to store the results
        // Initialize all values as -1, since default "no greater element" case is -1
        vector<int> ans(arr.size(), -1);

        // Outer loop to traverse each element
        for (int i = 0; i < arr.size(); i++) {
            /*
            For every arr[i], we need to check elements to its right (arr[j]) 
            to find the first one greater than arr[i].
            */
            for (int j = i + 1; j < arr.size(); j++) {
                // If we find a greater element
                if (arr[j] > arr[i]) {
                    ans[i] = arr[j];  // Store that element as the next greater
                    break;            // Stop searching further for this i
                }
            }
        }

        // Return the final result vector
        return ans;
    }
};

/*
📘 Time Complexity Analysis:
-----------------------------
- Outer loop runs 'n' times.
- Inner loop in worst case runs 'n' times (for each element).
⏱ Total = O(n^2)

📗 Space Complexity Analysis:
------------------------------
- 'ans' vector uses O(n) extra space.
🧮 Total = O(n)

✅ Brute-force approach (simple and easy to understand)
❌ Not efficient for large arrays (better approach uses stack → O(n))
*/

// Example usage
int main() {
    Solution sol;
    vector<int> arr = {4, 5, 2, 25};
    vector<int> result = sol.nextLargerElement(arr);

    cout << "Next Greater Elements: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}

/*
🔍 Output:
Next Greater Elements: 5 25 25 -1

📝 Notes for Revision:
-----------------------
- Brute force method → Compare each element with all elements to its right.
- When found, store and break.
- Time complexity = O(n^2)
- Space complexity = O(n) due to result vector.
- For optimized solution → Use Stack (Monotonic Stack) → O(n)
*/

// 2 Optimized Approach Using Stack 
// TIme and Space Complexity:
// Time Complexity: O(n) - Each element is pushed and popped at most once.
// Space Complexity: O(n) - Stack can hold up to n elements in worst case.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
🧠 Problem: Next Greater Element
--------------------------------
Given an array 'arr', for each element, find the next greater element to its right.
If no such element exists, return -1 for that position.

Example:
---------
Input: arr = [4, 5, 2, 25]
Output: [5, 25, 25, -1]
Explanation:
- For 4 → next greater is 5
- For 5 → next greater is 25
- For 2 → next greater is 25
- For 25 → none → -1
*/

/*
⚙️ Optimized Approach: Using Stack (Monotonic Stack)
-----------------------------------------------------
Idea:
- We use a stack to keep track of indices of elements whose next greater element we haven’t found yet.
- As we move from left → right:
    - For each new element, we check if it is greater than the element corresponding to the top index in the stack.
    - If yes, then the new element is the "Next Greater Element" for that index.
    - We pop that index and update its answer.
    - Repeat this until the stack is empty or top element is greater.
- Finally, if any elements remain in the stack, they don't have a next greater → remain -1.

This method ensures every element is pushed and popped at most once ⇒ O(n).
*/

class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();                // size of the input array
        stack<int> st;                     // stack to store indices
        vector<int> ans(n, -1);            // initialize all answers as -1

        // Traverse array from left to right
        for (int i = 0; i < n; i++) {

            /*
            While stack is not empty AND the current element (arr[i])
            is greater than the element represented by index on top of stack.
            */
            while (!st.empty() && arr[st.top()] < arr[i]) {
                // Current element arr[i] is the "Next Greater" for arr[st.top()]
                ans[st.top()] = arr[i];

                // Pop that index as we have found its next greater element
                st.pop();
            }

            // Push the current index onto stack
            // (We haven’t yet found its next greater)
            st.push(i);
        }

        // Any indices left in stack don’t have any next greater → remain -1
        return ans;
    }
};

/*
📘 Time Complexity Analysis:
-----------------------------
Each element is pushed and popped at most once.
=> O(n) time

📗 Space Complexity Analysis:
------------------------------
- Stack may hold up to 'n' elements in worst case.
=> O(n) extra space (for stack + ans vector)
*/

/*
🔍 Example Dry Run:
--------------------
Input: arr = [4, 5, 2, 25]

Step-by-step:
i = 0 → arr[0]=4
Stack empty → push(0) → st = [0]

i = 1 → arr[1]=5
arr[st.top()] = arr[0]=4 < 5 ⇒ ans[0] = 5, pop(0)
Now stack empty → push(1) → st = [1]

i = 2 → arr[2]=2
arr[1]=5 > 2 ⇒ no pop → push(2) → st = [1,2]

i = 3 → arr[3]=25
arr[2]=2 < 25 ⇒ ans[2]=25 → pop(2)
arr[1]=5 < 25 ⇒ ans[1]=25 → pop(1)
stack empty → push(3) → st = [3]

End of loop → ans = [5, 25, 25, -1]
*/

int main() {
    Solution sol;
    vector<int> arr = {4, 5, 2, 25};
    vector<int> result = sol.nextLargerElement(arr);

    cout << "Next Greater Elements: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}

/*
✅ Output:
Next Greater Elements: 5 25 25 -1

📝 Key Revision Notes:
-----------------------
- Use stack to track indices of unresolved elements.
- Pop when current element is greater → update result.
- Each element is pushed/popped at most once → O(n).
- This is the efficient “Monotonic Stack” solution pattern.
*/
