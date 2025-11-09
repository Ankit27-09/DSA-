class Solution {
public:
    vector<vector<int>> result;
    void twoSum(vector<int>& nums, int target, int i, int j) {
        while(i < j) {
            if(nums[i] + nums[j] > target) {
            j--;
            }
            else if(nums[i] + nums[j] < target) {
                i++;
            }
            else {
                while(i < j && nums[i] == nums[i + 1]) {
                    i++;
                }
                while(i < j && nums[j] == nums[j - 1]) {
                    j--;
                }
                result.push_back({-target, nums[i], nums[j]});
                i++;
                j--;
            }
        }
        
}
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 1. do Sorting because we are pushing the elements not the index 
        // 2. avoiid the duplicates
        // 3. avoid the fixed n1 also 
        // n1 + n2 + n3 = 0;
        // make it like n2 + n3 = -(n1);
        int n = nums.size();
        sort(nums.begin(), nums.end()); // step 1: sort

        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int n1 = nums[i];
            int target = -n1;
            twoSum(nums, target, i + 1, n - 1);
        }
    return result;
    }
};