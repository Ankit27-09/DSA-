// Question Link -> https://leetcode.com/problems/merge-sorted-array/

// Brute Force Approach 

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

/*
 Brute-force approach:
 - We create a temporary vector nums3 and merge the first m elements of nums1
   and the n elements of nums2 into nums3 in sorted order (like merge step of merge-sort).
 - After building nums3 we copy its values back into nums1 (first m+n positions).
 - This uses O(m + n) extra space and O(m + n) time.

 Notes:
 - The input constraint for the classic problem (LeetCode 88) is that nums1
   has size m + n and the last n entries are free space (usually zeros) to accommodate nums2.
 - We only read the first m elements of nums1 (indices 0..m-1).
*/
class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Temporary vector to store merged result
        vector<int> nums3;
        nums3.reserve(m + n); // reserve space to avoid repeated reallocations

        int i = 0; // pointer for nums1 (only first m elements)
        int j = 0; // pointer for nums2 (all n elements)

        // Merge while both arrays have remaining elements
        while (i < m && j < n) {
            // Compare current elements and push the smaller one to nums3
            if (nums1[i] < nums2[j]) {
                nums3.push_back(nums1[i]);
                ++i; // consume element from nums1
            } else {
                nums3.push_back(nums2[j]);
                ++j; // consume element from nums2
            }
        }

        // If nums1 still has leftover elements (nums2 finished), append them
        while (i < m) {
            nums3.push_back(nums1[i]);
            ++i;
        }

        // If nums2 still has leftover elements (nums1 finished), append them
        while (j < n) {
            nums3.push_back(nums2[j]);
            ++j;
        }

        // Copy merged result back to nums1
        // nums1 must contain the first (m + n) merged elements after this
        for (int k = 0; k < (int)nums3.size(); ++k) {
            nums1[k] = nums3[k];
        }

        // If you want to be explicit about the tail of nums1 (not necessary):
        // for (int k = nums3.size(); k < (int)nums1.size(); ++k) nums1[k] = 0;
        // But typically, only the first m+n elements matter.
    }
};

/*
 Optimized in-place approach (recommended):
 - Fill nums1 from the back using three pointers.
 - p1 points to the last valid element in the initial part of nums1 (index m-1).
 - p2 points to the last element in nums2 (index n-1).
 - p points to the last position of the merged array in nums1 (index m + n - 1).
 - At each step, place the larger of nums1[p1] and nums2[p2] at nums1[p], then decrease pointers.
 - This avoids extra memory and runs in O(m + n) time and O(1) extra space.

 Why this works:
 - Since nums1 has enough space to hold the merged array, placing elements from
   the end prevents overwriting nums1's elements that are not yet considered.
*/
class SolutionOptimized {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;           // last index of meaningful part of nums1
        int p2 = n - 1;           // last index of nums2
        int p = m + n - 1;        // last index of nums1 overall (target write position)

        // While there are elements in nums2 (or nums1)
        while (p2 >= 0) {
            // If nums1 still has elements and its current element is greater than nums2's,
            // take nums1[p1], else take nums2[p2].
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                --p1;
            } else {
                nums1[p] = nums2[p2];
                --p2;
            }
            --p; // move to next write position to the left
        }

        // No need to copy remaining nums1 elements: they are already in place.
    }
};

/* -------------------------
   Example / quick test
   -------------------------
 To try these functions quickly (not part of a submission on platforms like LeetCode),
 you can use the following main() test:

 Input:
   nums1 = [1,2,3,0,0,0], m = 3
   nums2 = [2,5,6],       n = 3

 Expected final nums1:
   [1,2,2,3,5,6]
*/
int main() {
    // Example test for brute-force class
    vector<int> a1 = {1, 2, 3, 0, 0, 0};
    vector<int> b1 = {2, 5, 6};
    Solution2().merge(a1, 3, b1, 3);
    cout << "Brute-force merged nums1: ";
    for (int x : a1) cout << x << ' ';
    cout << '\n';

    // Example test for optimized class
    vector<int> a2 = {1, 2, 3, 0, 0, 0};
    vector<int> b2 = {2, 5, 6};
    SolutionOptimized().merge(a2, 3, b2, 3);
    cout << "Optimized merged nums1:   ";
    for (int x : a2) cout << x << ' ';
    cout << '\n';

    return 0;
}

