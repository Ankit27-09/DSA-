// User function Template for C++
#include <iostream>
#include <stack>
using namespace std;

class Solution {
  public:
    // Function to convert Prefix expression to Infix expression
    string preToInfix(string s) {
        // Stack to hold operands/sub-expressions as strings
        stack<string> st;

        // STEP 1: Traverse the prefix expression from RIGHT to LEFT
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];

            // STEP 2: If the character is an operand (letter or digit)
            if (isalnum(c)) {
                // Convert char → string and push
                // string(1, c) creates a string with single character
                st.push(string(1, c));
            }
            else {
                // STEP 3: If the character is an operator (+, -, *, /, ^, etc.)
                // Pop two operands from the stack
                string op1 = st.top(); st.pop();  // first operand
                string op2 = st.top(); st.pop();  // second operand

                // STEP 4: Build new string = (operand1 operator operand2)
                // Add parentheses to maintain correct precedence
                string exp = "(" + op1 + c + op2 + ")";

                // STEP 5: Push the new expression back into stack
                st.push(exp);
            }
        }

        // STEP 6: At the end, stack contains one complete infix expression
        return st.top();
    }
};

// ---------- Driver Code for Testing ----------
int main() {
    Solution sol;
    string prefix = "*-A/BC-/AKL"; 
    // Example prefix: *-A/BC-/AKL
    // Expected infix: ((A-(B/C))*((A/K)-L))

    cout << "Prefix Expression: " << prefix << endl;
    cout << "Infix Expression: " << sol.preToInfix(prefix) << endl;

    return 0;
}
