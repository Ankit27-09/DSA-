#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node* createLinkedList(int arr[], int size, int index) {
    if (index == size) {
        return NULL;
    } else {
        Node* temp = new Node(arr[index]);  // Fixed class name
        temp->next = createLinkedList(arr, size, index + 1);
        return temp;
    }
}

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* Head = NULL;
    int arr[] = {1, 2, 3, 4, 5};

    Head = createLinkedList(arr, 5, 0);

    
    // Delete a node at Start
    
    if(Head != NULL) {
        Node* temp = Head;
        Head = Head -> next;
        delete temp;
    }
    // Print to verify
    printLinkedList(Head);
    
    return 0;
}
