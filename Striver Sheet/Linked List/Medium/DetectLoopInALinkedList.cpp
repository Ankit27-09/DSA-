// Question Link -> https://leetcode.com/problems/linked-list-cycle/description/

// Using Hash Map Function 
#include <iostream>
#include <unordered_map>
using namespace std;

/*
 * Definition for singly-linked list.
 * A simple linked list node structure used in LeetCode problems.
 */
struct ListNode {
    int val;            // Value stored in node
    ListNode *next;     // Pointer to next node

    // Constructor
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /*
     * Function: hasCycle
     * Purpose : Check if a linked list contains a cycle
     * Approach: Using unordered_map to track visited nodes
     *
     * Time Complexity: O(N)
     * Space Complexity: O(N)
     *
     * Logic:
     * - Traverse the list.
     * - Store each visited node's address in a hash map.
     * - If a node is already present in the map, cycle exists.
     */
    bool hasCycle(ListNode *head) {

        // Base cases: If list is empty OR only 1 node -> no cycle possible
        if (head == NULL || head->next == NULL) {
            return false;
        }

        // Hash map to store visited node addresses
        unordered_map<ListNode*, int> mpp;

        // Start traversing from head
        ListNode* temp = head;

        while (temp != NULL) {

            // If node already exists in map -> cycle detected
            if (mpp.find(temp) != mpp.end()) {
                return true;
            }

            // Mark current node as visited
            mpp[temp] = 1;

            // Move to next node
            temp = temp->next;
        }

        // Reached NULL -> no cycle
        return false;
    }
};

int main() {

    // ----------- Creating a sample linked list ----------
    // Example linked list: 1 -> 2 -> 3 -> 4 -> NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // ----------- Making a cycle manually for testing ----------
    // Let's say we connect node 4 -> node 2 to form a cycle
    head->next->next->next->next = head->next; // cycle created

    // Create solution object
    Solution sol;

    // Check if cycle exists
    if (sol.hasCycle(head)) {
        cout << "Cycle detected in linked list!" << endl;
    } else {
        cout << "No cycle in linked list!" << endl;
    }

    return 0;
}


// using the Torotise and Hare Algorithm to detect the loop in a linked list

/* Floyd’s Cycle Detection (Tortoise & Hare) — Intuition

Imagine two people running on a circular track:

Tortoise (slow pointer) → moves 1 step at a time

Hare (fast pointer) → moves 2 steps at a time

❗ Key Logic

If there is no cycle, fast pointer will reach NULL and stop.

If there is a cycle, fast pointer will eventually “lap” the slow pointer and they will meet inside the cycle.

That meeting point confirms a cycle exists.

🧠 Why does this always work?

Because when both are inside the cycle:

Hare moves twice as fast → it keeps gaining 1 node on the slow pointer each step.

Eventually, this gain makes the hare land exactly on the slow pointer.

This is like two people running around a circular track at different speeds — they MUST meet. */

#include <bits/stdc++.h>
using namespace std;

/*
 * Definition of a linked list node.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    /*
     * Function : hasCycle
     * Purpose  : Detect whether a linked list contains a cycle.
     * Method   : Floyd’s Cycle Detection (Tortoise and Hare)
     *
     * Time Complexity : O(N)
     * Space Complexity: O(1)  -> Best possible
     */
    bool hasCycle(ListNode *head) {

        // Base cases: empty list or single node -> no cycle
        if (head == NULL || head->next == NULL) {
            return false;
        }

        // slow = moves 1 step
        // fast = moves 2 steps
        ListNode* slow = head;
        ListNode* fast = head;

        /*
         * Loop runs until fast or fast->next becomes NULL
         * because at that point, we reached the end of the list -> no cycle.
         */
        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;          // move slow pointer by 1 step
            fast = fast->next->next;    // move fast pointer by 2 steps

            // If at any point slow == fast, cycle exists
            if (slow == fast) {
                return true;
            }
        }

        // If fast reaches NULL -> no cycle
        return false;
    }
};

int main() {

    // -------- Creating a test linked list ----------
    // Example: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // ----- Create a cycle manually for testing -----
    // Connecting node 4 -> node 2
    head->next->next->next->next = head->next;

    Solution sol;

    if (sol.hasCycle(head)) {
        cout << "Cycle detected using Floyd's Algorithm!" << endl;
    } else {
        cout << "No cycle found!" << endl;
    }

    return 0;
}
