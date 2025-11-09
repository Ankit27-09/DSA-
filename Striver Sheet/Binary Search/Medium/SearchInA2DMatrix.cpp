// Question Link -> https://leetcode.com/problems/search-a-2d-matrix/description/

#include <iostream>
#include <vector>
using namespace std;

/*
   Problem:
   You are given an m x n matrix where each row is sorted in ascending order,
   and the first element of each row is greater than the last element of the previous row.
   Your task: check if a target value exists in this matrix.

   Example:
   matrix = [
     [1, 3, 5, 7],
     [10, 11, 16, 20],
     [23, 30, 34, 60]
   ]
   target = 3
   Output: true
*/

class Solution {
public:

    // Helper function: perform binary search within a specific row
    bool searchSpecific(vector<vector<int>>& matrix, int target, int row) {
        int n = matrix[0].size();  // total number of columns in a row
        int start = 0;
        int end = n - 1;

        // Standard binary search on a 1D sorted array
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (matrix[row][mid] == target) {
                return true;  // found target
            }
            else if (target > matrix[row][mid]) {
                start = mid + 1;  // move right (search in larger half)
            }
            else {
                end = mid - 1;    // move left (search in smaller half)
            }
        }

        // Target not found in this row
        return false;
    }

    // Main function: search the matrix for the target
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();       // total number of rows
        int column = matrix[0].size(); // total number of columns

        int rowStart = 0;
        int rowEnd = row - 1;

        // First, use binary search on the "rows" to find the correct row
        while (rowStart <= rowEnd) {
            int mid = rowStart + (rowEnd - rowStart) / 2;

            // Check if target lies in the range of the current middle row
            if (target >= matrix[mid][0] && target <= matrix[mid][column - 1]) {
                // If yes, perform binary search within this row
                return searchSpecific(matrix, target, mid);
            }
            else if (target > matrix[mid][column - 1]) {
                // If target is greater than the last element of this row,
                // it must be in a row below (increase rowStart)
                rowStart = mid + 1;
            }
            else {
                // If target is smaller than the first element of this row,
                // it must be in a row above (decrease rowEnd)
                rowEnd = mid - 1;
            }
        }

        // If no row fits the condition, target doesn't exist
        return false;
    }
};

// ---------------------------
// Example usage / Testing
// ---------------------------
int main() {
    Solution obj;

    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target1 = 3;
    int target2 = 13;

    cout << "Searching for " << target1 << ": "
         << (obj.searchMatrix(matrix, target1) ? "Found ✅" : "Not Found ❌") << endl;

    cout << "Searching for " << target2 << ": "
         << (obj.searchMatrix(matrix, target2) ? "Found ✅" : "Not Found ❌") << endl;

    return 0;
}
