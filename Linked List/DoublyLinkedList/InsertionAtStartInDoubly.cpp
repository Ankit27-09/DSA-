#include <iostream>
using namespace std;

// Node class represents each node of the doubly linked list
class Node {
    public:
        int data;
        Node* next;
        Node* prev;
    
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
            this -> prev = NULL;
        }

};

int main() {
    Node* head = NULL;

    // Insert at start

    // Linked list does not dxist
        if(head == NULL) {
            head = new Node(10);
        }

       
    // ALready Exist karti hai 
    else {
        Node* temp = new Node(10);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }

    Node* trav = head;

    while(trav) {
        cout << trav -> data << " ";
        trav = trav -> next;
    }

}
