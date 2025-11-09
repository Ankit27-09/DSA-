// 1. Reverse the Infix
// 2. Infix to Postfix
// 3. Reverse that answer

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // STEP 1: Define operator precedence
    // Higher number = higher precedence
    int precedence(char ch) {
        switch(ch) {
            case '^': return 3;  // Exponent operator has highest precedence
            case '*': return 2;  // Multiplication
            case '/': return 2;  // Division (same as multiplication)
            case '+': return 1;  // Addition
            case '-': return 1;  // Subtraction (same as addition)
            default: return 0;   // For non-operators
        }
    }

    // STEP 2: Function to check if a character is an operand (a, b, c, 1, 2, etc.)
    bool isOperand(char c) {
        return (isalnum(c)); // alphanumeric (letters + digits)
    }

    // STEP 3: Convert Infix expression to Prefix
    string infixToPrefix(string s) {
        // ---- STEP 3.1: Reverse the infix expression ----
        reverse(s.begin(), s.end());

        // ---- STEP 3.2: Swap '(' with ')' and vice-versa ----
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                s[i] = ')';
            }
            else if (s[i] == ')') {
                s[i] = '(';
            }
        }

        // ---- STEP 3.3: Convert modified infix to postfix ----
        string result = "";
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            // Case 1: If character is an operand -> directly add to result
            if (isOperand(c)) {
                result += c;
            }
            // Case 2: If '(' -> push to stack
            else if (c == '(') {
                st.push(c);
            }
            // Case 3: If ')' -> pop until '(' is found
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // remove '('
            }
            // Case 4: If operator (+, -, *, /, ^)
            else {
                // Special rule for '^' (Right associative)
                if (c == '^') {
                    while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                        result += st.top();
                        st.pop();
                    }
                }
                // For all other operators (Left associative)
                else {
                    while (!st.empty() && precedence(st.top()) > precedence(c)) {
                        result += st.top();
                        st.pop();
                    }
                }
                st.push(c); // push current operator
            }
        }

        // ---- STEP 3.4: Pop any remaining operators from stack ----
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        // ---- STEP 3.5: Reverse the result to get prefix expression ----
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution obj;

    string infix = "((A-B)/((D+E)*F))";  
    // Example: Infix -> Prefix

    cout << "Infix Expression: " << infix << endl;
    cout << "Prefix Expression: " << obj.infixToPrefix(infix) << endl;

    return 0;
}
