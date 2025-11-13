// Question Link ->  https://leetcode.com/problems/odd-even-linked-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        // Edge case: 
        // If the list is empty or contains only one node, 
        // then odd-even rearrangement does nothing.
        if (!head || !head->next) return head;

        // We will store the final order of node values in this vector.
        // First store all odd-index nodes, then all even-index nodes.
        vector<int> result;

        // ---------------------------------------------------------------
        // STEP 1: Store all odd positioned node values in the vector.
        // Odd positions: 1st, 3rd, 5th, ...
        // We start from head and jump 2 steps each time.
        // ---------------------------------------------------------------
        ListNode* temp = head;

        // While both temp and temp->next exist, it means current node is odd.
        while (temp != NULL && temp->next != NULL) {
            result.push_back(temp->val);  // store odd-indexed node value
            temp = temp->next->next;      // jump to next odd node
        }

        // If temp is not NULL here, it means last odd node exists (for odd length list)
        if (temp) {
            result.push_back(temp->val);
        }

        // ---------------------------------------------------------------
        // STEP 2: Store all even positioned node values in the vector.
        // Even positions: 2nd, 4th, 6th, ...
        // Even nodes start from head->next
        // ---------------------------------------------------------------
        temp = head->next;

        // Same logic: jump 2 steps to stay on even nodes
        while (temp != NULL && temp->next != NULL) {
            result.push_back(temp->val);  // store even-indexed node value
            temp = temp->next->next;      // jump to next even node
        }

        // If temp exists, add the last even node
        if (temp) {
            result.push_back(temp->val);
        }

        // ---------------------------------------------------------------
        // STEP 3: Rewrite the linked list values from the result array.
        // Meaning we update the node values in the rearranged odd-even order.
        // ---------------------------------------------------------------
        temp = head;

        for (int i = 0; i < result.size(); i++) {
            temp->val = result[i];   // overwrite node value with reordered data
            temp = temp->next;
        }

        return head;   // return the modified list
    }
};

// Optimised Approach 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        // ---------------------------------------------------------------
        // EDGE CASE:
        // If list has 0 or 1 node → no rearrangement possible
        // ---------------------------------------------------------------
        if (!head || !head->next) return head;

        // ---------------------------------------------------------------
        // odd  pointer → points to the 1st node  (odd position)
        // even pointer → points to the 2nd node (even position)
        // evenHead     → stores the starting point of even list,
        //                 because we must attach it at the end of odd list.
        // ---------------------------------------------------------------
        ListNode* odd = head;            // position 1
        ListNode* even = head->next;     // position 2
        ListNode* evenHead = head->next; // store for later connection

        // ---------------------------------------------------------------
        // MAIN LOOP:
        // We will rearrange by changing pointers:
        //
        // odd->next should skip even and go to next odd
        // even->next should skip odd and go to next even
        //
        // Condition:
        //  even != NULL          → ensure even node exists
        //  even->next != NULL    → ensure next odd node exists
        // ---------------------------------------------------------------
        while (even != NULL && even->next != NULL) {

            // --------------------------
            // Connect current odd node to the next odd node
            // odd->next currently points to even
            // odd->next->next is the next odd node
            // --------------------------
            odd->next = odd->next->next;

            // --------------------------
            // Similarly connect current even node to the next even node
            // even->next->next is the next even node
            // --------------------------
            even->next = even->next->next;

            // Move both pointers forward:
            odd = odd->next;   // move to next odd
            even = even->next; // move to next even
        }

        // ---------------------------------------------------------------
        // At the end, link the last odd node to the head of even list.
        // This finalizes the "odd segment + even segment" structure.
        // ---------------------------------------------------------------
        odd->next = evenHead;

        // Return the modified list
        return head;
    }
};
