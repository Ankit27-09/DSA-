#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function to generate all binary strings of length n
    void generate(int n, string curr, vector<string>& result) {

        // 🧩 BASE CASE:
        // When the current string has reached length n, store it in result
        if (curr.length() == n) {
            result.push_back(curr);  // store the valid binary string
            return;                  // return to explore other possibilities
        }

        // 🧠 RECURSIVE CASE:

        // LEFT BRANCH ➜ Add '0' to current string
        // Example: if curr = "1" → left branch becomes "10"
        generate(n, curr + '0', result);

        // RIGHT BRANCH ➜ Add '1' to current string
        // Example: if curr = "1" → right branch becomes "11"
        generate(n, curr + '1', result);
    }

    // Main function to be called with only 'n'
    vector<string> binstr(int n) {
        vector<string> result;    // stores all possible binary strings
        generate(n, "", result);  // start recursion with empty string
        return result;
    }
};

int main() {
    Solution obj;
    int n = 3;  // Example: generate all binary strings of length 3

    vector<string> ans = obj.binstr(n);

    cout << "All binary strings of length " << n << " are:\n";
    for (string s : ans) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
