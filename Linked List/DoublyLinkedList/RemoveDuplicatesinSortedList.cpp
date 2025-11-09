#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};


int main() {
    vector<int> ans;
    ans.push_back(head -> data);
    Node *curr = head -> next;
    while(curr != NULL) {
        if(ans[ans.size() - 1] != curr -> data) {
            ans.push_back(curr -> data);
        }
        curr = curr -> next;
    }

    int index = 0;
    curr = head;

    while(index < ans.size()) {
        curr -> data = ans[index];
        index++;
        curr = curr -> next;
    }

    int size = ans.size() - 1;

    curr = head;
    while(size--) {
        curr = curr -> next;
    }
    curr -> next = NULL;
}