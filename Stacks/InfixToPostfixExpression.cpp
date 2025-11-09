#include <iostream>
#include <stack>
#include <string>
using namespace std;

class InfixToPostfix {
public:

    // Function to return precedence of operators
    int precedence(char op) {
        switch(op) {
            case '^': return 3; // highest precedence (exponent)
            case '*': 
            case '/': return 2; // multiplication and division
            case '+': 
            case '-': return 1; // addition and subtraction
            default: return -1; // for non-operators
        }
    }

    // Function to check if operator is right associative
    // '^' is right-associative, others are left-associative
    bool isRightAssociative(char op) {
        return (op == '^');
    }

    // Function to check if character is an operator
    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
    }

    // Function to convert infix expression to postfix
    string convert(string infix) {
        stack<char> st;        // stack to store operators
        string postfix = "";   // result string

        for (int i = 0; i < infix.length(); i++) {
            char c = infix[i];

            // 1. If operand (A-Z or a-z or 0-9), add to postfix
            if (isalnum(c)) {
                postfix += c;
            }
            // 2. If '(', push to stack
            else if (c == '(') {
                st.push(c);
            }
            // 3. If ')', pop until '(' is found
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }
                // remove the '(' from stack
                if (!st.empty()) st.pop();
            }
            // 4. If operator
            else if (isOperator(c)) {
                while (!st.empty() && isOperator(st.top())) {
                    char topOp = st.top();

                    // If current operator has lower precedence than top of stack
                    // OR they have same precedence and current operator is left-associative
                    if ((precedence(c) < precedence(topOp)) ||
                        (precedence(c) == precedence(topOp) && !isRightAssociative(c))) {
                        postfix += topOp;
                        st.pop();
                    }
                    else break; // stop if current operator has higher precedence
                }
                st.push(c);
            }
        }

        // 5. Pop all remaining operators from stack
        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }

        return postfix;
    }
};

int main() {
    InfixToPostfix converter;
    string infixExp;

    cout << "Enter an infix expression: ";
    cin >> infixExp;

    string postfixExp = converter.convert(infixExp);

    cout << "Postfix Expression: " << postfixExp << endl;

    return 0;
}
