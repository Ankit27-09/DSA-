// Question Link -> https://www.geeksforgeeks.org/problems/find-length-of-loop/1

#include <iostream> 
using namespace std;

/*
 Definition of the singly linked list node used by many competitive
 programming problems. It contains an integer data and a pointer to the next node.
*/
class Node {
public:
    int data;
    Node *next;

    // constructor for easy node creation
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

/*
 Solution class that contains the method lengthOfLoop.
 The function returns the length of the cycle (loop) in the linked list.
 If there is no cycle, it returns 0.
*/
class Solution {
public:
    /*
     lengthOfLoop:
     - Input: head pointer to the first node of a singly linked list.
     - Output: integer representing the number of nodes in the cycle.
               0 if the list has no cycle.

     Approach used: Floyd's Cycle Detection Algorithm (Tortoise and Hare).
     Steps:
       1. Use two pointers: slow (moves 1 step at a time) and fast (moves 2 steps at a time).
       2. If there is a cycle, the fast pointer will eventually meet the slow pointer inside the cycle.
       3. Once they meet, keep one pointer fixed and move the other around the cycle until it comes back,
          counting the nodes visited — that count is the cycle length.
       4. If fast reaches NULL (end of list), the list has no cycle -> return 0.
    */
    int lengthOfLoop(Node *head) {
        // Edge case: empty list or single node that doesn't form a self-loop
        if (head == nullptr) return 0;

        // Initialize both pointers to start of list
        Node* slow = head;
        Node* fast = head;

        // Move slow by 1 and fast by 2 steps until they either meet (cycle found)
        // or fast reaches the end (no cycle).
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;                // move slow by 1
            fast = fast->next->next;          // move fast by 2

            // If they meet, a cycle exists.
            if (fast == slow) {
                // Count the number of nodes in the cycle.
                int count = 1;                // start counting from 1 (slow->next)
                Node* temp = slow->next;      // start from the next node

                // Move temp until it returns to slow, incrementing count.
                // This traverses the whole cycle exactly once.
                while (temp != slow) {
                    count++;
                    temp = temp->next;
                }
                return count; // length of the loop
            }
        }

        // fast reached end of list -> no cycle
        return 0;
    }
};

/* --------------------------
   Additional notes & explanation
   --------------------------

1) Why Floyd's algorithm finds a cycle:
   - Think of slow advancing 1 step and fast 2 steps. If there is a cycle,
     the fast pointer gains 1 step on slow every time step (because 2-1 = 1).
     Inside the cycle, this means eventually fast will catch up to slow.

2) Why counting from slow->next works:
   - When fast == slow, both are at the same node inside the cycle.
   - To find cycle length we walk from that node around the loop until we return to it.
   - We can start from slow->next and count how many steps until we hit slow again;
     that gives the number of distinct nodes in the cycle.

3) Edge cases to consider:
   - Empty list (head == nullptr) -> function returns 0.
   - Single node that points to nullptr (no cycle) -> fast->next == nullptr triggers return 0.
   - Single node that points to itself (self-loop) -> slow == fast on first comparison after moves,
     and counting loop will produce 1.
   - Very large list: algorithm is O(n) and uses O(1) extra space, so it scales well.

4) Time complexity:
   - Detection phase (Floyd): O(n) — in the worst case we traverse the list a small constant
     number of times before detection or reaching the end.
   - Counting phase: O(k) where k is the size of the loop.
   - Overall: O(n) where n is number of nodes (k <= n).

5) Space complexity:
   - O(1) extra space (only a few pointers and counters are used).

6) Example walkthrough:
   - Consider list: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (cycle starts at node with value 3).
     Detection:
       slow path: 1,2,3,4,5,3,...
       fast path: 1,3,5,4,3,...
       They meet at node 3 (or some node in the cycle).
     Counting:
       From meeting node, traverse nodes in cycle: 3 -> 4 -> 5 -> 3. count = 3 -> return 3.

*/

int main() {
    // Example usage: create a list 1->2->3->4->5 and make 5->3 (cycle of length 3)
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // create cycle: node with value 5 points back to node with value 3
    head->next->next->next->next->next = head->next->next; // 5->3

    Solution sol;
    int loopLen = sol.lengthOfLoop(head);
    cout << "Length of loop: " << loopLen << "\n"; // expected output: 3

    // Note: we do not attempt to delete nodes here because of the cycle (would need careful cleanup).
    return 0;
}
