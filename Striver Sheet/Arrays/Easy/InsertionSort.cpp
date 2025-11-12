#include <iostream>
#include <vector>
using namespace std;

// -----------------------------------------------------------
// Function: insertionSort
// Purpose: Sort an array using Insertion Sort (two for loops)
// -----------------------------------------------------------
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    // Outer loop: pick each element starting from index 1
    for (int i = 1; i < n; i++) {
        // Inner loop: shift elements to the right to insert arr[i] at correct position
        for (int j = i; j > 0; j--) {
            // If the current element is smaller than its previous one → swap them
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            }
            else {
                // If it's already in correct order, stop shifting
                break;
            }
        }
    }
}

// -----------------------------------------------------------
// Function: printArray
// Purpose: Print the elements of the array.
// -----------------------------------------------------------
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// -----------------------------------------------------------
// Main function
// -----------------------------------------------------------
int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array: ";
    printArray(arr);

    insertionSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
