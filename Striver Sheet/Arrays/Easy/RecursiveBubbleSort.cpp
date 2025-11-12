#include <iostream>
#include <vector>
using namespace std;

/*
    ----------------------------------------------
              RECURSIVE BUBBLE SORT
    ----------------------------------------------

    🔹 Idea:
       - Bubble Sort compares adjacent elements and swaps them if they are in the wrong order.
       - After one full pass, the largest element "bubbles up" to the last position.
       - Then, we recursively sort the remaining (n-1) elements.

    🔹 Base Case:
       - If the size of the array (n) is 1, then it’s already sorted — so stop recursion.

    🔹 Recursive Case:
       - Perform one pass of Bubble Sort on the first n elements.
       - This will move the largest element of the current unsorted part to the end.
       - Then call bubbleSort() again for the first (n-1) elements.
*/

// Recursive function to perform Bubble Sort
void bubbleSort(vector<int>& arr, int n) {
    // Base Case: If there's only one element left, stop
    if (n == 1)
        return;

    // 🔹 One pass of Bubble Sort
    // After this loop, the largest element among arr[0...n-1]
    // will be placed at arr[n-1]
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            // Swap if elements are out of order
            swap(arr[i], arr[i + 1]);
        }
    }

    // 🔹 Recursive call:
    // Call bubbleSort for the first (n-1) elements
    bubbleSort(arr, n - 1);
}

int main() {
    // Example array
    vector<int> arr = {5, 1, 4, 2, 8};

    cout << "Original Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    // Function call
    bubbleSort(arr, arr.size());

    cout << "\nSorted Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    /*
        ----------------------------------------------
                    DRY RUN EXPLANATION
        ----------------------------------------------

        Input: [5, 1, 4, 2, 8]

        🔸 Pass 1:
            Compare (5,1) -> swap -> [1,5,4,2,8]
            Compare (5,4) -> swap -> [1,4,5,2,8]
            Compare (5,2) -> swap -> [1,4,2,5,8]
            Compare (5,8) -> ok    -> [1,4,2,5,8]
            Largest element 8 is now in its correct place

        🔸 Pass 2 (on first 4 elements):
            Compare (1,4) -> ok
            Compare (4,2) -> swap -> [1,2,4,5,8]
            Compare (4,5) -> ok
            Largest of remaining (5) placed correctly

        🔸 Pass 3:
            Compare (1,2) -> ok
            Compare (2,4) -> ok
            No swaps needed, array is sorted.

        ✅ Final Output: [1, 2, 4, 5, 8]
    */

    return 0;
}

/*
    ----------------------------------------------
                    TIME COMPLEXITY
    ----------------------------------------------
    🔹 Best Case (Already Sorted): O(n²)
    🔹 Worst Case: O(n²)
    🔹 Average Case: O(n²)

    ----------------------------------------------
                    SPACE COMPLEXITY
    ----------------------------------------------
    🔹 O(n) due to recursive call stack
    🔹 Sorting is done in-place (no extra array)
*/
