#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
   Problem: Merge Overlapping Intervals
   -----------------------------------
   Given an array of intervals where intervals[i] = [start_i, end_i],
   merge all overlapping intervals and return an array of the non-overlapping intervals 
   that cover all the intervals in the input.

   Example:
   Input: [[1,3],[2,6],[8,10],[15,18]]
   Output: [[1,6],[8,10],[15,18]]

   Explanation:
   Intervals [1,3] and [2,6] overlap, so they are merged into [1,6].
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // This will store the merged intervals as the final answer
        vector<vector<int>> ans;

        // Step 1: Sort the intervals based on the starting time
        // Sorting ensures that overlapping intervals appear next to each other
        sort(intervals.begin(), intervals.end());

        // Step 2: Take the first interval as the current interval to compare with others
        vector<int> current = intervals[0];

        // Step 3: Traverse through all intervals
        for (int i = 1; i < intervals.size(); i++) {

            // Case 1: If current interval overlaps with intervals[i]
            // i.e., if the start of the next interval <= end of the current interval
            if (intervals[i][0] <= current[1]) {
                // Merge them by extending the end to the maximum of both ends
                current[1] = max(current[1], intervals[i][1]);
            } 
            // Case 2: If no overlap
            else {
                // Push the current interval to answer
                ans.push_back(current);
                // Move to the next interval
                current = intervals[i];
            }
        }

        // Step 4: Push the last interval after the loop ends
        ans.push_back(current);

        // Step 5: Return the merged intervals
        return ans;
    }
};

// ---------- MAIN FUNCTION ----------
int main() {
    // Fast I/O (optional but good for competitive programming)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example Input
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    // Create object of Solution class
    Solution obj;

    // Call the merge function
    vector<vector<int>> result = obj.merge(intervals);

    // Print the merged intervals
    cout << "Merged Intervals:\n";
    for (auto interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}

/*
   --- DRY RUN EXPLANATION ---

   Input:  [[1,3], [2,6], [8,10], [15,18]]
   After sorting: [[1,3], [2,6], [8,10], [15,18]]

   Step 1: current = [1,3]
   Step 2: Compare with [2,6]
           Since 2 <= 3 → Overlap → merge → current = [1,6]
   Step 3: Compare with [8,10]
           Since 8 > 6 → No overlap → push [1,6] to ans
                         current = [8,10]
   Step 4: Compare with [15,18]
           Since 15 > 10 → No overlap → push [8,10] to ans
                         current = [15,18]
   Step 5: Push last current [15,18] to ans

   Final Answer: [[1,6], [8,10], [15,18]]

   --- TIME AND SPACE COMPLEXITY ---
   Time:  O(N log N) → for sorting
   Space: O(N) → for storing the result
*/
