// Question Link -> https://leetcode.com/problems/add-two-numbers/description/

#include <iostream>
using namespace std;
#include <vector>

/**
 * Definition for singly-linked list.
 * This is the typical LeetCode node definition.
 */
struct ListNode {
    int val;
    ListNode *next;
    // Constructors for easy node creation
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Solution class containing the addTwoNumbers function.
 * The function returns a new linked list representing the sum.
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy head simplifies building the result list.
        // At the end we return dummy->next (skipping the placeholder).
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;  // tail points to last node in the result list
        int carry = 0;           // carry between digit additions

        // Continue while there are digits in either list or there is a carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get values from current nodes (0 if node is null)
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            // Compute sum and update carry
            int sum = x + y + carry;
            carry = sum / 10;               // carry for next position (0 or 1 here)
            int digit = sum % 10;           // digit to store in new node

            // Append new node with digit
            tail->next = new ListNode(digit);
            tail = tail->next;

            // Advance input pointers if possible
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // Save head of result and delete dummy node to avoid memory leak in
        // non-LeetCode contexts (optional).
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

/* ---------------------------
   Helper functions for testing
   --------------------------- */

// Build a linked list from vector<int> (least significant digit first)
ListNode* buildList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* cur = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

// Print linked list as [a,b,c]
void printList(ListNode* head) {
    cout << "[";
    ListNode* cur = head;
    bool first = true;
    while (cur) {
        if (!first) cout << ",";
        cout << cur->val;
        first = false;
        cur = cur->next;
    }
    cout << "]";
}

// Free list memory
void freeList(ListNode* head) {
    while (head) {
        ListNode* nxt = head->next;
        delete head;
        head = nxt;
    }
}

/* ---------------------------
   Example usage (main)
   --------------------------- */
int main() {
    // Example 1: l1 = [2,4,3], l2 = [5,6,4]  => [7,0,8]
    ListNode* l1 = buildList({2,4,3});
    ListNode* l2 = buildList({5,6,4});

    Solution sol;
    ListNode* sum = sol.addTwoNumbers(l1, l2);

    cout << "l1 = "; printList(l1); cout << "\n";
    cout << "l2 = "; printList(l2); cout << "\n";
    cout << "sum = "; printList(sum); cout << "\n";

    // Clean up
    freeList(l1);
    freeList(l2);
    freeList(sum);
    return 0;
}
