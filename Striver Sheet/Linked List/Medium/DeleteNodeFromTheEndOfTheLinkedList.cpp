// Question Link -> https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/


//Optimised Approach 
/*
    Problem: Remove the N-th node from the end of a singly linked list.

    Approach Used: ONE-PASS (Fast & Slow Pointer Technique)

    Key Idea:
        - Move the FAST pointer 'n' steps ahead.
        - Then move both FAST and SLOW until FAST reaches the last node.
        - At this point, SLOW is standing *just before* the node to delete.
*/
#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // ------------------------------
        // BASE CONDITIONS
        // ------------------------------

        // Case 1: Empty list → nothing to remove
        if (head == NULL)
            return NULL;

        // Case 2: Only one node and n == 1 → remove that node
        if (head->next == NULL && n == 1)
            return NULL;

        // ------------------------------
        // STEP 1: Declare two pointers
        // ------------------------------
        ListNode* fast = head;   // moves ahead by n steps
        ListNode* slow = head;   // will stop just before the target node


        // ------------------------------
        // STEP 2: Move FAST 'n' steps forward
        // ------------------------------
        /*
            Why we do this?
            
            After moving FAST n steps ahead, the distance between 
            FAST and SLOW becomes n.
            
            When FAST finally reaches the end of the list,
            SLOW will be at (length - n)-th node,
            which is just before the node we want to delete.
        */
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // ------------------------------
        // STEP 3 (IMPORTANT EDGE CASE):
        // If FAST becomes NULL after moving 'n' steps,
        // it means we need to delete the HEAD node.
        // ------------------------------
        /*
            Example:
                List = 10 -> 20 -> 30
                n = 3 (remove 3rd from end = remove head)

            FAST moves 3 steps → becomes NULL
            So answer = head->next
        */
        if (fast == NULL) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // ------------------------------
        // STEP 4: Move FAST and SLOW together 
        // until FAST reaches the last node
        // ------------------------------
        /*
            Condition: while(fast->next != NULL)
            
            Why not while(fast != NULL)?
            Because we want FAST to stop ON THE LAST NODE,
            not go beyond it.

            When fast->next == NULL:
                → fast is at last node.
                → slow is exactly before the node we want to delete.
        */
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // ------------------------------
        // STEP 5: Delete the target node
        // ------------------------------
        /*
            slow->next is the node to be deleted.
            Example:
                slow = node with value 3
                slow->next = node with value 4 (DELETE THIS)
                slow->next->next = node with value 5
        */
        ListNode* deleteNode = slow->next;
        slow->next = deleteNode->next; // link prev node to next node
        delete deleteNode;             // free memory

        // ------------------------------
        // STEP 6: Return the updated head
        // ------------------------------
        return head;
    }
};

// --------------------------------------------------------------------------------------------
// Two pass Approach 
#include <iostream>
using namespace std;

/*
 Definition for singly-linked list node.
 Provided here so the file is self-contained (use this in coding notes).
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 Two approaches are provided below:
 1) twoPassRemoveNthFromEnd : count nodes (two passes)
 2) onePassRemoveNthFromEnd : fast/slow two-pointer (one pass)
 Both return the head of the modified list.
*/

// ----------------------
// Approach 1: Two-pass
// ----------------------
class SolutionTwoPass {
public:
    ListNode* twoPassRemoveNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;            // empty list
        // If list has single node and n == 1, result is empty list
        if (head->next == nullptr && n == 1) {
            delete head;
            return nullptr;
        }

        // First pass: count nodes
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            ++count;
            temp = temp->next;
        }

        // If we need to remove the head itself (n == count)
        if (count == n) {
            ListNode* newHead = head->next;
            delete head;               // free the removed node
            return newHead;
        }

        // Otherwise, find the (count - n)-th node (1-based)
        // which will be the node just before the node to remove.
        int targetIndex = count - n;   // targetIndex >= 1 (head is index 1)
        temp = head;
        // Move (targetIndex - 1) times to reach the previous node
        for (int i = 1; i < targetIndex; ++i) {
            temp = temp->next;
        }

        // temp now points to node before the one to delete
        ListNode* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
        return head;
    }
};

