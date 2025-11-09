#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr, int n) {
    for(int i = 1; i < n; i++) {
        int index = i;
        // Fix: decrement j instead of incrementing i
        for(int j = i - 1; j >= 0; j--) {
            if(arr[index] < arr[j]) {
                swap(arr[index], arr[j]);
                index = j; // update index after swap
            } else {
                // No need to continue if current element is in correct position
                break;
            }
        }
    }
}

int main() {
    cout << "Insertion Sort: " << endl;
    vector<int> arr = {4, 1, 5, 2, 3};
    insertionSort(arr, arr.size());

    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
