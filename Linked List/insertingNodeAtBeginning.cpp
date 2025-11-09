#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    // Constructor to initialize a node
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Recursive function to insert elements at the beginning
Node *InsertAtBeginning(int arr[], int size, int index, Node *prev) {
    // Base case: If index reaches size, return the head (prev)
    if (index == size) {
        return prev;
    }

    // Create a new node with the current array element
    Node *temp = new Node(arr[index]);

    // Point new node's next to previous node (head of current list)
    temp->next = prev;

    // Recursive call for the next index
    return InsertAtBeginning(arr, size, index + 1, temp);
}

int main() {
    Node *Head = NULL; // Initialize head pointer

    int arr[] = {2, 4, 6, 8, 10}; // Input array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate size of array

    // Call function to insert elements at the beginning
    Head = InsertAtBeginning(arr, size, 0, Head);

    // Print the linked list to verify
    Node *temp = Head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
