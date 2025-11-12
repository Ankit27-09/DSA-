// Question Link -> https://leetcode.com/problems/reverse-linked-list/

#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Function to reverse a linked list iteratively
    ListNode* reverseList(ListNode* head) { 
        // Initialize pointers
        ListNode* prev = NULL;     // Will point to the previous node (starts as NULL)
        ListNode* curr = head;     // Starts at the head of the list

        // Traverse the list
        while (curr != NULL) {
            // Step 1: Save the next node before breaking the link
            ListNode* nextNode = curr->next;

            // Step 2: Reverse the link
            curr->next = prev;

            // Step 3: Move the pointers one step forward
            prev = curr;
            curr = nextNode;
        }

        // At the end, 'prev' will be pointing to the new head
        return prev;
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

// Driver code for testing
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
    // Reverse the linked list
    head = sol.reverseList(head);

    cout << "\nReversed Linked List:\n";
    printList(head);

    return 0;
}
