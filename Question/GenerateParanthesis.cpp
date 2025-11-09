#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // ✅ Helper function to check if a given parenthesis string is valid
    bool isValid(string current) {
        int count = 0;
        for (char ch : current) {
            if (ch == '(')
                count++;
            else
                count--;

            // ❌ Invalid if closing bracket comes before a matching opening
            if (count < 0)
                return false;
        }

        // ✅ Valid only if every '(' has a matching ')'
        return count == 0;
    }

    // ✅ Recursive function to generate all possible combinations
    void generate(int n, string current, vector<string>& result) {
        // Base case: when string length == 2*n (since n pairs)
        if (current.size() == 2 * n) {
            if (isValid(current)) {
                result.push_back(current);
            }
            return; // return to explore other branches
        }

        // Recursive case:
        generate(n, current + '(', result); // add '('
        generate(n, current + ')', result); // add ')'
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n, "", result);
        return result;
    }
};

int main() {
    Solution obj;
    int n = 3;
    vector<string> ans = obj.generateParenthesis(n);

    cout << "All valid parentheses combinations for n=" << n << ":\n";
    for (string s : ans)
        cout << s << " ";
    cout << endl;

    return 0;
}


// 2. Approach is the better one 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    // Recursive backtracking function to generate valid parentheses
    // Parameters:
    // result - stores all valid sequences found
    // curr   - current sequence being built
    // n      - number of pairs of parentheses
    // open   - number of '(' used so far
    // close  - number of ')' used so far
    void solve(vector<string>& result, string &curr, int n, int open, int close) {
        
        // Base Case: If current sequence length reaches 2*n, we have a complete sequence
        if (curr.length() == 2 * n) {
            result.push_back(curr);  // Add to results
            return;                  // Return to explore other possibilities
        }

        // Option 1: Add '(' if we still have '(' left to use
        // We can only add '(' if open < n
        if (open < n) {
            curr.push_back('(');             // Choose '('
            solve(result, curr, n, open + 1, close); // Recurse with updated open count
            curr.pop_back();                 // Backtrack: undo choice to explore other options
        }

        // Option 2: Add ')' if we have more '(' used than ')' used
        // This ensures the sequence is always valid
        if (close < open) {
            curr.push_back(')');             // Choose ')'
            solve(result, curr, n, open, close + 1); // Recurse with updated close count
            curr.pop_back();                 // Backtrack: undo choice to explore other options
        }
    }

    // Main function to generate all valid parentheses
    vector<string> generateParenthesis(int n) {
        string curr = "";              // Current string sequence
        vector<string> result;         // Vector to store all valid sequences
        int open = 0;                  // Count of '(' used
        int close = 0;                 // Count of ')' used

        // Start recursion
        solve(result, curr, n, open, close);

        return result;                 // Return all valid sequences
    }
};

int main() {
    Solution sol;
    int n = 3;  // Example: generate parentheses for 3 pairs
    vector<string> ans = sol.generateParenthesis(n);

    // Print all valid sequences
    for (string s : ans) {
        cout << s << endl;
    }

    return 0;
}
