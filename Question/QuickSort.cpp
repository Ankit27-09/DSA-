#include <iostream>
#include <vector>
using namespace std;

/*
------------------------
 FUNCTION: partition()
------------------------
This function is responsible for placing the pivot element
at its correct position in the sorted array.

Logic:
1. Choose the last element (arr[end]) as the pivot.
2. Initialize an index (idx) that will mark the correct position
   for elements smaller than the pivot.
3. Traverse from start to end-1:
      - If the current element is smaller than pivot,
        increment idx and swap arr[idx] with arr[j].
4. After the loop, swap pivot (arr[end]) with arr[idx+1]
   so that pivot is placed in its correct sorted position.
5. Return (idx + 1) → the final pivot index.
*/

int partition(vector<int>& arr, int start, int end) {
    int idx = start - 1;         // Index of smaller element
    int pivot = arr[end];        // Choosing pivot as last element

    // Traverse from start to end-1
    for (int j = start; j <= end - 1; j++) {
        // If current element is smaller than pivot
        if (arr[j] < pivot) {
            idx++;               // Increment index for smaller element
            swap(arr[idx], arr[j]); // Swap elements
        }
    }

    // Place pivot at its correct position
    swap(arr[idx + 1], arr[end]);

    // Return the pivot index (position where pivot finally lies)
    return (idx + 1);
}

/*
------------------------
 FUNCTION: quickSort()
------------------------
Recursive function to sort an array using the Quick Sort algorithm.

Logic:
1. Base case → if start >= end, the array has 1 or 0 elements → already sorted.
2. Otherwise:
   - Partition the array → pivot will be placed at correct position.
   - Recursively sort:
       a) Elements before pivot (left subarray)
       b) Elements after pivot (right subarray)
*/

void quickSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        // Partition the array → get pivot index
        int pivotIdx = partition(arr, start, end);

        // Recursively sort elements before and after pivot
        quickSort(arr, start, pivotIdx - 1);   // Left subarray
        quickSort(arr, pivotIdx + 1, end);     // Right subarray
    }
}

/*
------------------------
 FUNCTION: main()
------------------------
Driver code:
1. Create an example vector.
2. Call quickSort() on entire array.
3. Print the sorted result.
*/

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    cout << "Original array: ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    // Call Quick Sort on full range
    quickSort(arr, 0, n - 1);

    cout << "Sorted array:   ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    return 0;
}
