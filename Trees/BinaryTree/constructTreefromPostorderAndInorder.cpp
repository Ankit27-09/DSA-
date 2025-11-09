// Construct a unique tree from postorder and inorder
// Take the root from the last as the root node and then find the position of the root node in the inorder array.



#include <iostream>
using namespace std;


class Node {
    int data;
    Node *left, *right;
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

int find(int *inOrder, int target, int start, int end) {
    for(int i = start; i <= end; i++) {
        if(inOrder[i] == target) {
            return i;
        }
    }
    return -1;
};


Node* Tree(int *inOrder, int* pos, int inStart, int inEnd, int index) {
    if(inStart > inEnd) {
        return NULL;
    }

    Node *root = new Node(pos[index]);
    int position = find(inOrder, pos[index], inStart, inEnd);
    root -> right = Tree(inOrder, pos, position + 1, inEnd, index - 1);
    root -> left = Tree(inOrder, pos, inStart, position - 1, index - (inEnd - position) - 1);
    return root;
}

int main() {
    
}
