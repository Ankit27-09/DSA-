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

class Stack {
    public:
    Node* top;
    int size;   // Actual size of stack

    Stack() {
        top = NULL;
        size = 0;
    }

    //push

    void push(int elem) {
        Node* temp = new Node(elem);
        if(temp == NULL) {
            cout << "Stack Overflow" << endl;
            return;
        }
        else {
            temp -> next = top;
            top = temp;
            size++;
            cout << "Push" << elem << "into the stack" << endl;
        }
        
    }
    //pop

    void pop() {
        if(top == NULL) {
            cout << "Stack Underflow" << endl;
            return;
        }
        else {
            Node* temp = top;
            cout << "Popped" << temp -> data << "from the stack" << endl;
            top = top -> next;
            delete temp;
            size--;
        }
    }
    //peek

    int peek() {
        if(top == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else {
            return top -> data;
        }
    }
    //isEmpty
    bool isEmpty() {
        return top == NULL;                 // Return true if top is NULL
    }

    // isSize
    int isSize() {
        return size;
    }

};

int main() {
    Stack S;
    S.push(4);
    S.push(5);
    S.push(6);
    cout << "Top element is " << S.peek() << endl;
    S.pop();
    cout << "Top element is " << S.peek() << endl;
}