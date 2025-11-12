// Question Link ->  https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
   Problem: Longest Subarray with Sum = 0
   --------------------------------------
   Given an array of integers, find the length of the longest subarray whose elements sum to 0.

   Example:
   Input:  arr = {15, -2, 2, -8, 1, 7, 10, 23}
   Output: 5

   Explanation:
   The longest subarray with sum 0 is: [-2, 2, -8, 1, 7]
   (Indexes 1 to 5) → length = 5
*/

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // 'mp' will store prefix sum → first index where it occurred
        unordered_map<int, int> mp;

        int maxi = 0;  // stores length of longest subarray with sum 0
        int sum = 0;   // prefix sum variable

        // Traverse through the array
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];  // accumulate prefix sum

            // Case 1: if prefix sum becomes 0 → subarray from 0 to i has sum 0
            if (sum == 0) {
                maxi = i + 1;
            }
            // Case 2: if sum is already seen before
            // Then the subarray between previous index+1 and current index has sum 0
            else if (mp.find(sum) != mp.end()) {
                maxi = max(maxi, i - mp[sum]);
            }
            // Case 3: store prefix sum with index if first time seen
            else {
                mp[sum] = i;
            }
        }

        return maxi;  // return maximum length found
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example test case
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};

    Solution obj;
    int result = obj.maxLength(arr);

    cout << "Length of Longest Subarray with Sum 0: " << result << endl;

    return 0;
}

/*
   -------------------- DRY RUN --------------------

   Input: arr = {15, -2, 2, -8, 1, 7, 10, 23}

   i=0 → sum=15
       sum != 0, not in map → mp[15]=0

   i=1 → sum=13
       sum != 0, not in map → mp[13]=1

   i=2 → sum=15
       sum already in map at index 0
       length = i - mp[15] = 2 - 0 = 2
       maxi = 2

   i=3 → sum=7
       mp[7]=3

   i=4 → sum=8
       mp[8]=4

   i=5 → sum=15
       already in map at index 0
       length = 5 - 0 = 5
       maxi = 5

   i=6 → sum=25
       mp[25]=6

   i=7 → sum=48
       mp[48]=7

   Result: maxi = 5

   -------------------- OUTPUT --------------------
   Length of Longest Subarray with Sum 0: 5

   -------------------- COMPLEXITY ----------------
   Time:  O(N) → single traversal using hashmap
   Space: O(N) → for storing prefix sums in unordered_map
*/
