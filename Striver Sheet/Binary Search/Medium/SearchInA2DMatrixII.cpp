Question Link -> https://leetcode.com/problems/search-a-2d-matrix-ii/description/

#include <iostream>
#include <vector>
using namespace std;


/*
   Problem:
   You are given an m x n matrix where:
   1️⃣ Each row is sorted in ascending order.
   2️⃣ Each column is sorted in ascending order.

   Your task: Find whether a target value exists in the matrix.

   Example:
   matrix = [
       [1, 4, 7, 11],
       [2, 5, 8, 12],
       [3, 6, 9, 16],
       [10, 13, 14, 17]
   ]
   target = 5
   Output: true
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();          // number of rows
        int column = matrix[0].size();    // number of columns

        // Start from the **top-right corner** of the matrix
        // Because:
        // - elements to the left are smaller
        // - elements below are larger
        int r = 0;            // current row index (start from top)
        int c = column - 1;   // current column index (start from last column)

        // Continue searching as long as we are inside the matrix boundaries
        while (r < row && c >= 0) {
            // Case 1: Found the target
            if (matrix[r][c] == target) {
                return true;
            }
            // Case 2: If target is smaller than the current element
            // move left (because all elements to the right are greater)
            else if (target < matrix[r][c]) {
                c--;
            }
            // Case 3: If target is greater than the current element
            // move down (because all elements above are smaller)
            else {
                r++;
            }
        }

        // If we exit the loop, target is not present in the matrix
        return false;
    }
};

// ---------------------------
// Example usage / Testing
// ---------------------------
int main() {
    Solution obj;

    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target1 = 5;
    int target2 = 20;

    cout << "Searching for " << target1 << ": "
         << (obj.searchMatrix(matrix, target1) ? "Found ✅" : "Not Found ❌") << endl;

    cout << "Searching for " << target2 << ": "
         << (obj.searchMatrix(matrix, target2) ? "Found ✅" : "Not Found ❌") << endl;

    return 0;
}
