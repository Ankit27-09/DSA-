#include <iostream>
using namespace std;

// Definition of an array
// Array stores elements of the same data type in contiguous memory locations.
// Insertion and Deletion in an array is inefficient as elements have to be shifted.
// Accessing elements in an array is efficient as elements can be accessed using their index.
// Size of an array is fixed. It cannot be changed at runtime.
// Generally Array has less memory head, it only need to store data value.

// Use Cases of Array
// It is used when random access is crucial, data size is fixed and frequent modification is not required.
void arrayExample() {
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Definition of a linked list
// Linked List stores elements in non-contiguous memory locations. Each element is called a node.
// Insertion and Deletion in a linked list is efficient as elements can be added or removed without shifting.
// Accessing elements in a linked list is inefficient as elements have to be traversed sequentially.
// Size of a linked list is dynamic. It can be changed at runtime.
// Required additional memory to store the address of the next element.

// Use Cases
// Used when frequent insertion and deletion are required, or data size is dynamic.
struct Node {
    int data;
    Node* next;
};

void linkedListExample() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = nullptr;

    cout << "Linked List elements: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Free allocated memory
    delete head;
    delete second;
    delete third;
}

int main() {
    arrayExample();
    linkedListExample();
    return 0;
}