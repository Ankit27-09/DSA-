// Question Link -> https://leetcode.com/problems/sort-list/description/

// First Approach is by taking one more array to store the values of linked list and then sort that array and again put the values back to linked list.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Definition of singly-linked list node.

    Each node contains:
        - an integer value (val)
        - a pointer to the next node (next)
*/
struct ListNode {
    int val;
    ListNode *next;

    // Constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    /*
        Function: sortList
        Purpose: Sorts a linked list using a naive approach.

        Strategy (Naive Approach):
        --------------------------
        1. Traverse the linked list and store all values in a vector.
        2. Sort the vector using sort() → O(n log n).
        3. Traverse the linked list again, and rewrite node values
           from the sorted vector.
        
        Important:
        - We are NOT rearranging node pointers.
        - Only the values inside the nodes are changed.
        - This is allowed because problem constraints allow value modification.
        
        Time Complexity:
            O(n)       → copying values into vector
            O(n log n) → sorting vector
            O(n)       → writing values back into linked list
            -----------------------------------------------
            Total = O(n log n)

        Space Complexity:
            O(n) → vector storing n elements
    */
    ListNode* sortList(ListNode* head) {

        // If list is empty or contains only 1 node, it's already sorted
        if (head == nullptr || head->next == nullptr)
            return head;

        vector<int> result; // To store the node values
        
        // Step 1: Traverse the list and push values into vector
        ListNode* curr = head;
        while (curr != nullptr) {
            result.push_back(curr->val);
            curr = curr->next;
        }

        // Step 2: Sort the vector using built-in sort()
        sort(result.begin(), result.end());

        // Step 3: Rewrite sorted values back into the linked list
        curr = head;
        for (int val : result) {
            curr->val = val;   // replace node value
            curr = curr->next; // move to next node
        }

        // Return the head of the "sorted" linked list
        return head;
    }
};


// Optional: Helper functions for testing the code (not required in online judges)

// Function to insert a new node at the end of list
ListNode* insert(ListNode* head, int val) {
    if (head == nullptr)
        return new ListNode(val);

    ListNode* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = new ListNode(val);
    return head;
}

// Function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


// Driver code (for manual testing)
int main() {
    ListNode* head = nullptr;

    // Create list: 4 -> 2 -> 1 -> 3
    head = insert(head, 4);
    head = insert(head, 2);
    head = insert(head, 1);
    head = insert(head, 3);

    cout << "Original List: ";
    printList(head);

    Solution s;
    head = s.sortList(head);

    cout << "Sorted List:   ";
    printList(head);

    return 0;
}


// 2. Second Approach is by using Merge Sort on Linked List which is more optimal and doesn't require extra space for array.

/**
 * Definition for singly-linked list.
 * (This is the usual ListNode definition used in LeetCode problems.)
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

    // -----------------------
    // findMiddle
    // -----------------------
    // Purpose:
    //   Find (and return) a node that acts as the "middle" of the list.
    //   We will split the list at this node: left = head..middle, right = middle->next..
    //
    // Technique:
    //   Two-pointer method: slow moves by 1 step, fast moves by 2 steps.
    //   When fast reaches the end, slow is approximately in the middle.
    //
    // Note about `fast = head->next;`:
    //   You used `fast = head->next;` instead of `fast = head;`. That's valid.
    //   - With fast=head->next, for an even-length list the left half will have fewer nodes (it biases split to right).
    //   - With fast=head, left and right are more balanced (commonly used).
    //   Either choice still produces a correct merge-sort; it's just a small difference in how the list is split.
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;    // starting fast one step ahead -> slightly different split on even length

        // Move until fast runs out or only one step remains
        // Condition ensures we don't dereference null pointers.
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;                // move slow by one
            fast = fast -> next -> next;        // move fast by two
        }

        // slow now points to the middle (or the left-middle in even-size lists with current fast init)
        return slow;
    }

    // -----------------------
    // mergeTwoList
    // -----------------------
    // Purpose:
    //   Merge two sorted linked lists (list1 and list2) into a single sorted list
    //   and return the head of that merged list.
    //
    // Implementation details:
    // - Use a dummy node to simplify edge cases (empty resulting list, attach first node, etc).
    // - Walk through both lists, always pick the smaller node and append it to the merged list.
    // - After the loop, exactly one list (maybe none) still has nodes — attach the remainder.
    //
    // Notes:
    // - We reuse the existing nodes (no new nodes are allocated except the dummy).
    // - `temp = list1;` or `temp = list2;` is okay because we move temp afterwards; 
    //   an alternative common pattern is `temp = temp->next;` right after assigning `temp->next = ...`.
    ListNode* mergeTwoList(ListNode* list1, ListNode* list2) {
        // Dummy node simplifies logic: merged list will start at dummy->next
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;   // temp is the tail of the merged list

        // While both lists have nodes, pick the smaller head and append
        while(list1 != NULL && list2 != NULL) {
            if(list1 -> val < list2 -> val) {
                temp -> next = list1;   // attach list1's current node
                temp = list1;           // move tail to the attached node
                list1 = list1 -> next;  // advance list1
            }
            else {
                temp -> next = list2;   // attach list2's current node
                temp = list2;           // move tail to the attached node
                list2 = list2 -> next;  // advance list2
            }
        }

        // One list may still contain nodes — attach the whole remainder
        if(list1) {
            temp -> next = list1;
        }
        else {
            temp -> next = list2;
        }

        // head of merged list is dummyNode->next
        ListNode* mergedHead = dummyNode -> next;

        // Optional: you could delete(dummyNode) to free the tiny dummy allocation.
        // But do NOT delete nodes that are part of the merged result.
        // (If you delete dummyNode here, ensure you do it safely after saving mergedHead.)
        // For clarity in competitive programming we often ignore deleting dummy.

        return mergedHead;
    }

    // -----------------------
    // sortList (merge sort on linked list)
    // -----------------------
    // Purpose:
    //   Recursively sort the linked list using the divide-and-conquer merge sort algorithm.
    //
    // Steps:
    // 1. Base case: if 0 or 1 node -> already sorted
    // 2. Find middle -> split into left and right halves
    // 3. Recursively sort left and right
    // 4. Merge the sorted halves and return
    //
    // Complexity:
    //  Time:  O(n log n)  — each level does O(n) work, there are O(log n) levels
    //  Space: O(log n)    — recursion stack depth (not counting the small dummy allocation)
    //
    // Important base case detail:
    //  Use `if (head == NULL || head->next == NULL)` — using && is wrong because
    //  if head==NULL then accessing head->next is invalid.
    ListNode* sortList(ListNode* head) {
        // Base case: empty list or single node -> return as-is
        if(head == NULL || head -> next == NULL) {
            return head;
        }

        // Find middle node for splitting
        ListNode* middle = findMiddle(head);

        // Split: right starts at middle->next; left starts at head
        ListNode* right = middle -> next;
        ListNode* left = head;

        // Break the link so left is a proper list ending at middle
        middle -> next = NULL;

        // Recursively sort left and right halves
        left = sortList(left);
        right = sortList(right);

        // Merge the two sorted halves and return head of merged list
        return mergeTwoList(left, right);
    }
};
