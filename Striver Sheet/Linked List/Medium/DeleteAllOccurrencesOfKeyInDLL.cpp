#include <iostream>
using namespace std;

// Structure for a node in a Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

// Function to delete all occurrences of a given key 'k'
Node* deleteAllOccurrences(Node* head, int k) {
    Node* temp = head;  // start from the head of the DLL

    // Traverse the linked list
    while (temp != NULL) {

        // Check if current node's data matches key 'k'
        if (temp->data == k) {

            // ----------------------------------------------------
            // CASE 1️⃣ : Node to be deleted is the HEAD node
            // ----------------------------------------------------
            // If the node to be deleted is the head, 
            // then after deletion, head should move to next
            if (temp == head) {
                head = temp->next;
            }

            // Store previous and next node references
            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;

            // ----------------------------------------------------
            // CASE 2️⃣ : Adjust pointers to bypass 'temp'
            // ----------------------------------------------------
            // If there is a next node, update its 'prev' pointer
            if (nextNode != NULL)
                nextNode->prev = prevNode;

            // If there is a previous node, update its 'next' pointer
            if (prevNode != NULL)
                prevNode->next = nextNode;

            // ----------------------------------------------------
            // CASE 3️⃣ : Delete the node
            // ----------------------------------------------------
            // Free the memory for the deleted node
            free(temp);

            // Move 'temp' to the next node to continue traversal
            temp = nextNode;
        }
        else {
            // If value does not match, move to next node normally
            temp = temp->next;
        }
    }

    return head; // Return updated head pointer
}

// Utility: Insert new node at end of the DLL
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);

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

// Utility: Print the doubly linked list
void printList(Node* head) {
    cout << "NULL <-> ";
    while (head != NULL) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Driver function to test the code
int main() {
    Node* head = NULL;

    // Create DLL: 10 <-> 20 <-> 20 <-> 30 <-> 40 <-> 20
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    insertEnd(head, 20);

    cout << "Original Doubly Linked List:\n";
    printList(head);

    int key = 20;

    // Call deletion function
    head = deleteAllOccurrences(head, key);

    cout << "\nList after deleting all occurrences of " << key << ":\n";
    printList(head);

    /*
        🔹 Dry Run:
        Input : 10 <-> 20 <-> 20 <-> 30 <-> 40 <-> 20
        Key   : 20

        temp = 10 → skip
        temp = 20 → delete (fix pointers)
        temp = 20 → delete (fix pointers)
        temp = 30 → skip
        temp = 40 → skip
        temp = 20 → delete (tail)
        ✅ Output : 10 <-> 30 <-> 40
    */

    return 0;
}

/*
    -----------------------------------------------------
                    COMPLEXITY ANALYSIS
    -----------------------------------------------------
    ✅ Time Complexity:  O(n)
       - Each node visited once.

    ✅ Space Complexity: O(1)
       - In-place deletion, no extra space.

    ✅ Handles all cases:
       - Deleting head node(s)
       - Deleting middle/tail nodes
       - All nodes are equal to key
       - Empty list
*/
