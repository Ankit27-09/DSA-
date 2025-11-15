// Question Link ->  https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

// Optimised Approach

#include <iostream>
using namespace std;

/*
    -----------------------------------------------------------------
    Definition of a singly linked list node (same as LeetCode default)
    -----------------------------------------------------------------
*/
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
    -----------------------------------------------------------------
            DELETE MIDDLE NODE — ONE PASS SOLUTION (O(n))
    -----------------------------------------------------------------
    Intuition:
    ----------
    We want to delete the node at index floor(n / 2) (0-based).

    Examples:
        n = 1 → middle = 0
        n = 2 → middle = 1
        n = 3 → middle = 1
        n = 4 → middle = 2
        n = 5 → middle = 2
        n = 7 → middle = 3

    We use two pointers:
        • slow  → moves 1 step
        • fast  → moves 2 steps

    Why it works:
        - fast moves twice as fast
        - So when fast reaches the end,
          slow will be near the middle.
        - But we want slow to stop at (middle - 1)
          so that slow->next is the middle node to delete.

    Technique:
        1. Move fast two steps initially.
        2. Then move slow=slow->next and fast=fast->next->next
        3. Stop when fast reaches end.
           Now slow->next is the MIDDLE node.

    After loop:
        slow->next = middle node → delete it
*/


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // -------------------------------
        // CASE 1: If the list is empty
        // -------------------------------
        if (head == NULL)
            return NULL;

        // -------------------------------
        // CASE 2: If list has only 1 node
        // Middle is the only node → delete it
        // -------------------------------
        if (head->next == NULL) {
            delete head;         // free memory
            return NULL;         // final list becomes empty
        }

        // Two-pointer method starts here
        ListNode* slow = head;   // will reach node BEFORE middle
        ListNode* fast = head;   // moves twice as fast

        /*
            Move fast two steps initially.
            This creates an offset so that when fast reaches the last node,
            slow stops at (middle - 1)-th index.
        */
        fast = fast->next->next;

        /*
            Loop until fast reaches end.
            Condition:
                - fast ≠ NULL ensures fast pointer is valid
                - fast->next ≠ NULL ensures fast can still move 2 steps

            Movement summary:
                slow → moves one step
                fast → moves two steps

            This ensures correct alignment to delete the middle node.
        */
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;         // slow moves 1 step
            fast = fast->next->next;   // fast moves 2 steps
        }

        /*
            At this point:
                slow = node BEFORE the middle
                slow->next = middle node

            So deleting middle is easy:
        */

        ListNode* deleteNode = slow->next;      // actual middle node
        slow->next = slow->next->next;          // unlink middle node
        delete deleteNode;                      // free memory

        return head;                            // return updated list
    }
};


// Counting Approach 
#include <iostream>
using namespace std;

/*
    Definition for singly-linked list node.
    This structure is used by LeetCode for all linked list problems.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    /*
        Function: deleteMiddle
        -----------------------
        Deletes the middle node of the linked list.
        Middle is defined as floor(n / 2) (0-based indexing).

        Approach: TWO PASS (Count first, then delete)
        --------------------------------------------
        1) First pass → count total nodes.
        2) Middle index = count / 2  (floor division)
        3) Traverse again to reach (middle - 1)-th node.
        4) Delete (middle)-th node by linking around it.
    */
    ListNode* deleteMiddle(ListNode* head) {

        // Case 1: Empty list
        if (head == NULL)
            return NULL;

        // Case 2: Only 1 node → deleting middle returns empty list
        if (head->next == NULL) {
            delete head;       // free memory
            return NULL;
        }

        // ----------------------------------------------------------
        // PASS 1: Count number of nodes in the list
        // ----------------------------------------------------------
        int count = 0;
        ListNode* curr = head;

        while (curr != NULL) {
            count++;
            curr = curr->next;
        }

        /*
            Example:
                List: [1, 3, 4, 7, 1, 2, 6]
                count = 7
                middle index = floor(7 / 2) = 3  (0-based)
                Node at index 3 (value 7) should be deleted.
        */

        int k = count / 2;   // middle index
        curr = head;         // reset to head

        // ----------------------------------------------------------
        // PASS 2: Move curr to the (k-1)-th node (node before middle)
        // ----------------------------------------------------------
        /*
            We want to stop one step before the middle node
            because to delete:
                 curr->next = curr->next->next

            Loop condition: while (k - 1 > 0)
                Example:
                    count = 7 → k = 3
                    We want curr to stop at index 2.
                    Loop runs while (3 - 1 > 0):
                        iteration 1 → curr moves to index 1 (k becomes 2)
                        iteration 2 → curr moves to index 2 (k becomes 1)
                        iteration stops because now (1 - 1 > 0) is false
        */
        while (k - 1 > 0) {
            curr = curr->next;
            k--;
        }

        // ----------------------------------------------------------
        // DELETE the middle node
        // ----------------------------------------------------------
        ListNode* deleteNode = curr->next;       // node at middle index
        curr->next = curr->next->next;           // unlink middle node
        delete deleteNode;                       // free memory

        return head;   // return updated list
    }
};
