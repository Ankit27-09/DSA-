#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int val) {
            data = val;
            next = NULL;
            prev = NULL;
        }
};

int main() {
    int arr[] = {10, 20, 30, 40, 50};

    Node* head = NULL;
    Node* tail = NULL;

    for(int i = 0; i < 5; i++) {
        //Linked List doesnt Exist
            if(head == NULL) {
                head = new Node(arr[i]);
                tail = head;
            }
            
            // Linked list Exist

            else {
                Node* newNode = new Node(arr[i]);
                tail -> next = newNode;
                newNode -> prev = tail;
                tail = newNode;
            }
    }

    Node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " <-> ";
        temp = temp -> next;
    }
}