class Solution {
  public:
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& nums) {
       int n = nums.size();
       
       // If the array is empty, return 0 (no sequence possible).
       if(n == 0) {
           return 0;
       }
       
       // Variable to store the maximum length found.
       int longest = 1;
       
       // Step 1: Insert all numbers into an unordered_set.
       // Why? Because set gives O(1) average time for search operations,
       // and also removes duplicates automatically.
       unordered_set<int> st;
       for(int i = 0; i < n; i++) {
           st.insert(nums[i]);
       }
       
       // Step 2: Traverse through the set elements.
       for(auto it: st) {
           
           // Check if "it" can be the **starting point of a sequence**.
           // A number can only be a starting point if (it - 1) does NOT exist.
           // Example: For sequence [1,2,3,4],
           // only '1' is the starting point, because (1-1=0) is not in the set.
           if(st.find(it - 1) == st.end()) {
               
               int count = 1;  // Current sequence length
               int x = it;     // Current number
               
               // Step 3: Expand the sequence from 'it'.
               // Keep checking if (x+1) exists in the set.
               while(st.find(x + 1) != st.end()) {
                   x = x + 1;   // Move to the next number
                   count++;     // Increase sequence length
               }
               
               // Update the longest sequence length found so far.
               longest = max(longest, count);
           }
       }
       
       // Step 4: Return the final answer
       return longest;
    }
};
