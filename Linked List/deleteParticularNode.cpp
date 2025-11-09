class Solution {
    public:
      // Delete node at position x (1-indexed) and return updated head
      Node* deleteNode(Node* head, int x) {
          if (!head) return head;  // Empty list
  
          if (x == 1) {  // Deleting head node
              Node* temp = head;
              head = head->next;
              delete temp;
              return head;
          }
  
          Node *curr = head, *prev = nullptr;
          x--;  // Adjust for 1-indexed list
          while(x-- && curr) {
              prev = curr;
              curr = curr->next;
          }
          if (!curr) return head;  // x out of bounds
  
          prev->next = curr->next;
          delete curr;
          return head;
      }
  };
  