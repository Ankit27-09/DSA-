// What is quick Sort?
// QuickSort is a sorting algorithm based on the Divide and Conquer that picks an element as a pivot 
//and partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array.

/*There are mainly three steps in the algorithm:

Choose a Pivot: Select an element from the array as the pivot. The choice of pivot can vary (e.g., first element, last element, random element, or median).
Partition the Array: Rearrange the array around the pivot. After partitioning, all elements smaller than the pivot will be on its left, and all elements greater than the pivot will be on its right. The pivot is then in its correct position, and we obtain the index of the pivot.
Recursively Call: Recursively apply the same process to the two partitioned sub-arrays (left and right of the pivot).
Base Case: The recursion stops when there is only one element left in the sub-array, as a single element is already sorted. */


/* Always pick the first (or last) element as a pivot. The below implementation picks the last element as pivot. The problem with this approach is it ends up in the worst case when array is already sorted.
Pick a random element as a pivot. This is a preferred approach because it does not have a pattern for which the worst case happens.
Pick the median element is pivot. This is an ideal approach in terms of time complexity as we can find median in linear time and the partition function will always divide the input array into two halves. But it takes more time on average as median finding has high constants.*/


// Divide and Conquer Algorithm is a problem-solving technique used to solve problems by dividing the main problem into subproblems,
// solving them individually and then merging them to find solution to the original problem. Divide and Conquer is mainly useful when we divide a problem into independent subproblems. 

#include <iostream>
using namespace std;

int partition(int arr[], int start, int end) {
    int pivot = arr[end];  // Choosing last element as pivot
    int pos = start;  

    for (int i = start; i < end; i++) {
        if (arr[i] <= pivot) {  
            swap(arr[i], arr[pos]);
            pos++;
        }
    }
    swap(arr[pos], arr[end]);  // Move pivot to its correct position
    return pos;  // Return the correct pivot position
}

void quickSort(int arr[], int start, int end) {
    if (start < end) {  // Fixing base condition
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot - 1);  // Sort left subarray
        quickSort(arr, pivot + 1, end);  // Sort right subarray
    }
}

int main() {
    int arr[] = {10, 3, 4, 1, 5, 6, 3, 2, 11, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