// Second Optimal Approach 
// Time Complexity: O((m + n) log(m + n))
// Space Complexity: O(1)
#include <iostream>
#include <vector>
using namespace std;

/*
🧩 PROBLEM STATEMENT:
--------------------
Given two sorted arrays nums1 and nums2, merge them into one sorted array.

nums1 has enough space (size m + n) to hold additional elements from nums2.
The first m elements in nums1 are valid; nums2 has n elements.

Your task:
-----------
Merge nums2 into nums1 as one sorted array (in-place if possible).
*/


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { 
        /*
        nums1 → [1, 4, 7, 8, 10, 0, 0, 0]
                 ↑  valid elements ↑     (extra space for nums2)
                 m = 5

        nums2 → [2, 3, 9]
                 n = 3
        */

        int left = m - 1;  // pointer to the last valid element in nums1 (index = m-1)
        int right = 0;     // pointer to the first element in nums2 (index = 0)

        /*
        🔹 Step 1: Swap elements that are out of order.
        ------------------------------------------------
        If nums1[left] > nums2[right], it means an element from nums1 
        should actually belong to nums2 (because nums1 has a bigger element
        that should come later in sorted order).

        So we swap them and move the pointers inward.
        */

        while (left >= 0 && right < n) {
            // Compare the largest (nums1[left]) and smallest (nums2[right])
            if (nums1[left] > nums2[right]) {
                swap(nums1[left], nums2[right]);  // bring smaller to nums1 and larger to nums2
                left--;   // move left pointer leftwards
                right++;  // move right pointer rightwards
            } 
            else {
                // If nums1[left] <= nums2[right], 
                // both arrays are already in correct relative order.
                break;
            }
        }

        /*
        🔹 Step 2: Sort both arrays again
        ----------------------------------
        After swapping, some elements might be out of place inside nums1 or nums2.
        Sorting them individually restores their internal order.

        Example after swapping:
            nums1 = [1, 4, 7, 3, 2]
            nums2 = [10, 8, 9]
        After sorting:
            nums1 = [1, 2, 3, 4, 7]
            nums2 = [8, 9, 10]
        */
        sort(nums1.begin(), nums1.begin() + m);  // sort only first 'm' elements
        sort(nums2.begin(), nums2.end());        // sort full nums2

        /*
        🔹 Step 3: Copy nums2 elements into nums1’s extra space
        --------------------------------------------------------
        Now nums1 has its smallest half sorted, and nums2 has the larger half.
        The remaining 'n' slots in nums1 are reserved for nums2’s elements.
        */
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];  // place nums2[i] into the empty tail of nums1
        }

        /*
        🔹 Final nums1 result:
        -----------------------
        nums1 = [1, 2, 3, 4, 7, 8, 9, 10]
        */
    }
};


int main() {
    // Example run to understand behavior
    Solution obj;

    vector<int> nums1 = {1, 4, 7, 8, 10, 0, 0, 0}; // nums1 has space for nums2
    vector<int> nums2 = {2, 3, 9};
    int m = 5, n = 3;

    obj.merge(nums1, m, nums2, n);

    // Print merged nums1
    cout << "Merged nums1: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;

    return 0;
}

/*
🧠 COMPLEXITY ANALYSIS:
------------------------
Step 1: While loop → O(min(m, n))  (swap phase)
Step 2: Sorting → O(m log m + n log n)
Step 3: Copy → O(n)

✅ Overall Time Complexity: O((m + n) log(m + n))
✅ Space Complexity: O(1)   (in-place sort)

🧩 Notes:
----------
- Works well for moderate input sizes.
- Fully in-place (doesn’t create a large temporary array).
- Easier to understand conceptually than the two-pointer optimal merge.

⚡ For larger arrays:
Prefer the two-pointer “merge from the end” approach 
for O(m + n) time.
*/
