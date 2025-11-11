#include <iostream>
#include <vector>
using namespace std;

// -----------------------------------------------------------
// Function: selectionSort
// Purpose: Sort an array using the Selection Sort algorithm.
// -----------------------------------------------------------
void selectionSort(vector<int>& arr) {
    int n = arr.size();

    // Outer loop – selects each position to fill with the minimum element
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Inner loop – find the index of the smallest element in the remaining array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // Update index of the new minimum
            }
        }

        // Swap the smallest element with the first unsorted element
        swap(arr[minIndex], arr[i]);
    }
}

// -----------------------------------------------------------
// Function: printArray
// Purpose: Print the elements of the array.
// -----------------------------------------------------------
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// -----------------------------------------------------------
// Main function
// -----------------------------------------------------------
int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original array: ";
    printArray(arr); 

    selectionSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
