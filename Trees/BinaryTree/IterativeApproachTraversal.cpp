// In the recursion the stack is used to store the function call and the local variables of the function
// SO instead of doing the recursion for the inorder, preorder, postorder, we are going to use the stack..


// 1. preOrder Traversal of the tree
#include <iostream>
using namespace std;
#include <stack>
#include <vector>

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


    vector<int> preOrder(Node* node) {
        // code here
        vector<int> ans;
        stack<Node*>st;
          st.push(node);
        
        while(st.empty() != 0) {
            Node* temp = st.top();
            st.pop();
            ans.push_back(temp -> data);
            if(temp -> right) {
                st.push(temp -> right);    
            }
            if(temp -> left) {
                st.push(temp -> left);    
            }
        }
        return ans;
}

Node* createBinaryTree() {
    int rootVal;
    cin >> rootVal;
    Node* root = new Node(rootVal);

    // For demonstration, let's create a simple tree manually:
    // root->left = new Node(rootVal - 1);
    // root->right = new Node(rootVal + 1);
    // You can expand this function to take more input and build a tree as needed.

    return root;
}

int main() {
    cout << "Enter the value that you want as the root: " << endl;
    Node* root = createBinaryTree(); // Create the binary tree starting from the root
    cout << "Binary tree created successfully!" << endl;

    vector<int> result = preOrder(root); // Call preOrder function
    cout << "Preorder Traversal: ";
    for(int val : result) {
        cout << val << " "; // Print the preorder traversal
    }
    cout << endl;

    return 0; // Exit the program
}

// 2. postOrder
class Solution {
public:
    vector<int> postOrder(Node* node) {
        vector<int> ans;
        if (!node) return ans;
        
        stack<Node*> st;
        st.push(node);
          
        while (!st.empty()) {
            Node* temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            
            if (temp->left)  st.push(temp->left);   // ✅ push left later
            if (temp->right) st.push(temp->right);  // ✅ push right first
        }
        
        reverse(ans.begin(), ans.end()); // ✅ root-right-left → left-right-root
        return ans;
    }
};


// 3. inOrder
// in Order first time visit karunga the order will be right root left;
// 2nd time visit karunga toh direct print kardunga 

// in the inorder we are going to use the two stack ek stack occurence ke liye aur dusra stack print karne ke liye

vector<int> Inorder(Node* root) {
    stack<Node*> s;
    stack<bool> visited;

    s.push(root);
    visited.push(false);

    vector<int> ans;

    while (!s.empty()) {
        Node* curr = s.top();
        bool isVisited = visited.top();
        s.pop();
        visited.pop();

        if (curr == nullptr) continue; 

        if(!isVisited) {
            // First time visiting the node
           
            
            // Push right child first, then left child
            if (curr->right) {
                s.push(curr->right);
                visited.push(false);
            }
             s.push(curr); // Push the current node back onto the stack
            visited.push(true); // Mark it as visited
            if (curr->left) {
                s.push(curr->left);
                visited.push(false);
            }
        } else {
            // Second time visiting the node, print it
            ans.push_back(curr->data);
        }
    }
};