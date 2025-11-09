// Question Link -> https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

/*
    Problem: The Celebrity Problem

    There are N people in a party (0 to N-1). 
    A "celebrity" is a person who is:
        - Known by everyone else.
        - Knows no one in return.

    The input is given as an NxN matrix `mat` where:
        mat[i][j] = 1 → person i knows person j
        mat[i][j] = 0 → person i does not know person j

    Task: Find the celebrity's index if one exists, otherwise return -1.
*/

#include <iostream>
using namespace std;
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size(); // total number of people

        // 🧱 Step 1: Push all people (0 to n-1) into a stack
        stack<int> st;
        for (int i = 0; i < n; i++) {
            st.push(i);
        }

        // 🧩 Step 2: Eliminate non-celebrities using pairwise comparison
        // Compare top two people and eliminate one who cannot be a celebrity
        while (st.size() > 1) {
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();

            // If first knows second -> first cannot be celebrity
            // Push second back
            if (mat[first][second] == 1 && mat[second][first] == 0) {
                st.push(second);
            }
            // If first doesn't know second -> second cannot be celebrity
            // Push first back
            else if (mat[first][second] == 0 && mat[second][first] == 1) {
                st.push(first);
            }
            // If both know each other OR both don't know each other -> both can't be celebrity
            // (we simply skip pushing any)
        }

        // ⚠️ Step 3: If stack becomes empty, no celebrity exists
        if (st.empty()) {
            return -1;
        }

        // The remaining person might be a celebrity candidate
        int num = st.top();
        st.pop();

        int rowSum = 0; // how many people 'num' knows
        int colSum = 0; // how many people know 'num'

        // 🔍 Step 4: Verify the celebrity condition
        for (int i = 0; i < n; i++) {
            rowSum += mat[num][i]; // sum of row (who num knows)
            colSum += mat[i][num]; // sum of column (who knows num)
        }

        /*
            ✅ Step 5: Check conditions for being a celebrity:
                - rowSum == 0 → num should know nobody
                - colSum == n-1 → everyone else should know num
        */

        if (rowSum == 0 && colSum == n - 1) {
            return num; // celebrity found
        }
        return -1; // no celebrity
    }
};

int main() {
    Solution obj;

    // 🧪 Example Test Case
    vector<vector<int>> mat = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int ans = obj.celebrity(mat);

    if (ans == -1)
        cout << "No Celebrity Found\n";
    else
        cout << "Celebrity ID: " << ans << "\n";

    return 0;
}
