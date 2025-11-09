// Question Link -> https://leetcode.com/problems/3sum/description/

// Brute force approach 
// Time complexity ->  O(n^3 * log(m))  where n is size of input array and m is number of unique triplets
// Space complexity -> O(m)  where m is number of unique triplets

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
  Problem: 3Sum
  Goal: Find all unique triplets (nums[i], nums[j], nums[k]) such that:
        nums[i] + nums[j] + nums[k] == 0

  Approach: Brute Force (O(n³))
  --------------------------------
  1. We use three nested loops (i, j, k) to generate all possible triplets.
  2. For every triplet, check if the sum == 0.
  3. If yes, store the sorted triplet into a set (to remove duplicates).
  4. Finally, return all unique triplets as a vector of vectors.

  Complexity:
    → Time  : O(n³) — because of 3 nested loops.
    → Space : O(m)  — where m is number of unique triplets stored in the set.

  This is the simplest possible correct solution,
  though not efficient for large input (used mainly for understanding).
*/

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> s;       // To automatically handle duplicate triplets
    vector<vector<int>> ans;  // To store the final list of triplets

    // Generate all possible triplets using 3 nested loops
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                // Check if the current triplet sums to zero
                if (nums[i] + nums[j] + nums[k] == 0) {
                    // Create a vector for the triplet
                    vector<int> trip = {nums[i], nums[j], nums[k]};

                    // Sort the triplet to ensure order consistency
                    // (e.g., [-1, 0, 1] and [0, -1, 1] are treated the same)
                    sort(trip.begin(), trip.end());

                    // If this sorted triplet is not already in the set, insert it
                    if (s.find(trip) == s.end()) {
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                }
            }
        }
    }

    return ans;  // Return the list of all unique triplets
}

// Utility function to print the resulting triplets neatly
void printTriplets(const vector<vector<int>>& triplets) {
    cout << "[\n";
    for (auto trip : triplets) {
        cout << "  [";
        for (int i = 0; i < trip.size(); i++) {
            cout << trip[i];
            if (i < trip.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    cout << "]\n";
}

int main() {
    // Example input array
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    // Call the brute-force threeSum function
    vector<vector<int>> result = threeSum(nums);

    // Print the output triplets
    cout << "All unique triplets with sum 0 (Brute Force):\n";
    printTriplets(result);

    return 0;
}

// 2 Better Approach using hashing 
// Time complexity -> O(n^2 * log(m))  where n is size of input array and m is number of unique triplets
// Space complexity -> O(m)  where m is number of unique triplets

#include <iostream>
using namespace std;
#include <vector>
#include <set>

/*
  Problem: 3Sum
  -------------------------------------------------
  Given an array nums, find all unique triplets [a, b, c] such that:
      a + b + c == 0

  Approach: Hash Set (O(n²))
  -------------------------------------------------
  - Fix one element (nums[i]) in the outer loop.
  - Use an unordered_set (hash set) to find the remaining two numbers whose sum = -nums[i].
  - For each i, run a loop for j = i+1...n-1:
      → Let 'target' = -nums[i].
      → For each nums[j], compute required third = target - nums[j].
      → If 'third' is already in the set, we found a valid triplet.
  - Use a set<vector<int>> to store unique triplets (avoid duplicates).
  - Sort each triplet before inserting (so [1, -1, 0] and [-1, 0, 1] are treated same).

  Time Complexity:  O(n²)
  Space Complexity: O(n) (for the hash set and storage)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> uniqueTriplets;  // to store only unique combinations

        // Outer loop: fix one number at a time
        for (int i = 0; i < n; i++) {
            int target = -nums[i];       // We need a pair that sums to 'target'
            set<int> seen;     // Hash set to store numbers we have seen so far

            // Inner loop: find pairs (nums[j], third) such that nums[j] + third == target
            for (int j = i + 1; j < n; j++) {
                int third = target - nums[j]; // This is the number needed to complete triplet

                // If we have already seen 'third', it means nums[i] + nums[j] + third == 0
                if (seen.find(third) != seen.end()) {
                    vector<int> trip = {nums[i], nums[j], third};

                    // Sort triplet to maintain order and allow duplicate detection
                    sort(trip.begin(), trip.end());

                    // Insert into set to avoid duplicates
                    uniqueTriplets.insert(trip);
                }

                // Add current number to hash set for future lookups
                seen.insert(nums[j]);
            }
        }

        // Convert the set into a vector (required return type)
        vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
        return ans;
    }
};


// ---------- Utility Function for Testing ----------
void printTriplets(const vector<vector<int>>& triplets) {
    cout << "[\n";
    for (auto& t : triplets) {
        cout << "  [";
        for (int i = 0; i < t.size(); i++) {
            cout << t[i];
            if (i < t.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    cout << "]\n";
}


// ---------- Driver Code ----------
int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    Solution sol;
    vector<vector<int>> result = sol.threeSum(nums);

    cout << "Unique Triplets that sum to 0 (Hash Set approach):\n";
    printTriplets(result);

    return 0;
}


// Optimal Approach 

#include <iostream>
#include <vector>
using namespace std;

/*
  Problem: 3Sum
  --------------------------------------------------
  Given an integer array nums, return all unique triplets [a, b, c]
  such that a + b + c == 0.

  Approach: Sorting + Two Pointer
  --------------------------------------------------
  1️⃣ Sort the array.
  2️⃣ Fix one element nums[i] in each iteration.
  3️⃣ Use two pointers (j and k) to find pairs in the remaining array
      such that nums[i] + nums[j] + nums[k] == 0.
  4️⃣ Move pointers smartly based on sum comparison.
  5️⃣ Skip duplicates to avoid repeating the same triplet.

  Complexity:
    → Time  : O(n²)
    → Space : O(1) (not counting output vector)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // Step 2: Fix the first element one by one
        for (int i = 0; i < n; i++) {

            // Skip duplicates for the first element
            // Example: nums = [-1, -1, 0, 1]
            // If we already used the first -1, skip the next -1
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Step 3: Initialize two pointers
            int j = i + 1;       // start just after i
            int k = n - 1;       // start from end of array

            // Step 4: Move j and k toward each other
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                // If sum < 0, we need a bigger number → move j forward
                if (sum < 0)
                    j++;

                // If sum > 0, we need a smaller number → move k backward
                else if (sum > 0)
                    k--;

                // Found a valid triplet
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});

                    // Move both pointers inward
                    j++;
                    k--;

                    // Skip duplicates for the second element (nums[j])
                    while (j < k && nums[j] == nums[j - 1])
                        j++;

                    // Optional: You can also skip duplicates for nums[k]
                    // while (j < k && nums[k] == nums[k + 1])
                    //     k--;
                }
            }
        }

        return ans;
    }
};


// ---------- Utility Function for Output ----------
void printTriplets(const vector<vector<int>>& triplets) {
    cout << "[\n";
    for (auto& t : triplets) {
        cout << "  [";
        for (int i = 0; i < t.size(); i++) {
            cout << t[i];
            if (i < t.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    cout << "]\n";
}


// ---------- Driver Code ----------
int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    Solution sol;
    vector<vector<int>> result = sol.threeSum(nums);

    cout << "Unique Triplets that sum to 0 (Two-Pointer Approach):\n";
    printTriplets(result);

    return 0;
}
