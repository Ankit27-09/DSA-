class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // start' is the maximum element in nums
        // Because at least one subarray must contain the largest element.
        int start = *max_element(nums.begin(), nums.end());

        // 'end' is the total sum of nums
        // Because in the worst case, only 1 subarray is used (k = 1).
        int end = accumulate(nums.begin(), nums.end(), 0);

        int ans = 0;

        // Binary search between [start, end]
        // The goal is to minimize the maximum subarray sum.
        while (start <= end) {
            int mid = start + (end - start) / 2; // Proposed maximum subarray sum

            int count = 1; // number of subarrays formed
            int sub = 0;   // current subarray sum

            // Try splitting nums into subarrays
            for (int i = 0; i < nums.size(); i++) {
                sub += nums[i];

                // If subarray sum exceeds mid → make a new subarray
                if (sub > mid) {
                    count++;       // Increase subarray count
                    sub = nums[i]; // Start new subarray with current element
                }
            }

            // If the number of subarrays needed <= k,
            // it means mid is a valid maximum sum → try to minimize further
            if (count <= k) {
                ans = mid;       // store the possible answer
                end = mid - 1;   // try smaller value
            }
            // If more than k subarrays are needed,
            // mid is too small → increase the allowed sum
            else {
                start = mid + 1;
            }
        }

        //  Return the minimized maximum subarray sum
        return ans;
    }
};