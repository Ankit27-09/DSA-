// This code creates a binary tree from user input using level order traversal.
/*

#include <iostream>
using namespace std;
#include <queue>

class Node {
    public:
    Node* left;
    Node* right;
    int data;
    public:
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

int main() {
    int x;
    int first, second;
    queue<Node*> q;
    cout << "Enter the root element" << endl;
    cin >> x; 
    Node* root = new Node(x);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter the left child of" << temp -> data << endl;
        cin >> first;
        if(first != -1) {
            temp -> left = new Node(first);
            q.push(temp -> left);
        }

        cout << "Enter the right child of" << temp ->data << endl;
        cin >> second;
        if(second != -1) {
            temp -> right = new Node(second);
            q.push(temp -> right);
        }
    }
}
*/

// 2. Create a binary tree using recursion 
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Function to build binary tree
Node* BinaryTree() {
    int x;
    cout << "Enter data (-1 for no node): ";
    cin >> x;

    if (x == -1) return NULL; // Base case

    Node* root = new Node(x);
    cout << "Enter left child of " << x << endl;
    root->left = BinaryTree();

    cout << "Enter right child of " << x << endl;
    root->right = BinaryTree();

    return root;
}

// Postorder traversal
// TIme complexity: O(n)
// Space complexity: O(h) where h is the height of the binary tree due to recursive
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = BinaryTree();
    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;
    return 0;
}
