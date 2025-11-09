// Step down Approach for building a Heap
// Time Complexity: O(n log n)
// Space Complexity: O(1)
// Step1 Approach already done in heap1.cpp

// Method2: Build Heap (Bottom-Up Approach)
// Time complexity: O(n)
// space complexity: O(1)

// Step Down Approach for building a Heap
// Time Complexity: O(n)
// Space Complexity: O(logn)

/*

#include <iostream>
using namespace std;

class BuildHeap {
    int *arr;
    int size;        // total elements in heap
    int total_size;  // capacity of array

public:
    BuildHeap(int total_size = 100) {
        this->total_size = total_size;
        arr = new int[total_size];
        size = 0;
    }

    // Insert element (does not maintain heap property yet)
    void insert(int value) {
        if (size == total_size) {
            cout << "Heap is full" << endl;
            return;
        }
        arr[size] = value; // Insert at the end
        size++;
    }

    void print() {
        cout << "Heap elements are: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void Heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(arr[index], arr[largest]);
            Heapify(largest);
        }
    }

    void buildHeap() {
        // Start from last non-leaf node down to root
        for (int i = (size / 2) - 1; i >= 0; i--) {
            Heapify(i);
        }
    }

    // Optional: Extract maximum element (root)
    int extractMax() {
        if (size <= 0) {
            cout << "Heap is empty" << endl;
            return -1;
        }
        if (size == 1) {
            size--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[size - 1]; // Move last element to root
        size--;
        Heapify(0); // Restore heap property
        return root;
    }
};

int main() {
    BuildHeap heap;

    // Insert elements (unordered)
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(6);
    heap.insert(1);
    heap.insert(8);
    heap.insert(9);
    heap.insert(4);

    cout << "Before building heap:" << endl;
    heap.print();

    heap.buildHeap();

    cout << "After building heap (Step Down):" << endl;
    heap.print();

    cout << "Extracting max: " << heap.extractMax() << endl;
    cout << "Heap after extractMax:" << endl;
    heap.print();

    return 0;
}
*/

// Heap Sort
// Heap sort is a comparison-based sorting technique based on Binary Heap Data Structure. 
// It is similar to selection sort where we first find the maximum element and place the maximum element at the end.
// We repeat the same process for the remaining elements.
//  It can be seen as an optimization over selection sort where we first find the max (or min) element and swap it with the last (or first).
// In Heap Sort, we use Binary Heap so that we can quickly find and move the max element in O(Log n) instead of O(n) and hence achieve the O(n Log n) time complexity.

// First convert the array into a max heap using heapify, Please note that this happens in-place.

//Then one by one delete the root node of the Max-heap and replace it with the last node and heapify. 
// Repeat this process while size of heap is greater than 1.

// Rearrange array elements so that they form a Max Heap.
// Repeat the following steps until the heap contains only one element:
// Swap the root element of the heap (which is the largest element in current heap) with the last element of the heap.
// Remove the last element of the heap (which is now in the correct position). We mainly reduce heap size and do not remove element from the actual array.
// Heapify the remaining elements of the heap.
// Finally we get sorted array.

#include <iostream>
using namespace std;
#include <vector>

void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left child
    int right = 2 * i + 2; // right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify the affected sub-tree
    }

}

void printArray(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}
int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();
    // 1. Build Max heap from the array
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // 2. One by one extract elements from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
    cout << "Sorted array is \n";
    printArray(arr);
}