// Question Link -> https://leetcode.com/problems/reverse-linked-list/

#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    
    // Constructor to initialize a node easily
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Recursive helper function to reverse the linked list
    // Parameters:
    // curr -> the current node we are processing
    // prev -> the previous node (initially NULL)
    ListNode* reverseRecursive(ListNode* curr, ListNode* prev) {
        // Base condition:
        // If the current node is NULL, we've reached the end of the list.
        // At this point, 'prev' will be pointing to the new head of the reversed list.
        if (curr == NULL) {
            return prev;
        }

        // Save the next node before breaking the link
        ListNode* nextNode = curr->next;

        // Reverse the link: current node now points to the previous node
        curr->next = prev;

        // Move one step ahead:
        // - The current node becomes the previous node
        // - The next node becomes the current node
        return reverseRecursive(nextNode, curr);
    }

    // Main function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        // Initially, 'prev' is NULL since the head node will become the last node
        ListNode* prev = NULL;

        // Call the recursive helper function
        return reverseRecursive(head, prev);
    }
};

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Driver code to test the reverseList function
int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original Linked List:\n";
    printList(head);

    Solution sol;
    // Reverse the list using recursion
    head = sol.reverseList(head);

    cout << "\nReversed Linked List:\n";
    printList(head);

    return 0;
}
