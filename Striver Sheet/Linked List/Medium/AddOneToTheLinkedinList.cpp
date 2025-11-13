// ✅ Problem: Add 1 to a number represented as a Linked List
// Example: 1 -> 9 -> 9 represents the number 199
// After adding 1, it should become 2 -> 0 -> 0 (i.e., 200)


#include <iostream>
#include <vector>
using namespace std;

// Structure of a node in the linked list
struct Node {
    int data;      // To store the digit
    Node* next;    // Pointer to the next node

    // Constructor to create a new node easily
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
public:
    // 🔁 Helper function to reverse a linked list using recursion
    Node* recursionReverse(Node* curr, Node* prev) {
        // Base case: when the list has been fully reversed
        // The 'prev' becomes the new head of the reversed list
        if (curr == NULL) {
            return prev;
        }

        // Save the next node before changing the link
        Node* nextNode = curr->next;

        // Reverse the link
        curr->next = prev;

        // Recursive call: move one step forward
        return recursionReverse(nextNode, curr);
    }

    // ➕ Main function to add one to the linked list number
    Node* addOne(Node* head) {
        // Edge case: if the list is empty, return a single node with 1
        if (!head) return new Node(1);

        // 🔹 Step 1: Reverse the linked list
        // We reverse because it’s easier to add from the least significant digit (end)
        Node* prev = NULL;
        Node* reversedHead = recursionReverse(head, prev);

        // 🔹 Step 2: Add 1 to the reversed list
        Node* temp = reversedHead;
        int carry = 1;  // Because we are adding one

        while (temp != NULL) {
            int sum = temp->data + carry;  // Add carry to current digit
            temp->data = sum % 10;         // Update current digit (0–9)
            carry = sum / 10;              // Compute new carry (either 0 or 1)

            // If no carry left, we can stop early
            if (carry == 0) break;

            // If we reach the end and still have a carry, add a new node
            if (temp->next == NULL && carry) {
                temp->next = new Node(carry);
                carry = 0;
                break;
            }

            // Move to the next node
            temp = temp->next;
        }

        // 🔹 Step 3: Reverse the list back to original order
        Node* resultHead = recursionReverse(reversedHead, NULL);

        // Return the new head
        return resultHead;
    }
};

// 🔍 Utility function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// 🔹 Helper function to create a linked list from a vector of digits
Node* createList(vector<int> digits) {
    if (digits.empty()) return NULL;
    Node* head = new Node(digits[0]);
    Node* temp = head;

    for (int i = 1; i < digits.size(); i++) {
        temp->next = new Node(digits[i]);
        temp = temp->next;
    }
    return head;
}

// 🧠 Example usage
int main() {
    // Example: list represents 1 -> 9 -> 9
    vector<int> digits = {1, 9, 9};
    Node* head = createList(digits);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    Node* result = obj.addOne(head);

    cout << "After Adding One: ";
    printList(result);

    return 0;
}
