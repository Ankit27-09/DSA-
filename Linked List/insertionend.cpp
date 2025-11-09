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

int main() {
    Node *Head = NULL;  // Initialize Head to NULL
    Node *Tail = NULL;  // Initialize Tail to NULL
    int arr[] = {2, 4, 6, 8, 10};

    for(int i = 0; i < 5; i++) {
        // If the linked list is empty.
        if (Head == NULL) {
            Head = new Node(arr[i]);  // Create the first node
            Tail = Head;  // Set Tail to Head
        }
        // If the linked list is not empty.
        else {
            Tail->next = new Node(arr[i]);  // Create a new node and link it
            Tail = Tail->next;  // Move the Tail pointer to the new node
        }
    }

    // Print the linked list
    Node *temp = Head;
    while (temp) {
        cout << temp->data << endl;
        temp = temp->next;
    }
    return 0;
}
