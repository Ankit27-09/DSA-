// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to convert Postfix expression to Prefix
    string postToPre(string post_exp) {
        stack<string> st;

        // Traverse the postfix expression
        for (char c : post_exp) {
            // If operand → push as string
            if (isalnum(c)) {
                st.push(string(1, c)); // convert char to string
            }
            // If operator → pop two operands and form new prefix
            else {
                string op1 = st.top(); st.pop(); // first operand (top)
                string op2 = st.top(); st.pop(); // second operand

                // Form new prefix string: operator + op2 + op1
                string exp = string(1, c) + op2 + op1;

                st.push(exp); // push back to stack
            }
        }

        // Final element of stack is the Prefix expression
        return st.top();
    }
};

// ---------- Driver Code ----------
int main() {
    Solution sol;

    string postfix = "AB+C*";  
    // Example: Postfix = "AB+C*"
    // Expected Prefix = "*+ABC"

    cout << "Postfix Expression: " << postfix << endl;
    cout << "Prefix Expression: " << sol.postToPre(postfix) << endl;

    return 0;
}
