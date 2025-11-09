// This approach would be O(N) and here we will use the two pointer approach 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        while(i < j) {
            if(nums[i] + nums[j] > target) {
                j--;
            }
            else if(nums[i] + nums[j] < target) {
                i++;

            }
            else {
                return {i + 1, j + 1};
            }
        }
        return{};
    }
};