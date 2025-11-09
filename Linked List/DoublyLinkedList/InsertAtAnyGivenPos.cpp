#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// Function to insert at a given position in a doubly linked list
void insertAtPosition(Node*& head, int pos, int val) {
    Node* newNode = new Node(val);

    // Insert at the beginning
    if (pos == 0) {
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return;
    }

    Node* curr = head;
    
    // Traverse to the (pos-1)th node
    int tempPos = pos;
    while (--tempPos && curr != NULL) {
        curr = curr->next;
    }

    // If `curr` is NULL, the position is out of bounds
    if (curr == NULL) {
        cout << "Position out of range!\n";
        delete newNode;  // Prevent memory leak
        return;
    }

    // Insert at the end
    if (curr->next == NULL) {
        curr->next = newNode;
        newNode->prev = curr;
    }
    // Insert in the middle
    else {
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next->prev = newNode;
        curr->next = newNode;
    }
}

// Function to print the doubly linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    // Insert at different positions
    insertAtPosition(head, 0, 10);  // Insert 10 at position 0
    insertAtPosition(head, 1, 20);  // Insert 20 at position 1
    insertAtPosition(head, 2, 30);  // Insert 30 at position 2
    insertAtPosition(head, 1, 40);  // Insert 40 at position 1

    // Print the doubly linked list
    cout << "Doubly Linked List: ";
    printList(head);

    return 0;
}
