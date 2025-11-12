
// Optimised Approach  Taking O(N) Time and O(1) Space

#include <iostream>
#include <vector>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};

class Solution {
  public:
    // Function to find all pairs of nodes whose sum equals the target
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) { 
        vector<pair<int, int>> result;  // To store valid pairs
        
        // Edge case: if the list is empty or has one node
        if (head == nullptr || head->next == nullptr)
            return result;

        // Step 1️⃣: Initialize two pointers
        Node* left = head;      // Start from the beginning
        Node* right = head;     // Start from head and move to last node
        
        // Move 'right' pointer to the tail (last node)
        while (right->next != nullptr) {
            right = right->next;
        }

        // Step 2️⃣: Use two-pointer technique to find pairs
        while (left != right && right->next != left) {
            int sum = left->data + right->data;

            // Case 1: Found a valid pair
            if (sum == target) {
                result.push_back({left->data, right->data});

                // Move both pointers inward
                left = left->next;
                right = right->prev;
            }
            // Case 2: Sum is smaller than target → move 'left' forward
            else if (sum < target) {
                left = left->next;
            }
            // Case 3: Sum is larger than target → move 'right' backward
            else {
                right = right->prev;
            }
        }

        return result; // Return all valid pairs
    }
};

//
// -------- Utility Functions --------
//

// Function to insert node at end of DLL
void insertEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to print all pairs
void printPairs(const vector<pair<int, int>>& pairs) {
    if (pairs.empty()) {
        cout << "No pairs found!\n";
        return;
    }
    for (auto p : pairs)
        cout << "(" << p.first << ", " << p.second << ") ";
    cout << endl;
}

// -------- Driver Code --------
int main() {
    Node* head = nullptr;

    // Create a sorted doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);
    insertEnd(head, 6);
    insertEnd(head, 8);
    insertEnd(head, 9);

    int target = 7;  // Target sum to find

    Solution obj;
    vector<pair<int, int>> ans = obj.findPairsWithGivenSum(head, target);

    cout << "Pairs with sum " << target << ": ";
    printPairs(ans);

    /*
        🔹 Dry Run Example:
        Doubly Linked List: 1 2 3 4 5 6 8 9
        Target = 7

        Step-by-step:
        left=1, right=9 → 10 > 7 → move right backward
        left=1, right=8 → 9 > 7 → move right backward
        left=1, right=6 → 7 ✅ store (1,6)
        left=2, right=5 → 7 ✅ store (2,5)
        left=3, right=4 → 7 ✅ store (3,4)
        Stop when left and right meet

        ✅ Output: (1,6) (2,5) (3,4)
    */

    return 0;
}

// Brute Force Approach Taking O(N^2) Time
#include <iostream>
#include <vector>
using namespace std;

//
// ----------------------------
//  DOUBLY LINKED LIST STRUCTURE
// ----------------------------
//
struct Node {
    int val;     // Stores data of each node
    Node* next;  // Pointer to next node
    Node* prev;  // Pointer to previous node

    // Constructor to create a new node
    Node(int x) {
        val = x;
        next = prev = nullptr;  // Initially no links
    }
};

//
// ----------------------------
//  SOLUTION CLASS
// ----------------------------
//
class Solution {
  public:
    /*
        Function Name : findPairsWithGivenSum
        -------------------------------------
        Goal:
            Find all pairs of nodes in the doubly linked list whose
            data values add up to the given target sum.

        Input:
            head   -> pointer to the first node of the DLL
            target -> integer sum we are searching for

        Output:
            vector<pair<int, int>> -> list of all value pairs that sum up to 'target'

        Approach:
            - Use a brute-force nested loop.
            - For each node (temp1), traverse all nodes after it (temp2).
            - Check if temp1->val + temp2->val == target.
            - If true, store that pair in a vector.
            - Continue until all pairs are checked.
    */
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {

        Node* temp1 = head;                 // Outer pointer starts from head
        vector<pair<int, int>> result;      // Vector to store all valid pairs

        // Outer loop: pick the first node (temp1)
        while (temp1 != nullptr) {

            Node* temp2 = temp1->next;      // Inner pointer starts from node after temp1

            // Inner loop: check each subsequent node (temp2)
            while (temp2 != nullptr) {

                // Compute the sum of values at temp1 and temp2
                int sum = temp1->val + temp2->val;

                // If sum matches the target, store the pair in the result vector
                if (sum == target) {
                    result.push_back({temp1->val, temp2->val});
                }

                // Move temp2 one step forward
                temp2 = temp2->next;
            }

            // Move temp1 one step forward
            temp1 = temp1->next;
        }

        // After traversing all pairs, return the result vector
        return result;
    }
};

//
// ----------------------------
//  HELPER / UTILITY FUNCTIONS
// ----------------------------
//

// Function to insert a new node at the end of a doubly linked list
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);  // Create a new node

    // Case 1: List is empty
    if (!head) {
        head = newNode;
        return;
    }

    // Case 2: Traverse to the end of the list
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    // Link the new node at the end
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to print all pairs stored in the vector
void printPairs(const vector<pair<int, int>>& pairs) {
    if (pairs.empty()) {
        cout << "No pairs found!" << endl;
        return;
    }

    for (auto p : pairs)
        cout << "(" << p.first << ", " << p.second << ") ";
    cout << endl;
}

//
// ----------------------------
//  DRIVER FUNCTION (MAIN)
// ----------------------------
//
int main() {
    Node* head = nullptr;  // Start with an empty list

    // Create a sorted doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> 7
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);
    insertEnd(head, 6);
    insertEnd(head, 7);

    // Target sum to find
    int target = 8;

    // Create Solution object and call the function
    Solution obj;
    vector<pair<int, int>> ans = obj.findPairsWithGivenSum(head, target);

    // Display the result
    cout << "Pairs with sum " << target << ": ";
    printPairs(ans);

    /*
        ----------------------------------------------------------
        🔹 DRY RUN EXAMPLE
        ----------------------------------------------------------
        List:   1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> 7
        Target: 8

        Outer loop (temp1): 1
            Inner loop (temp2): checks 2→3→4→5→6→7
            Found (1,7)

        Outer loop (temp1): 2
            Inner loop (temp2): checks 3→4→5→6→7
            Found (2,6)

        Outer loop (temp1): 3
            Inner loop (temp2): checks 4→5→6→7
            Found (3,5)

        Outer loop (temp1): 4
            Inner loop (temp2): checks 5→6→7
            (4,4) not valid, skip rest

        ✅ Final pairs stored in vector:
            (1,7), (2,6), (3,5)
    */

    return 0;
}

//
// ----------------------------
//  OUTPUT
// ----------------------------
//
// Pairs with sum 8: (1, 7) (2, 6) (3, 5)
//
// ----------------------------
//  COMPLEXITY ANALYSIS
// ----------------------------
//
// 🔸 Time Complexity  : O(n²)
//     Because for every node (temp1), we check all nodes after it (temp2).
//     So if the list has n nodes → total iterations ≈ n*(n-1)/2.
//
// 🔸 Space Complexity : O(1)
//     We’re not using any extra data structure except the result vector.
//
// 🔸 Advantage
//     - Simple to implement and understand.
//     - Works even if the list is not sorted.
//
// 🔸 Limitation
//     - Inefficient for very long lists (because of nested loops).
//
