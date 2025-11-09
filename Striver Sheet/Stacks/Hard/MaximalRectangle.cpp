
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
    Problem: Maximal Rectangle (LeetCode 85)
    ----------------------------------------
    Given a binary matrix filled with 0's and 1's, 
    find the largest rectangle containing only 1's 
    and return its area.

    Approach:
    =========
    1️⃣ Treat each row of the matrix as the base of a histogram.
    2️⃣ For each cell:
        - If it's '1', add 1 to the column height.
        - If it's '0', reset the column height to 0.
    3️⃣ For every updated row, calculate the largest rectangle area 
        in the histogram using the "Largest Rectangle in Histogram" method.
    4️⃣ Keep track of the maximum area found.
*/

// ----------------------------------------------------
// Helper Function: largestRectangleArea()
// Finds the largest rectangle in a histogram.
// ----------------------------------------------------
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) { 
        int n = heights.size();
        int ans = 0;           // stores the maximum rectangle area
        stack<int> st;         // stack to store indices of bars

        // Traverse through all bars of histogram
        for (int i = 0; i < n; i++) {
            // If the current bar is smaller than the top of the stack
            // It means the rectangle with the height of st.top() has ended
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int index = st.top();   // store top index
                st.pop();               // pop the top

                // If stack is not empty, calculate width as (i - st.top() - 1)
                // Else width is i (since all bars before were larger)
                int width = st.empty() ? i : (i - st.top() - 1);

                // Calculate area using height * width
                ans = max(ans, heights[index] * width);
            }
            st.push(i); // Push current bar's index to stack
        }

        // After full traversal, some bars may remain in stack
        // Pop them and calculate area for remaining heights
        while (!st.empty()) {
            int index = st.top();
            st.pop();
            int width = st.empty() ? n : (n - st.top() - 1);
            ans = max(ans, heights[index] * width);
        }

        return ans;
    }

    // ----------------------------------------------------
    // Main Function: maximalRectangle()
    // Uses the largestRectangleArea() to compute maximal rectangle
    // ----------------------------------------------------
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int row = matrix.size();
        int column = matrix[0].size();
        int ans = 0;

        // Vector to store the "height" of histogram at each column
        vector<int> heights(column, 0);

        // Traverse each row of the matrix
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                // If the current cell is '1', add 1 to the height
                // else reset height to 0
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                } else {
                    heights[j] += 1;
                }
            }

            // For the updated histogram (current row as base),
            // find the largest rectangle area
            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};

// ----------------------------------------------------
// Example Usage
// ----------------------------------------------------
int main() {
    Solution sol;

    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    cout << "Maximal Rectangle Area: " << sol.maximalRectangle(matrix) << endl;
    return 0;
}

/*
-----------------------------------------------
OUTPUT:
Maximal Rectangle Area: 6
-----------------------------------------------

Explanation:
The largest rectangle containing only 1’s is:
[
  ['1','0','1','0','0'],
  ['1','0','1','1','1'],
  ['1','1','1','1','1'],
  ['1','0','0','1','0']
]
It forms a 3x2 rectangle (area = 6)
-----------------------------------------------
*/
