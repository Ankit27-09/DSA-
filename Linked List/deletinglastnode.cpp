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
    } else {
        Node *temp = new Node(arr[index]); 
        temp->next = CreateLinkedList(arr, index + 1, size);  
        return temp;
    }
}

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
    Head = CreateLinkedList(arr, 0, 6);  // Create the linked list

     // Print the list before deletion
    cout << "Linked list before deletion: ";
    PrintLinkedList(Head);

    // Delete a node at the end
    if (Head != NULL) {
        // If only one node is present
        if (Head->next == NULL) { 
            Node *temp = Head;
            delete temp;
            Head = NULL;
        }
        // More than one node is present
        else {
            Node *curr = Head;
            Node *prev = NULL;

            // Traverse to the last node
            while (curr->next != NULL) {
                prev = curr;
                curr = curr->next;
            }

            // Delete the last node
            prev->next = NULL; // Set the second-last node's next to NULL
            delete curr;
        }
    }
    
     // Print the list bAfter  deletion
    cout << "Linked list before deletion: ";
    PrintLinkedList(Head);

    return 0;
}
