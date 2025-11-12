// Question Link -> https://leetcode.com/problems/sort-an-array/
#include <iostream>
#include <vector>
using namespace std;

// 🧩 Function to merge two sorted halves of the array
void merge(vector<int>& arr, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    vector<int> temp;

    // Merge elements from both halves into temp
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy remaining elements from left half
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements from right half
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy sorted elements back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// 🧠 Recursive Merge Sort function
void mergeSort(vector<int>& arr, int low, int high) {
    // Base case: stop when subarray has 1 element
    if (low < high) {
        int mid = low + (high - low) / 2;

        // Sort the left half
        mergeSort(arr, low, mid);

        // Sort the right half
        mergeSort(arr, mid + 1, high);

        // Merge the two sorted halves
        merge(arr, low, mid, high);
    }
}

// 📜 Helper function to print the array
void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 🚀 Main function
int main() {
    vector<int> arr = {70, 30, 50, 10};

    cout << "Original array: ";
    printArray(arr);

    // Call mergeSort on full range (0 to n-1)
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
