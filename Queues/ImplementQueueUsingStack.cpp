#include <iostream>
#include <stack>
using namespace std;

// Queue class using two stacks
class Queue {
    stack<int> stack1;  // Stack used for enqueue operations (push)
    stack<int> stack2;  // Stack used for dequeue operations (pop/peek)

public:

    // Function to check if queue is empty
    bool empty() {
        return stack1.empty() && stack2.empty();
    }

    // Enqueue operation (O(1))
    void push(int x) {
        // Simply push the new element into stack1
        stack1.push(x);
    }

    // Dequeue operation (O(n) in worst case)
    int pop() {
        if (empty()) {
            cout << "Queue is empty!\n";
            return -1;  // Return -1 to indicate underflow
        }

        // If stack2 is empty, we move all elements from stack1 to stack2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        // Now, top of stack2 is the front of the queue
        int element = stack2.top();
        stack2.pop();  // Remove the front element
        return element;
    }

    // Peek operation: returns the front of the queue without removing it
    int peek() {
        if (empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }

        // Similar to pop, we transfer elements if stack2 is empty
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        // Top of stack2 is the front element
        return stack2.top();
    }
};

// Driver code to test the Queue
int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl; // Should be 10
    cout << "Removed: " << q.pop() << endl;        // Should remove 10
    cout << "Front element: " << q.peek() << endl; // Should be 20

    q.push(40);
    cout << "Removed: " << q.pop() << endl;        // Should remove 20
    cout << "Removed: " << q.pop() << endl;        // Should remove 30
    cout << "Removed: " << q.pop() << endl;        // Should remove 40
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
// This code implements a queue using two stacks, allowing for efficient enqueue and dequeue operations.