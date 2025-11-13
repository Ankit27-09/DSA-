// Question Link -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Problem: Best Time to Buy and Sell Stock
// ---------------------------------------
// You are given an array 'prices' where prices[i] is the price of a given stock on the i-th day.
// You want to maximize your profit by choosing a single day to buy one stock
// and choosing a different day in the future to sell that stock.
//
// Return the maximum profit you can achieve from this transaction.
// If you cannot achieve any profit, return 0.
//
// Example:
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6).
// Profit = 6 - 1 = 5.

#include <iostream>
#include <vector> 
using namespace std;

// Define a Solution class as per LeetCode function signature convention
class Solution {
public:
    
    // Function to find the maximum profit from buying and selling one stock
    int maxProfit(vector<int>& prices) {
        // Variable to store the maximum profit found so far.
        // Initially, we assume profit is 0 because no transaction has been made yet.
        int maxProfit = 0;
        
        // Variable to store the lowest (best) price to buy so far.
        // Start by assuming the first day's price is the minimum.
        int bestBuy = prices[0];

        // Loop through the price list starting from the second day
        for(int i = 1; i < prices.size(); i++) {

            // If we find a price that is lower than our current 'bestBuy' price,
            // we update 'bestBuy' because it could be a better day to buy.
            if(bestBuy > prices[i]) {
                bestBuy = prices[i];
            }
            else {
                // Otherwise, we check if selling at today's price would give a better profit.
                // Calculate profit = current price - lowest price seen so far.
                // Compare with maxProfit and keep the larger value.
                maxProfit = max(maxProfit, prices[i] - bestBuy);
            }
        }

        // After traversing all days, maxProfit contains the maximum possible profit.
        return maxProfit;
    }
};

// ---------------------------
// Time & Space Complexity
// ---------------------------
// Time Complexity: O(n)
//   -> We go through the array once (single loop), so linear time.
// Space Complexity: O(1)
//   -> We only use a few extra variables (maxProfit and bestBuy), no extra data structures.
//
// ---------------------------
// Concept Recap / Intuition
// ---------------------------
// 1️⃣ The idea is to find the smallest price before each day (bestBuy).
// 2️⃣ On each day, calculate the profit if you sold today: prices[i] - bestBuy.
// 3️⃣ Keep track of the largest such profit (maxProfit).
// 4️⃣ If prices are always decreasing, no profit can be made, so the answer is 0.
//
// ---------------------------
// Example walkthrough
// ---------------------------
// Input: prices = [7, 1, 5, 3, 6, 4]
//
// Step-by-step:
// Day 1: price = 7, bestBuy = 7, maxProfit = 0
// Day 2: price = 1, bestBuy = 1 (found smaller), maxProfit = 0
// Day 3: price = 5, profit = 5 - 1 = 4, maxProfit = 4
// Day 4: price = 3, profit = 3 - 1 = 2, maxProfit = 4
// Day 5: price = 6, profit = 6 - 1 = 5, maxProfit = 5 (updated)
// Day 6: price = 4, profit = 4 - 1 = 3, maxProfit = 5
//
// Output: 5
//
// ---------------------------
// Edge Cases to Remember
// ---------------------------
// ✅ Only one price (prices.size() == 1) → return 0 (can't sell)
// ✅ Prices always decreasing (e.g., [7,6,4,3,1]) → return 0
// ✅ All prices equal (e.g., [3,3,3]) → return 0
// ✅ Large input (up to 10^5 elements) → efficient due to O(n)
//
// ---------------------------
// Note:
// ---------------------------
// ❌ Don't use nested loops for comparing every buy-sell pair → O(n^2) → too slow.
// ✅ Use this single-pass greedy approach for optimal performance.
//
