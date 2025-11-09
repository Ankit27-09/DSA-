#include <iostream>
using namespace std;

class Node {
    public: 
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Queue {
   
    Node *front;
    Node *rear;

     public:
     Queue() {
        front = rear = NULL;
     }

     // Queue is Empty or not

     bool isEmpty() {
        return front == NULL;
     }

     //push element into the queue
     void push(int x) {
        // Empty na ho 
        if(isEmpty()) {
            cout << "Pushed " << x << " into the queue" << endl;
            front = rear = new Node(x);
            return;
        }

        else {
            rear-> next = new Node(x);
            rear = rear -> next;
            cout << "Pushed " << x << " into the queue" << endl;
        }
     }

     void pop() {
        // Empty toh nhi hai 
        if(isEmpty() ){
            cout << "Queue Underflow \n";
            return;

        }
        else {
            cout << "Popped " << front -> data << " from the queue" << endl;
            Node * temp = front;
            front = front -> next;
            delete temp;                                           
        }
     }
     int start() {
        if(isEmpty()) {
            cout << "Queue is Empty \n";
            return -1;
        }
        else {
           return front -> data;
        }
     }

};

int main() {
    Queue q;
    q.push(5);
    q.push(12);
    q.push(89);

    return 0;
}
