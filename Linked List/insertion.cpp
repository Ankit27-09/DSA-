#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node (int value) {
        data = value;
    }
};

int main() {
    Node *HEAD;

    int arr[] = {1,2,3,4,5};

// Linked List doesn't Exist
    for( int i = 0; i < 5; i++ ) {
        if(HEAD == NULL) {
        HEAD = new Node(arr[i]);
        }
// Linked List does Exist
        else {
            Node *temp = new Node(arr[i]);
            temp -> next = HEAD;
            HEAD = temp;
        }
    }

// Print the elements inside the linked list
    Node *temp = HEAD;

    while(temp != NULL) {
        cout << temp -> data << endl;
        temp = temp -> next;
    }
    }

// Insert the Node at the beginning



