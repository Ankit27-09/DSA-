#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to convert Prefix → Postfix
    string preToPost(string s) {
        stack<string> st;

        // Traverse prefix expression from RIGHT to LEFT
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];

            // If operand → push to stack
            if (isalnum(c)) {
                st.push(string(1, c)); // convert char to string
            }
            // If operator → pop two operands, combine into postfix
            else {
                string op1 = st.top(); st.pop(); // first operand
                string op2 = st.top(); st.pop(); // second operand

                // Postfix = op1 + op2 + operator
                string exp = op1 + op2 + c;
                st.push(exp); // push new subexpression
            }
        }

        // Final element in stack is complete postfix expression
        return st.top();
    }
};

// ---------- Driver Code ----------
int main() {
    Solution sol;

    string prefix = "*+ABC";  
    // Example: Prefix = "*+ABC"
    // Expected Postfix = "AB+C*"

    cout << "Prefix Expression: " << prefix << endl;
    cout << "Postfix Expression: " << sol.preToPost(prefix) << endl;

    return 0;
}
