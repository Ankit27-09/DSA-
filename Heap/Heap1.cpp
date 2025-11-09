/* Heap --> It is a complete binary tree 
--> All levels are completely filled except possibly the last level, which is filled from left to right.
--> At last level the node should be filled from left side */ 

// Max Heap

// It should be a complete binary tree
// The value of each node should be greater than or equal to the values of its children.
// The element present at the root node should be greater than as compared to the other nodes.
// Parent node ≥ Child nodes
// Min Heap

// It should be a complete Binary Tree
// The value of each node should be less than or equal to the values of children.

// Creation of MAX Heap
//  1. If the parent index is i then the left child index is 2*i + 1 and the right child index is 2*i + 2.
// 2. If the child index i is given then parent will be (i - 1) / 2.

/*

Method 1: Insertion (Top-Down Approach)

Start with an empty array.

Insert elements one by one.

For each insertion:

Place the new element at the end.

Compare with its parent:

If child > parent → Swap (Bubble-up / Heapify-up).

Repeat until heap property is satisfied.

// INSERT THE ELEMENT IN THE ARRAY Last position 
Continue for all elements.
*/

#include <iostream>
using namespace std;

class MaxHeap {
    int * arr;
    int size; // total elements in heap
    int total_size;  // total size of array

    public:

    MaxHeap(int total_size = 100) {
        this->total_size = total_size;
        arr = new int[total_size];
        size = 0;
    }

    // insert in to the heap
    void insert(int value) {
        // If heap size is avalable or not
        if(size == total_size) {
            cout << "Heap is full" << endl;
            return;
        }

        arr[size] = value; // Insert the new element at the end
        int index = size; // Get the index of the newly inserted element
        size++; // Increase the size of the heap

        // compare it with its parent 
        while(index  > 0 && arr[(index - 1) / 2] < arr[index]) {
            swap(arr[index], arr[(index - 1) / 2]); // Swap with parent if child is greater
            index = (index - 1) / 2; // Move to the parent index
        }
        cout << arr[index] << " inserted successfully" << endl;
    }

    void print() {
        cout << "Heap elements are: ";
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }   

    void Heapify(int index) {
        int largest = index; // Initialize largest as root
        int left = 2 * index + 1; // Left child index
        int right = 2 * index + 2; // Right child index
        // Largest will store the index of the element which is largest among root, left child and right child

        // If left child is larger than root
        if(left < size && arr[left] > arr[largest]) {
            largest = left;
        }
        // If right child is larger than largest so far
        if(right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        // If largest is not root, swap and continue heapifying
        if(largest != index) {
            swap(arr[index], arr[largest]);
            Heapify(largest); // Recursively heapify the affected sub-tree
        }
    }
    void deletes() {
        if(size == 0) {
            cout << "Heap is empty, nothing to delete" << endl;
            return;
        }
        cout << arr[0] << " deleted successfully" << endl;
        arr[0] = arr[size - 1]; // Replace root with the last element
        size--; // Decrease the size of the heap
        if(size == 0) {
            return; // If heap is now empty, nothing more to do
        }
        Heapify(0); // Restore the heap property
    }
};

int main() {
    MaxHeap H1(10); // Create a MaxHeap with a total size of 10
    H1.insert(4);
    H1.insert(10);
    H1.insert(7);
    H1.insert(40);
    H1.deletes();
    H1.print(); // Print the heap elements
    return 0;
}

// Deletion operation 
// 1. Remove the root element (the maximum element).
// 2. Replace it with the last element in the heap.
// 3. Decrease the size of the heap.
// 4. Restore the heap property by "bubbling down" the new root element
// TIme Complexity: O(log n) for insertion and deletion operations.
// Heapify -> Heapify refers to the process of rearranging elements within a binary tree (often represented as an array) to satisfy the heap property.

