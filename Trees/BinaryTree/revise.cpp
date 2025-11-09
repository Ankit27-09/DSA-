#include <iostream>
using namespace std;

class Node {
    public:
    Node* left, *right;
    int data;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

Node* BinaryTree() {
    int x;
    cin >> x; // Input for the node value

    if(x == -1) return NULL; // If x is -1, return NULL

    Node* newNode = new Node(x); // Create a new node with value x

    cout << "Enter the left child of " << x << ": ";
    int leftValue;

    cin >> leftValue; // Input for left child

    newNode->left = BinaryTree();
     // Recursive call for left child
    cout << "Enter the right child of " << x << ": ";
    int rightValue;

    newNode->right = BinaryTree(); // Recursive call for right child
    return newNode; // Return the newly created node
}

int main () {
    cout << "Enter the value that you want as the root: " << endl;
    Node* root = BinaryTree(); // Create the binary tree starting from the root
    cout << "Binary tree created successfully!" << endl;
    // You can add code here to traverse or display the tree if needed
    return 0; // Exit the program  
}
