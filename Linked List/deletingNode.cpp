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

// Recursive function to create linked list from array
Node* CreateLinkedList(int arr[], int index, int size) {
    // Base case: End of array
    if (index == size) {
        return NULL;
    }
    else {
        Node *temp = new Node(arr[index]); 
        temp->next = CreateLinkedList(arr, index + 1, size);  
        return temp;
    }
}

// Function to print the linked list
void PrintLinkedList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function
int main() {
    Node *Head = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6};
    Head = CreateLinkedList(arr, 0, 6);  // Pass the correct size

    // Print the list before deletion
    cout << "Linked list before deletion: ";
    PrintLinkedList(Head);

    // Deleting the node at the start (Head)
    if (Head != NULL) {
        Node *temp = Head;
        Head = Head->next;  // Move the head to the next node
        delete(temp);       // Free memory of the old head node
    }

    // Print the list after deletion
    cout << "Linked list after deletion: ";
    PrintLinkedList(Head);

    return 0;
}
