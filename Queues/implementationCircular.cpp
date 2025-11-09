#include <iostream>
using namespace std;

//  Implementation Of Queue using array

class Queue {
    int front, rear;
    int size;
    int *arr; 

    public:
    Queue(int n) {   
        arr = new int[n];
        size = n;
        front = rear = -1;
    }

    // If queue is Empty or not...
    bool isEmpty() {
        return front == -1;
    }

    // If queue is full or not
    bool isFull() {
        return (rear + 1) % size == front;
    }

    // Push Element into the queue
    void push(int x) {
        // Empty
        if (isEmpty()) {
            cout << "Pushed " << x << " into the Queue" << endl;
            front = rear = 0;
            arr[0] = x;
            return;
        }
        // Full
        else if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        // Insert
        else {
            rear = (rear + 1) % size;
            arr[rear] = x;
            cout << "Pushed " << x << " into the Queue" << endl;
        }
    }

    // Pop Element from the queue
    void pop() {
        // Empty
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        // Pop the element
        else {
            cout << "Popped " << arr[front] << " from the Queue" << endl;
            if (front == rear) {
                front = rear = -1; // Reset after popping the last element
            } else {
                front = (front + 1) % size;
            }
        }
    }

    // Return the front element
    int start() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        } else {
            return arr[front];
        }
    }
};

int main() {
    Queue q(5);
    q.push(4);
    q.push(15);
    q.push(52);
    q.push(11);
    q.pop();
    q.pop();
    q.push(11);

    q.pop();
    

    cout << "Front element is: " << q.start() << endl;

    return 0;
}
