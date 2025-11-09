// Max Heap Insertion implementation in C++

/*
#include <iostream>
using namespace std;

class MaxHeap
{
public:
    int *arr;
    int size;       // Current size of an array
    int total_size; // Total size of an max heap

public:
    MaxHeap(int total_size)
    {
        this->total_size = total_size;
        arr = new int[total_size];
        size = 0;
    }

    void insert(int x)
    {
        // If heap size is full its will be overflow
        if (size == total_size)
        {
            cout << "Heap Overflow \n";
            return;
        }
        arr[size] = x;
        int index = size;
        size++;

        while (index > 0 && arr[index] > arr[(index - 1) / 2])
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void printHeap()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    MaxHeap h1(100);
    h1.insert(50);
    h1.insert(10);
    h1.insert(100);
    h1.insert(55);
    h1.insert(90);
    h1.printHeap();
} */

// Min Heap Implementation in C++

/*
#include <iostream>
using namespace std;

class MinHeap
{
public:
    int *arr;
    int size;       // Current size of an array
    int total_size; // Total size of an max heap

public:
    MinHeap(int total_size = 100)
    {
        this->total_size = total_size;
        size = 0;
        arr = new int[total_size];
    }

public:
    void insert(int value)
    {
        if (size == total_size)
        {
            cout << "Heap Overflow\n";
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        while (index > 0 && arr[index] < arr[(index - 1) / 2])
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    MinHeap h1;
    h1.insert(5);
    h1.insert(9);
    h1.insert(7);
    h1.insert(2);
    h1.insert(4);
    h1.print();
}
*/

// Deletion in a Max Heap

/*
#include <iostream>
using namespace std;

class MaxHeap {
public:
    int *arr;
    int size;       // Current size of an array
    int total_size; // Total size of an max heap

public:
    MaxHeap(int total_size)
    {
        this->total_size = total_size;
        arr = new int[total_size];
        size = 0;
    }

    void insert(int x)
    {
        // If heap size is full its will be overflow
        if (size == total_size)
        {
            cout << "Heap Overflow \n";
            return;
        }
        arr[size] = x;
        int index = size;
        size++;

        while (index > 0 && arr[index] > arr[(index - 1) / 2])
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapify(int index) {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if(leftChild < size && arr[largest] < arr[leftChild]) {
            largest = leftChild;
        }
        if(rightChild < size && arr[largest] < arr[rightChild]) {
            largest = rightChild;
        }

        if(largest != index) {
            swap(arr[largest], arr[index]);
            heapify(largest);
        }
    }

    void deletion() {
        if(size == 0) {
            cout << "Nothing to delete " << endl;
        }

        arr[0] = arr[size - 1];
        size--;
        heapify(0);
    }

    void printHeap()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    MaxHeap h1(100);
    h1.insert(50);
    h1.insert(10);
    h1.insert(100);
    h1.insert(55);
    h1.insert(90);
    h1.printHeap();
    h1.deletion();
    h1.printHeap();
} 
*/

// Deletion in a Min Heap

/*
#include <iostream>
using namespace std;

class MinHeap {
public:
    int *arr;
    int size;       // Current size of heap
    int total_size; // Capacity

    MinHeap(int total_size = 100) {
        this->total_size = total_size;
        arr = new int[total_size];
        size = 0;
    }

    // Insert a value
    void insert(int value) {
        if (size == total_size) {
            cout << "Heap Overflow\n";
            return;
        }
        arr[size] = value;
        int index = size;
        size++;

        // Bubble up (heapify up)
        while (index > 0 && arr[index] < arr[(index - 1) / 2]) {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    // Heapify down (fix min-heap property)
    void heapify(int index) {
        int smallest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < size && arr[leftChild] < arr[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < size && arr[rightChild] < arr[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            swap(arr[smallest], arr[index]);
            heapify(smallest); // only recurse if swap happened
        }
    }

    // Delete root element (minimum)
    void deletion() {
        if (size == 0) {
            cout << "Nothing to delete\n";
            return;
        }

        cout << "Deleting root: " << arr[0] << endl;

        arr[0] = arr[size - 1]; // Move last element to root
        size--;                 // Reduce size
        heapify(0);             // Fix heap property
    }

    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~MinHeap() {
        delete[] arr;
    }
};

int main() {
    MinHeap h1;
    h1.insert(5);
    h1.insert(9);
    h1.insert(7);
    h1.insert(2);
    h1.insert(4);

    cout << "Heap before deletion: ";
    h1.printHeap();

    h1.deletion();

    cout << "Heap after deleting root: ";
    h1.printHeap();
}
*/

// Check if a given array represents a Min-Heap

/*
#include <iostream>
#include <vector>
using namespace std;

bool isMinHeap(vector<int>& arr, int n) {
    // Check only non-leaf nodes
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // If left child exists and parent > left child → Not a Min-Heap
        if (left < n && arr[i] > arr[left])
            return false;

        // If right child exists and parent > right child → Not a Min-Heap
        if (right < n && arr[i] > arr[right])
            return false;
    }
    return true;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11}; // Example Min-Heap
    int n = arr.size();

    if (isMinHeap(arr, n))
        cout << "YES, it's a Min-Heap" << endl;
    else
        cout << "NO, it's not a Min-Heap" << endl;

    return 0;
}

*/

// Convert a min heap to max heap 

#include <iostream>
#include <vector>
using namespace std;

// Max-Heapify a subtree rooted at index i
void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;           // Initialize largest as root
    int left = 2 * i + 1;      // Left child
    int right = 2 * i + 2;     // Right child

    // If left child exists and is greater than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child exists and is greater than current largest
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root, swap and heapify recursively
    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Convert a Min-Heap array into a Max-Heap
void convertMinToMaxHeap(vector<int>& arr) {
    int n = arr.size();
    // Start from last non-leaf node and heapify each node
    for (int i = (n / 2) - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Print heap array
void printHeap(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> minHeap = {2, 4, 7, 9, 5}; // Min-Heap array

    cout << "Original Min-Heap: ";
    printHeap(minHeap);

    convertMinToMaxHeap(minHeap);

    cout << "Converted Max-Heap: ";
    printHeap(minHeap);

    return 0;
}
