// concept of slow and fast pointer
// The slow pointer moves one step at a time while the fast pointer moves two steps at a time.
// When the fast pointer reaches the end of the linked list, the slow pointer will be at the middle of the linked list.
//  The slow pointer is at the middle of the linked list.
//  The fast pointer is at the end of the linked list.      

class Solution {
    public:
        ListNode* middleNode(ListNode* head) {
            ListNode* slow = head; 
            ListNode* fast = head;
    
            while(fast != NULL && fast -> next != NULL) {
                slow = slow -> next;
                fast = fast -> next -> next;
            }
            return slow;
        }
    };