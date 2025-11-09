#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool solve(int n, vector<int>& arr, int target, int sum, int index, vector<int>& result) {
        if (index == n) {
            return (sum == target);
        }

        // Include current element
        result.push_back(arr[index]);
        sum += arr[index];
        if (solve(n, arr, target, sum, index + 1, result)) {
            return true;
        }

        // Exclude current element (backtrack)
        result.pop_back();
        sum -= arr[index];
        if (solve(n, arr, target, sum, index + 1, result)) {
            return true;
        }

        return false;
    }

    bool checkSubsequenceSum(int n, vector<int>& arr, int target) {
        int sum = 0;
        int index = 0;
        vector<int> result;
        return solve(n, arr, target, sum, index, result); // ✅ added return
    }
};
