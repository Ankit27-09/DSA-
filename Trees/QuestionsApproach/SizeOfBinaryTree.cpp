// Size of binary Tree

// Method 1 in which we first increase the count as we first start from the root node and then
// we travsersal left and thrn go to right;

// class Solution {
//   public:
    
//     void totalNodes(Node* root,int &count) {
//         if(root == NULL) {
//             return;
//         }
//         count++;
//         totalNodes(root -> left, count);
//         totalNodes(root -> right, count);
//     }
//     int getSize(Node* root) {
//         // code here
//         int count = 0;
//         totalNodes(root, count);
//         return count;
//     }
// };

// Second Method
// first count the left subtree nodes and then right and then add one for the root node 


class Solution {
    public:
    
    int getSize(Node* root) {
        if(root == NULL) {
        return 0;
    }
        return(1+ getSize(root -> left) + getSize(root -> right));
        
    }
      
   };
  