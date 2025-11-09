// Question Link -> https://leetcode.com/problems/largest-rectangle-in-histogram/

// First Appproach Having time and space complexity is O(N)

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> NSR(n); // NSR[i] → index of Nearest Smaller to Right
        vector<int> NSL(n); // NSL[i] → index of Nearest Smaller to Left
        stack<int> st;

        //---------------------------------------
        // STEP 1: Find NSR (Nearest Smaller to Right)
        //---------------------------------------
        // For each bar, we find the next index on the right side
        // where the height is smaller than the current bar.
        // If no smaller bar on the right, we take n (array size).

        for (int i = n - 1; i >= 0; i--) {
            // Pop until we find a smaller height
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // If stack is empty, no smaller bar to the right → use n
            if (st.empty()) NSR[i] = n;
            else NSR[i] = st.top(); // index of smaller bar to right

            // Push current index for future comparisons
            st.push(i);
        }

        // Clear the stack for next computation
        while (!st.empty()) st.pop();

        //---------------------------------------
        // STEP 2: Find NSL (Nearest Smaller to Left)
        //---------------------------------------
        // For each bar, we find the next index on the left side
        // where the height is smaller than the current bar.
        // If no smaller bar on the left, we take -1.

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // If stack is empty, no smaller bar to left → use -1
            if (st.empty()) NSL[i] = -1;
            else NSL[i] = st.top(); // index of smaller bar to left

            st.push(i);
        }

        //---------------------------------------
        // STEP 3: Compute maximum rectangular area
        //---------------------------------------
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            // Width of rectangle = NSR[i] - NSL[i] - 1
            int width = NSR[i] - NSL[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

//---------------------------------------
// Example usage / testing
//---------------------------------------
int main() {
    Solution sol;

    // Example histogram heights
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << "Input: [2, 1, 5, 6, 2, 3]" << endl;
    cout << "Largest Rectangle Area = " << sol.largestRectangleArea(heights) << endl;
    // Expected Output: 10 (formed by heights[2]=5 and heights[3]=6 -> width=2, height=5)

    return 0;
}


// Optimised Approach Having time complexity O(N) and space complexity O(n)
#include <iostream>
#include <vector>
using namespace std;

/*
    🧠 Problem: Largest Rectangle in Histogram
    ------------------------------------------
    Given an array 'heights' representing the heights of bars in a histogram,
    we need to find the largest rectangular area that can be formed between
    consecutive bars.

    Example:
        Input:  heights = [2, 1, 5, 6, 2, 3]
        Output: 10
        Explanation: The largest rectangle has height = 5 and width = 2 (between bars 5 and 6),
                     so area = 5 * 2 = 10.
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) { 
        int ans = 0;             // Stores the maximum area found so far
        int index;               // Temporary variable to hold popped index
        stack<int> st;           // Monotonic increasing stack (stores indices)
        int n = heights.size();  // Total number of bars

        /*
            ✅ Step 1: Traverse all bars from left to right
            ------------------------------------------------
            We'll use a stack to store indices of bars in increasing order of height.
            Whenever we find a smaller bar than the top of stack, we start popping
            and calculating area for the popped bars.
        */
        for (int i = 0; i < n; i++) {

            // While the current bar is smaller than the bar at stack top
            // → it means the bar at stack top can no longer extend further to the right.
            while (!st.empty() && heights[st.top()] > heights[i]) {
                index = st.top();   // Store the index of the bar being popped
                st.pop();           // Remove it from the stack

                /*
                    When we pop, we calculate the area with heights[index]
                    as the smallest bar height in the rectangle.

                    - If stack is not empty:
                        Left boundary = st.top()
                        Right boundary = i - 1
                        So width = (i - st.top() - 1)

                    - If stack is empty:
                        That means current bar is the smallest so far,
                        and this rectangle extends from 0 to (i - 1)
                        → width = i
                */
                if (!st.empty()) {
                    ans = max(ans, heights[index] * (i - st.top() - 1));
                } else {
                    ans = max(ans, heights[index] * i);
                }
            }

            // After popping all taller bars, push current bar index
            st.push(i);
        }

        /*
            ✅ Step 2: Process remaining bars in the stack
            -----------------------------------------------
            After we reach the end, some bars may still remain in the stack.
            For these bars, the right boundary is the end of the histogram (n - 1).
        */
        while (!st.empty()) {
            index = st.top();
            st.pop();

            /*
                If stack is not empty:
                    Width = (n - st.top() - 1)
                Else:
                    Width = n  → whole histogram
            */
            if (!st.empty()) {
                ans = max(ans, heights[index] * (n - st.top() - 1));
            } else {
                ans = max(ans, heights[index] * n);
            }
        }

        // ✅ Step 3: Return the maximum area found
        return ans;
    }
};

/*
    🧩 Dry Run Example
    ------------------
    Input: heights = [2, 1, 5, 6, 2, 3]

    Iteration by iteration:
    i=0: st = [0]               (2)
    i=1: heights[0] > 1 → pop 0 → area = 2 * 1 = 2
          st = [1]
    i=2: st = [1,2]             (1,5)
    i=3: st = [1,2,3]           (1,5,6)
    i=4: heights[3] > 2 → pop 3 → area = 6 * 1 = 6
          heights[2] > 2 → pop 2 → area = 5 * (4 - 1 - 1) = 10 ✅
          st = [1,4]
    i=5: st = [1,4,5]           (1,2,3)
    End: pop remaining
          pop 5 → area = 3 * 1 = 3
          pop 4 → area = 2 * (6 - 1 - 1) = 8
          pop 1 → area = 1 * 6 = 6
    ✅ Final Answer = 10
*/

/*
    ⏱️ Time Complexity:
    -------------------
    O(n)
    - Each bar is pushed and popped from the stack at most once.

    💾 Space Complexity:
    --------------------
    O(n)
    - Stack can hold up to 'n' indices in the worst case.
*/

/*
    🧠 Key Idea:
    ------------
    The stack-based approach ensures we efficiently find
    the *next smaller element to left and right* for each bar implicitly,
    without needing separate arrays.

    The algorithm is linear, elegant, and widely used for
    histogram, matrix maximal rectangles, etc.
*/

int main() {
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area: " << sol.largestRectangleArea(heights) << endl;
    return 0;
}
