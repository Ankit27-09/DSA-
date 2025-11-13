// Question Link -> https://leetcode.com/problems/linked-list-cycle-ii/description/

#include <iostream>
#include <unordered_map>
using namespace std;

/*
 * Definition for singly-linked list node.
 * Matches common LeetCode style.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/*
 * Solution class containing detectCycle using an unordered_map
 * The function returns a pointer to the node where the cycle begins.
 * If there is no cycle, it returns nullptr.
 */
class Solution {
public:
    /*
     * detectCycle (hash map approach)
     *
     * Idea:
     * - Traverse the linked list and record each node's address
     *   in an unordered_map (or unordered_set would also work).
     * - Before inserting a node, check whether it's already present.
     *   If yes, that node is the start of the cycle (first repeated node).
     *
     * Time Complexity : O(N) — we visit each node at most once.
     * Space Complexity: O(N) — we store each visited node's address.
     */
    ListNode *detectCycle(ListNode *head) {
        // Map to store visited nodes (address -> 1)
        unordered_map<ListNode*, int> mp;

        ListNode* temp = head;
        while (temp != nullptr) {
            // If temp already exists in map, we've found the cycle entry
            if (mp.find(temp) != mp.end()) {
                return temp;
            }
            // Mark current node as visited
            mp[temp] = 1;
            // Move to next node
            temp = temp->next;
        }
        // Reached end -> no cycle
        return nullptr;
    }
};

/* ---------- Helper functions to build & test lists ---------- */

// Utility: print first few nodes (safe printing to avoid infinite loop)
void printListSafe(ListNode* head, int limit = 20) {
    ListNode* cur = head;
    int count = 0;
    while (cur != nullptr && count < limit) {
        cout << cur->val << " -> ";
        cur = cur->next;
        ++count;
    }
    if (cur != nullptr) cout << "... (continues)\n";
    else cout << "NULL\n";
}

// Utility: free nodes of a non-cyclic list
void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    // ------------------- Test 1: No cycle -------------------
    // List: 1 -> 2 -> 3 -> 4 -> NULL
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);

    Solution sol;
    ListNode* ans1 = sol.detectCycle(head1);

    cout << "Test 1 (no cycle): ";
    if (ans1 == nullptr) cout << "No cycle detected.\n";
    else cout << "Cycle detected at node with value: " << ans1->val << "\n";

    // Clean up (safe because list1 is acyclic)
    freeList(head1);

    // ------------------- Test 2: With cycle -------------------
    // Create list: 10 -> 20 -> 30 -> 40 -> 50
    // Then create cycle by pointing 50->30 (cycle starts at node with value 30)
    ListNode* head2 = new ListNode(10);
    head2->next = new ListNode(20);
    head2->next->next = new ListNode(30);
    head2->next->next->next = new ListNode(40);
    head2->next->next->next->next = new ListNode(50);

    // Keep pointer to node where cycle should start (30)
    ListNode* cycleStart = head2->next->next; // node with val 30

    // Make cycle: last node -> cycleStart
    ListNode* tail = head2;
    while (tail->next != nullptr) tail = tail->next;
    tail->next = cycleStart; // creates cycle

    // We won't attempt to free head2 because it contains a cycle;
    // deleting nodes safely requires breaking the cycle first.

    ListNode* ans2 = sol.detectCycle(head2);
    cout << "Test 2 (with cycle): ";
    if (ans2 == nullptr) cout << "No cycle detected.\n";
    else cout << "Cycle detected at node with value: " << ans2->val << "\n";

    // Optional: break the cycle and free memory
    // To free, find tail and set tail->next = nullptr, then free.
    tail->next = nullptr;
    freeList(head2);

    return 0;
}


// Optimised Approach using Floyd's Cycle Detection Algorithm(Tortoise and Hare Algorithm)

#include <iostream>
using namespace std;

/*
 * Standard singly-linked list node definition.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    /*
     * detectCycle:
     * Returns the node where the cycle begins.
     * If there is no cycle, returns NULL.
     *
     * Uses Floyd's Cycle Detection Algorithm:
     * 1) Use slow & fast pointers to detect cycle.
     * 2) If cycle found, move slow to head and
     *    move both slow and fast one step at a time.
     * 3) The point where they meet again is the cycle start.
     */
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        // PHASE 1 — Detect cycle
        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;          // moves 1 step
            fast = fast->next->next;    // moves 2 steps

            // Cycle detected when both pointers meet
            if (slow == fast) {

                // PHASE 2 — Find the cycle entry point
                slow = head;  // move slow to head

                /*
                 * Move both slow and fast one step at a time.
                 * They will meet at the cycle start node.
                 */
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;  // meeting point == cycle start
            }
        }

        // No cycle
        return NULL;
    }
};


/* ------------------- MAIN FUNCTION FOR TESTING ------------------- */
int main() {

    // Creating a list: 3 -> 2 -> 0 -> -4
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Creating a cycle: tail connects to node with value 2
    head->next->next->next->next = head->next; // cycle starts at 2

    Solution sol;
    ListNode* cycleStart = sol.detectCycle(head);

    if (cycleStart) {
        cout << "Cycle starts at node with value: " 
             << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
