#include <iostream>
#include <queue>
using namespace std;

// Stack class using two queues
class Stack {
    queue<int> q1;  // Primary queue
    queue<int> q2;  // Helper queue

public:

    // Check if the stack is empty
    bool empty() {
        return q1.empty() && q2.empty();
    }

    // Push operation (O(1) time)
    void push(int x) {
        // Always push into the non-empty queue (or q1 if both are empty)
        if (!q1.empty()) {
            q1.push(x);
        } else {
            q2.push(x);
        }
    }

    // Pop operation (O(n) time)
    void pop() {
        if (empty()) {
            cout << "Stack Underflow\n";
            return;
        }

        // Identify the non-empty queue and transfer all elements except last
        if (!q1.empty()) {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop(); // Remove the last (top) element
        } else {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            q2.pop(); // Remove the last (top) element
        }
    }

    // Peek operation (O(n) time)
    void peek() {
        if (empty()) {
            cout << "Stack is empty\n";
            return;
        }

        int topElement;

        // Identify the non-empty queue and move all except last
        if (!q1.empty()) {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            topElement = q1.front();  // Last element is the top of the stack
            q1.pop();
            q2.push(topElement);     // Put it back to maintain order
        } else {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            topElement = q2.front();
            q2.pop();
            q1.push(topElement);
        }

        cout << "Top element is: " << topElement << endl;
    }
};

// Driver code to test the Stack class
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.peek();        // Should print 30
    s.pop();         // Removes 30
    s.peek();        // Should print 20
    s.pop();         // Removes 20
    s.peek();        // Should print 10
    s.pop();         // Removes 10
    s.peek();        // Should print "Stack is empty"
    s.pop();         // Should print "Stack Underflow"

    return 0;
}
