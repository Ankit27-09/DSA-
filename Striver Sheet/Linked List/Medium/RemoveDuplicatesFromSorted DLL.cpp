#include <iostream>
using namespace std;

// Structure for a node in a Doubly Linked List
struct Node {
    int val;
    Node* next;
    Node* prev;

    Node(int data) {
        val = data;
        next = NULL;
        prev = NULL;
    }
};

// Function to remove duplicates from a sorted doubly linked list
void removeDuplicates(Node* head) {
    // 'temp' pointer is used to traverse the list
    Node* temp = head;

    // Traverse until the end of the list
    while (temp != NULL && temp->next != NULL) {

        // 'nextNode' will check for duplicates ahead of 'temp'
        Node* nextNode = temp->next;

        // Skip all nodes having the same value as 'temp->val'
        while (nextNode != NULL && nextNode->val == temp->val) {
            nextNode = nextNode->next;  // move forward to find first non-duplicate
        }

        // Link 'temp->next' to the first non-duplicate node
        temp->next = nextNode;

        // If 'nextNode' is not NULL, fix its 'prev' pointer
        if (nextNode) {
            nextNode->prev = temp;
        }

        // Move 'temp' forward to continue the process
        temp = temp->next;
    }
}

// Helper function to insert node at the end
void insertEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Helper function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Driver Code
int main() {
    Node* head = NULL;

    // Creating a sorted doubly linked list with duplicates
    insertEnd(head, 1);
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 4);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "Original DLL: ";
    printList(head);

    // Remove duplicates
    removeDuplicates(head);

    cout << "After removing duplicates: ";
    printList(head);

    return 0;
}
