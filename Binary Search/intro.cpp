// What is Binary Search ??
// prerequisite for binary search is that the array should be sorted in ascending order or descending order.
// Binary search is a searching algorithm that finds the position of a target value within a sorted array.
// It compares the target value to the middle element of the array.
// If the target value is less than the middle element, the search continues in the lower half of the array.
// If the target value is greater than the middle element, the search continues in the upper half of the array.
// This process continues until the target value is found or the search space is empty.
// The time complexity of binary search is O(log n), where n is the number of elements in the array.
// The space complexity is O(1) for the iterative approach and O(log n) for the recursive approach.
// Binary search is more efficient than linear search, especially for large datasets.

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 123;

    int start = 0;
    int end = n - 1;

    while(start <= end) {
        int mid = start + (end - start) / 2; // To avoid overflow
        if(arr[mid] == target) {
            cout << "Element found at index: " << mid << endl;
            return 0; // Element found, exit the program
        } else if(arr[mid] < target) {
            start = mid + 1; // Search in the right half
        } else {
            end = mid - 1; // Search in the left half
        }
    }
    cout << "Element not found" << endl;
    return -1; // Element not found
}