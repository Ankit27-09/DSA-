#include <iostream>
using namespace std;

void insertionSortRecursive(int arr[], int n) {
    if (n <= 1)
        return;

    // Sort first n-1 elements
    insertionSortRecursive(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    // Insert last element into sorted array
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

int main() {
    int arr[] = {5, 4, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSortRecursive(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
