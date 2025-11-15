// Question Link -> https://www.geeksforgeeks.org/problems/second-largest3735/1

// This is the most optimal approach to find the second largest element in an array.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getSecondLargest(vector<int> &arr) {

        int n = arr.size();

        // If array contains less than 2 elements,
        // a second largest number CANNOT exist.
        if (n < 2) return -1;

        // Initialize largest and second largest.
        // INT_MIN ensures any real value will override it.
        int largest = INT_MIN;
        int second_largest = INT_MIN;

        // -----------------------------------------
        // SINGLE-PASS TRAVERSAL (O(N))
        // -----------------------------------------
        for (int num : arr) {

            // Case 1: Found a NEW largest number
            // Example:
            // largest = 10, second_largest = 8
            // num = 12 → now:
            // largest = 12, second_largest = 10
            if (num > largest) {
                second_largest = largest;  // Previous largest becomes second largest
                largest = num;             // Update new largest value
            }

            // Case 2: num is smaller than 'largest' but greater than 'second_largest'
            // Example:
            // largest = 12, second_largest = 10
            // num = 11 → now second_largest = 11
            else if (num < largest && num > second_largest) {
                second_largest = num;
            }

            // Case 3: num == largest or num <= second_largest
            // → do nothing (ignore duplicates of largest)
        }

        // If second_largest never changed from INT_MIN,
        // it means no valid second largest exists.
        // Example: [7, 7, 7] or [5, 5]
        if (second_largest == INT_MIN) {
            return -1;
        }

        return second_largest;
    }
};

int main() {

    vector<int> arr = {10, 5, 8, 10, 3};

    Solution obj;
    int ans = obj.getSecondLargest(arr);

    cout << "Second Largest Element: " << ans << endl;

    return 0;
}


// Optimised Approach 

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getSecondLargest(vector<int> &arr) {

        int n = arr.size();

        // If there are less than 2 elements,
        // second largest does NOT exist.
        if (n < 2) return -1;

        // -------------------------------------
        // STEP 1: FIND THE MAXIMUM ELEMENT
        // -------------------------------------

        // Assume the first element is the maximum
        int maxi = arr[0];

        // Traverse the array from index 1 to n-1
        // and update maxi whenever we find a bigger value
        for (int i = 1; i < n; i++) {
            if (arr[i] > maxi) {
                maxi = arr[i];  // Update maximum
            }
        }

        // -------------------------------------
        // STEP 2: FIND THE SECOND LARGEST ELEMENT
        // -------------------------------------

        // Initialize second largest with INT_MIN
        // INT_MIN ensures any real value can replace it.
        int second_largest = INT_MIN;

        for (int i = 0; i < n; i++) {

            // We IGNORE all elements equal to the maximum,
            // because second largest must be STRICTLY smaller.
            if (arr[i] != maxi) {

                // Update second largest if we find a bigger valid value
                if (arr[i] > second_largest) {
                    second_largest = arr[i];
                }
            }
        }

        // -------------------------------------
        // STEP 3: CHECK IF SECOND LARGEST EXISTS
        // -------------------------------------

        // If second_largest is still INT_MIN,
        // it means all elements were equal to maxi.
        // Example: [7, 7, 7] → no second largest
        if (second_largest == INT_MIN) {
            return -1;
        }

        // Return the valid second largest number
        return second_largest;
    }
};

int main() {

    vector<int> arr = {10, 5, 8, 10, 3};

    Solution obj;
    int ans = obj.getSecondLargest(arr);

    cout << "Second Largest Element: " << ans << endl;

    return 0;
}



// Brute Force Approach 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getSecondLargest(vector<int> &arr) {

        // ------------------------------
        // BRUTE FORCE APPROACH
        // ------------------------------

        // STEP 1: Sort the array in decreasing order.
        // sort(arr.begin(), arr.end(), greater<int>())
        // --> This sorts the array from largest to smallest.
        // Example: [1, 5, 3, 5] becomes [5, 5, 3, 1].
        //
        // Time Complexity of sort = O(N log N)
        sort(arr.begin(), arr.end(), greater<int>());

        // After sorting, the largest element is always at index 0.
        int maxi = arr[0];

        // STEP 2: Traverse the sorted array to find the second largest.
        // We skip all elements equal to the maximum.
        // Example: If array = [5, 5, 3, 1]
        // maxi = 5
        // We skip two 5's and return 3.
        for (int i = 0; i < arr.size(); i++) {

            // If current element is equal to the max,
            // skip it because we want a value strictly smaller than maxi.
            if (arr[i] == maxi) {
                continue;
            }
            else {
                // The first element smaller than maxi is the second largest.
                return arr[i];
            }
        }

        // If we reach this line, it means
        // all elements in the array are equal (example: [7, 7, 7]).
        // Therefore, second largest does not exist.
        return -1;
    }
};

int main() {
    vector<int> arr = {10, 5, 8, 10, 3};

    Solution obj;
    int ans = obj.getSecondLargest(arr);

    cout << "Second Largest Element: " << ans << endl;

    return 0;
}

