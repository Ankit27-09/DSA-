// Question Link -> https://leetcode.com/problems/palindrome-linked-list/description/


#include <iostream>
#include <stack>
using namespace std;

/*
 Intuition:
 ----------
 A palindrome reads the same forward and backward.
 But a singly linked list cannot be traversed backward.

 So we use a STACK (LIFO):
    - First, traverse the list and push all nodes into a stack.
    - Stack will store nodes in reverse order.
    - Then, traverse again from the head.
    - Compare each value with the value popped from the stack.
    - If all values match → list is a palindrome.

 Why does this work?
 -------------------
 Because pushing nodes in forward order means popping them gives us
 their reverse order. So we directly compare:
       front[i] == back[i]
 for all i.
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        // Edge cases: empty list or single node is always palindrome
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        stack<ListNode*> st;

        // STEP 1: Push all nodes into the stack
        // After this, top of stack = last node
        ListNode* temp = head;
        while (temp != nullptr) {
            st.push(temp);
            temp = temp->next;
        }

        // STEP 2: Reset temp to head to compare from front
        temp = head;

        // We use && because we must ensure BOTH temp and stack have elements.
        while (temp != nullptr && !st.empty()) {

            // Top of stack contains node from the back
            ListNode* backNode = st.top();
            st.pop();

            // If mismatch → not a palindrome
            if (temp->val != backNode->val) {
                return false;
            }

            temp = temp->next;   // move forward
        }

        // If loop completes → all matched
        return true;
    }
};


// 2. Approach by using half Reverse (O(1) space)

#include <iostream>
using namespace std;

/*
    Definition of ListNode for LeetCode-style questions.
    Each node has an integer value and a pointer to the next node.
*/
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    /*
        Function: reverseIterative
        ---------------------------
        Reverses a singly linked list in O(n) time using iterative method.

        Why we need it?
        ----------------
        To check palindrome, we reverse the SECOND HALF of the list,
        compare it with the first half, then reverse it back to restore.
    */
    ListNode* reverseIterative(ListNode* head) {

        ListNode* prev = NULL;   // previous node (initially NULL)
        ListNode* curr = head;   // current node to process

        while (curr != NULL) {
            
            ListNode* nxt = curr->next; // store next node

            curr->next = prev;          // reverse the pointer
            prev = curr;                // move prev forward
            curr = nxt;                 // move curr forward
        }

        // prev now points to the NEW HEAD of the reversed list
        return prev;
    }

    /*
        Function: isPalindrome
        -----------------------
        Checks if the linked list is a palindrome in O(n) time and O(1) space.

        Algorithm Steps:
        ----------------
        1. Use slow & fast pointers to find the middle of the list.
        2. Reverse the second half of the list.
        3. Compare first half and reversed second half.
        4. Restore the list back to original form.
        5. Return true if palindrome, otherwise false.
    */
    bool isPalindrome(ListNode* head) {

        // Base cases: empty list OR single node is always palindrome
        if (head == NULL || head->next == NULL) {
            return true;
        }

        // Initialize two pointers
        ListNode* fast = head;   // moves 2 steps at a time
        ListNode* slow = head;   // moves 1 step at a time

        /*
            Find the middle of the linked list.

            Condition explanation:
            ----------------------
            We check:
                fast->next != NULL    → ensures fast is not at last node
                fast->next->next != NULL → ensures next jump is possible

            This ensures safe movement of fast pointer by two steps.

            After loop ends:
                slow → will be at the middle node (or just before it for even length)
        */
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;         // move by 1
            fast = fast->next->next;   // move by 2
        }

        /*
            Reverse the second half of the list.

            slow->next → beginning of the second half.

            Example:
                1 → 2 → 3 → 2 → 1
                        ↑
                       slow

                After reversing second half:
                1 → 2 → 3 | 1 → 2
                              ↑ newHead
        */
        ListNode* newHead = reverseIterative(slow->next);

        // Now: first → head of first half
        //      second → head of reversed second half
        ListNode* first = head;
        ListNode* second = newHead;

        /*
            Compare both halves:

            We only iterate SECOND half because it is always
            equal or smaller than first half.

            If at any node values differ → NOT palindrome.
        */
        while (second != NULL) {

            // mismatch → not palindrome
            if (first->val != second->val) {

                // VERY IMPORTANT:
                // Restore the second half before returning
                reverseIterative(newHead);
                return false;
            }

            // Move both pointers forward
            first = first->next;
            second = second->next;
        }

        /*
            If all values matched → it's a palindrome

            Restore the second half to maintain input list structure
        */
        reverseIterative(newHead);

        return true;
    }
};
