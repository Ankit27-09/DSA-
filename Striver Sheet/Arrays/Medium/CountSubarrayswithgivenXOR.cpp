// Question Link -> https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long subarrayXor(vector<int> &arr, int k) {
        long count = 0;  // total count of subarrays
        int n = arr.size();

        // Outer loop for starting index
        for (int i = 0; i < n; i++) {

            // Middle loop for ending index
            for (int j = i; j < n; j++) {
                int xxor = 0;  // reset XOR for each subarray (i...j)

                // Inner loop: compute XOR of subarray arr[i...j]
                for (int kk = i; kk <= j; kk++) { 
                    xxor = xxor ^ arr[kk];
                }

                // Now check after full subarray XOR is done
                if (xxor == k) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example test case
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;

    Solution sol;
    long result = sol.subarrayXor(arr, k);
    cout << "Number of subarrays with XOR " << k << " is: " << result << endl;

    return 0;
}

// Better Approach 
// Time Complexity -> O(N2)
class Solution {
public:
    long subarrayXor(vector<int> &arr, int k) {
        long count = 0;
        int n = arr.size();

        // iterate over all starting points
        for (int i = 0; i < n; i++) {
            int xxor = 0;  // reset XOR for each new subarray starting at i

            // extend subarray from i to j
            for (int j = i; j < n; j++) {
                xxor = xxor ^ arr[j];  // compute XOR of subarray arr[i...j]

                if (xxor == k) {
                    count++;  // valid subarray found
                }
            }
        }

        return count;
    }
};
// ---------------- MAIN FUNCTION ----------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example test case
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;

    Solution sol;
    long result = sol.subarrayXor(arr, k);
    cout << "Number of subarrays with XOR " << k << " is: " << result << endl;

    return 0;
}

// Optimal Approach