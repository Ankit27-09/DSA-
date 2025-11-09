#include <bits/stdc++.h>
using namespace std;

/*
  Problem: Min and Max Candy Cost

  You are given:
    - An array `prices[]`, where each element is the cost of a candy.
    - An integer `k` which represents the offer:
        "Buy 1 candy, get up to k candies for free."

  Goal:
    1. Find the minimum money you must spend to buy all candies.
       -> Strategy: Always buy the cheapest candies first.
          Because each time you buy 1 cheap candy, you can skip paying
          for k of the most expensive ones.
    2. Find the maximum money you may spend.
       -> Strategy: Always buy the most expensive candies first.
          Because each time you buy 1 expensive candy, you can skip paying
          for k of the cheapest ones.

  Approach:
    - For minimum cost:
        Sort the prices in ascending order.
        Use two pointers (i for cheapest, j for costliest).
        Repeatedly:
          * Buy candy at index i (cheapest).
          * Move i forward.
          * Skip k costliest candies by moving j backward by k.
    - For maximum cost:
        Sort the prices in descending order.
        Again use two pointers (i for costliest, j for cheapest).
        Repeatedly:
          * Buy candy at index i (costliest).
          * Move i forward.
          * Skip k cheapest candies by moving j backward by k.

  Complexity:
    - Sorting takes O(n log n).
    - The two-pointer loop runs O(n).
    - Total: O(n log n).
    - Space: O(1) extra.
*/

class Solution {
  public:
    // Function to calculate minimum cost
    int minimumAmount(vector<int>& prices, int k) {
        // Step 1: Sort in ascending order
        sort(prices.begin(), prices.end());

        int i = 0;                 // pointer to the cheapest candy
        int j = prices.size() - 1; // pointer to the costliest candy
        int minCost = 0;

        // Step 2: Buy cheapest, skip k costliest
        while (i <= j) {
            minCost += prices[i];  // buy cheapest candy
            i++;                   // move to next cheapest
            j -= k;                // skip k costliest
        }

        return minCost;
    }
    
    // Function to calculate maximum cost
    int maximumAmount(vector<int>& prices, int k) {
        // Step 1: Sort in descending order
        sort(prices.begin(), prices.end(), greater<int>());

        int i = 0;                 // pointer to the costliest candy
        int j = prices.size() - 1; // pointer to the cheapest candy
        int maxCost = 0;

        // Step 2: Buy costliest, skip k cheapest
        while (i <= j) {
            maxCost += prices[i];  // buy costliest candy
            i++;                   // move to next costliest
            j -= k;                // skip k cheapest
        }

        return maxCost;
    }
    
    // Function to return both minimum and maximum costs
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        vector<int> ans;
        ans.push_back(minimumAmount(prices, k)); // first element = minimum cost
        ans.push_back(maximumAmount(prices, k)); // second element = maximum cost
        return ans;
    }
};

int main() {
    Solution sol;

    // Example usage
    vector<int> prices = {3, 2, 1, 4};
    int k = 2;

    vector<int> result = sol.minMaxCandy(prices, k);

    cout << "Minimum cost: " << result[0] << endl; // Expected 3
    cout << "Maximum cost: " << result[1] << endl; // Expected 7

    return 0;
}
