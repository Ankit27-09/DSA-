// Create a Binary tree
// 1. We are creating the left side of the tree first
// 2. If the left child is -1, then we do not create a node
// step1 :-
// if the x is -1 return NULL
// other than that create a new node with value x
// left side jao 
// right side jao
// Node ke address ko return karo

// Time complexity: O(n) where n is the number of nodes in the binary tree
// Space complexity: O(h) where h is the height of the binary tree due to recursive
#include <iostream>
using namespace std;

class Node {  
    public:
        int data;
        Node* left;
        Node* right;
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


    // Recursive call for left child
    newNode->left = BinaryTree();
    // Recursive call for right child
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


// 2. Preorder Traversal of the tree
// In this traversal, we visit the root node first, then the left subtree, and finally the right subtree.
// This is a common way to display the structure of the tree.

void preOrder(Node* root) {
    if(root == NULL) return; // Base case: if the node is NULL, return
    cout << root->data << " "; // Visit the root node
    preOrder(root->left); // Traverse the left subtree
    preOrder(root->right); // Traverse the right subtree
}



// 3. Postorder Traversal of the tree
// In this traversal, we visit the left subtree first, then the right subtree, and finally
// the root node. This is useful for deleting nodes or freeing memory in a tree structure.

void postOrder(Node* root) {
    if(root == NULL) return; // Base case: if the node is NULL, return
    postOrder(root->left); // Traverse the left subtree
    postOrder(root->right); // Traverse the right subtree
    cout << root->data << " "; // Visit the root node
}
// 4. Inorder Traversal of the tree
// In this traversal, we visit the left subtree first, then the root node, and finally
// the right subtree. This traversal is often used to retrieve the elements of a binary search tree in sorted order.

void inOrder(Node* root) {
    if(root == NULL) return; // Base case: if the node is NULL, return
    inOrder(root->left); // Traverse the left subtree
    cout << root->data << " "; // Visit the root node
    inOrder(root->right); // Traverse the right subtree
}
