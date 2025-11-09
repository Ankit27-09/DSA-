// Insertion

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
    Node *HEAD;
    HEAD = new Node(4);
    cout << HEAD << endl;
    cout << HEAD -> data;
    cout << HEAD -> next;
}