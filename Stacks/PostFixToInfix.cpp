// User function Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string postToInfix(string s) {
        stack<string> st; // stack will store strings (not chars!)

        // Traverse the postfix expression
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            // Case 1: If operand (letter or digit) -> push as string
            if (isalnum(c)) {
                st.push(string(1, c)); // convert char to string
            }
            // Case 2: If operator -> pop two operands, build infix expression
            else {
                // Pop operand1 and operand2 from stack
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();

                // Form a new expression: (op2 operator op1)
                string exp = "(" + op2 + c + op1 + ")";

                // Push back the new expression
                st.push(exp);
            }
        }

        // Final element in stack is the infix expression
        return st.top();
    }
};

int main() {
    Solution obj;

    string postfix = "AB-DE+F*/";  
    // Example: Postfix -> Infix

    cout << "Postfix Expression: " << postfix << endl;
    cout << "Infix Expression: " << obj.postToInfix(postfix) << endl;

    return 0;
}
