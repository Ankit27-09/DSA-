// // 1. Approachh is the brute force approach 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            int sum = target - nums[i];
            for(int j = i + 1; j < nums.size(); j++) {
                if(sum == nums[j]) {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};

// 2. Approach is by doiing the map 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            int remaining = target - nums[i];
            if(! mp.count(remaining)) {
                mp[nums[i]] = i;
            }
            else {
                return {mp[remaining], i};
            }
         
        }
        return {};
    }
};