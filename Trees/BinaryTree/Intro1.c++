// Tree: It is a Data Structure is a non-linear data structure in which a collection of elements known as nodes are connected to each other via edges such that there exists exactly one path between any two nodes.

// Binary Tees:-- It is defined as a Tree data Structure where each node has atmost 2 childrens.

// If there are n nodes then there will be n - 1 edges

// Basic Terminologies In Tree Data Structure:

/*
Parent Node: The node which is an immediate predecessor of a node is called the parent node of that node. {B} is the parent node of {D, E}.

Child Node: The node which is the immediate successor of a node is called the child node of that node. Examples: {D, E} are the child nodes of {B}.

Root Node: The topmost node of a tree or the node which does not have any parent node is called the root node. {A} is the root node of the tree. A non-empty tree must contain exactly one root node and exactly one path from the root to all other nodes of the tree.

Leaf Node or External Node: The nodes which do not have any child nodes are called leaf nodes. {I, J, K, F, G, H} are the leaf nodes of the tree.

Ancestor of a Node: Any predecessor nodes on the path of the root to that node are called Ancestors of that node. {A,B} are the ancestor nodes of the node {E}

Descendant: A node x is a descendant of another node y if and only if y is an ancestor of x.

Sibling: Children of the same parent node are called siblings. {D,E} are called siblings.

Level of a node: The count of edges on the path from the root node to that node. The root node has level 0.

Internal node: A node with at least one child is called Internal Node.

Neighbour of a Node: Parent or child nodes of that node are called neighbors of that node.

Subtree: Any node of the tree along with its descendant.

Degree of a Node: The number of children of a node is called the degree of that node. The degree of the root node is called the degree of the tree.

Height of a Node: The number of edges on the longest path from that node to a leaf node is called the height of that node.

Edge: The connection between two nodes is called an edge.
*/

#include <iostream>
using namespace std;
#include <queue>

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};


int main() {
    int x;
    int first, second;
    cout << " Enter the value that you want as the root " << endl;
    cin >> x;
    queue<Node*> q;
    Node *root = new Node(x);
    q.push(root);
    // BUild the binary tree

    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
         // left Node
        cout << "Enter the left child of " << temp -> data << endl;
        cin >> first; // left node ki value
        if(first != -1) {
            temp -> left  = new Node(first);
            q.push(temp -> left);
        }

        // Right Node
        cout << "Enter the right child of " << temp -> data << endl;
        cin >> second;
        if(second != -1) {
            temp -> right = new Node(second);
            q.push(temp -> right);
        }
    }
}