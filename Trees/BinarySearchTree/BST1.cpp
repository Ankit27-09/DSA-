// A Binary Search Tree (or BST) is a data structure used in computer science for organizing and storing data in a sorted manner. 
// Each node in a Binary Search Tree has at most two children, a left child and a right child, with the left child containing values less than the parent node and the right child containing values greater than the parent node. 
// This hierarchical structure allows for efficient searching, insertion, and deletion operations on the data stored in the tree.
// The Inorder traversal of a Binary Search Tree results in the elements being visited in ascending order, making it easy to retrieve sorted data.
/* Properties of Binary Search Tree:
The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
The left and right subtree each must also be a binary search tree.  
There must be no duplicate nodes(BST may have duplicate values with different handling approaches). */


/* Important Points about BST
A Binary Search Tree is useful for maintaining sorted stream of data. It allows search, insert, delete, ceiling, max and min in O(h) time. Along with these, we can always traverse the tree items in sorted order.
With Self Balancing BSTs, we can ensure that the height of the BST is bound be Log n. Hence we achieve, the above mentioned O(h) operations in O(Log n) time.
When we need only search, insert and delete and do not need other operations, we prefer Hash Table over BST as a Hash Table supports these operations in O(1) time on average.
*/

/* 
Advantages of Binary Search Tree (BST):
Efficient searching: O(log n) time complexity for searching with a self balancing BST
Ordered structure: Elements are stored in sorted order, making it easy to find the next or previous element
Dynamic insertion and deletion: Elements can be added or removed efficiently
Balanced structure: Balanced BSTs maintain a logarithmic height, ensuring efficient operations
Doubly Ended Priority Queue: In BSTs, we can maintain both maximum and minimum efficiently.
*/

/* Important points:--->
1.) Time Complexity of Insertion :-- O(h) where h is the height of the tree.[Worst Time Complexity]
// Reason is becasue every node is visited from the root to the leaf node.
// The height of the tree is the longest path from the root to the leaf node.
2.) Time Complexity of Searching :-- O(h) where h is the height of the tree.
3.) Space Complexity of Binary Search Tree :-- O(n) where n is the number of nodes in the tree.
 
*/


#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node*left, *right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int value) {
    // base case
    if(root == NULL) {
       Node* temp = new Node(value);
       return temp;
    }

    if(value < root -> data) {
        root -> left = insert(root -> left, value);
    } else {
        root -> right = insert(root -> right, value);
    }
    return root;
};

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
};

bool search(Node* root, int value) {
    // base case
    if(root == NULL) {
        return false;
    }

    if(root -> data == value) {
        return true;
    } else if(value < root -> data) {
        return search(root -> left, value);
    } else {
        return search(root -> right, value);
    }
}


int main() {
    int arr[] = {10, 5, 15, 2, 7, 12, 20};
    Node *root = NULL;

    for(int i = 0; i < 6; i++) {
       root = insert(root, arr[i]);
    }

    // Searching for a value
    int searchValue = 7;
    search(root, searchValue) ? 
        cout << "Value " << searchValue << " found in the BST." << endl : 
        cout << "Value " << searchValue << " not found in the BST." << endl;


    // Traverse
    inorder(root);

    return 0;
}