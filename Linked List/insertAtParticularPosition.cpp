#include <iostream>
using namespace std;

class Node {
public: 
    int data;
    Node *next;

    // Constructor to initialize a node with a value
    Node(int value) {
        data = value;
        next = NULL;
    }
};

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4
    Node *Head = new Node(1);
    Head->next = new Node(2);
    Head->next->next = new Node(3);
    Head->next->next->next = new Node(4);

    int x = 3; // Position at which to insert the new node (1-indexed)
    int value = 10; // Value to be inserted

    // If we need to insert at the beginning (position 1)
    if (x == 1) {
        Node* newNode = new Node(value);
        newNode->next = Head;
        Head = newNode;
    } else {
        Node *temp = Head;
        // Traverse to the node just before the insertion point
        for (int i = 1; i < x - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        // Ensure that the insertion position is valid
        if (temp != NULL) {
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    
    // Print the linked list to verify the insertion
    Node *current = Head;
    while(current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
