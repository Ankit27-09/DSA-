// To optimised the space complexity, we can use the iterative approach using queue.
// The time complexity of the iterative approach is O(n) and the space complexity is O(n).                                 

// Level order Tranversal we have to return the vector of vector ans 

class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
    
     // Edge case: If the tree is empty
            if (root == NULL) return {};
    
            queue<TreeNode*> q;
            q.push(root);
            vector<vector<int>> ans; // Fix: Store levels instead of a single vector
    
            while(!q.empty()) {
                vector<int> level;
                int size = q.size();
    
                for(int i = 0; i < size; i++) {
                    TreeNode* temp = q.front();
                    q.pop();
                    level.push_back(temp -> val);
    
                    if(temp -> left) {
                        q.push(temp -> left);
                    }
                    if(temp -> right) {
                        q.push( temp -> right);
                    }
                
                }
                ans.push_back(level);
            }
            return ans;
        }
    };