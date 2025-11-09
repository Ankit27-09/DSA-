// Level order traversal printing 

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
    // Address are stored in the queue
    queue<Node*> q;
    Node *root = new Node(x);
    q.push(root);
    // Build the binary tree

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

    // Print in level traversal order
    q.push(root);
    while(!q.empty()) {
        cout << q.front() << endl;
        q.pop();
        q.push(root -> left);
        q.push(root -> right);
    }
}

