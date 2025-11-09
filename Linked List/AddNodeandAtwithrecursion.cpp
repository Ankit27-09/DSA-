#include <iostream>  // Include input-output stream library
using namespace std;

// Definition of the Node class
class Node {
public:
    int data;   // Stores the data of the node
    Node *next; // Pointer to the next node

    // Constructor to initialize a node with a value
    Node(int value) {
        data = value;
        next = NULL;  // Initially, next is set to NULL
    }
};

// Recursive function to create a linked list from an array
Node* CreateLinkedList(int arr[], int index, int size) {
    // Base case: If index reaches size, return NULL (end of the list)
    if (index == size) {
        return NULL;
    }
    else {
        // Create a new node with the current array element
        Node *temp = new Node(arr[index]);  
        
        // Recursively create the rest of the linked list
        temp->next = CreateLinkedList(arr, index + 1, size);  
        
        // Return the newly created node (head of the sublist)
        return temp;
    }
}

int main() {
    Node *Head = NULL;  // Initialize head pointer to NULL
    int arr[] = {1, 2, 3, 4, 5, 6};  // Input array

    // Create linked list using recursion, passing index 0 and size of array
    Head = CreateLinkedList(arr, 0, 6);  

    // Print the linked list to verify its correctness
    Node *temp = Head;  // Temporary pointer to traverse the list
    while (temp != NULL) {  // Traverse until the end of the list
        cout << temp->data << " ";  // Print current node data
        temp = temp->next;  // Move to the next node
    }
    cout << endl;  // Print a newline after printing all elements

    return 0;  // Indicate successful program execution
}
