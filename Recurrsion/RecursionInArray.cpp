// Recursion In Array

// 1) Print Array
// This function prints the elements of an array using recursion.
// Here we are printing from the beginning 
// Approach is to print the element and then call the function recursively.
#include <iostream>
using namespace std;

// void printArray(int arr[],int n, int index) {
//     if (index == n) {
//         return;
//     }

//     cout << arr[index] << " ";
//     printArray(arr, n, index + 1);
// }
// int main() {
//     int arr[] = {1, 2, 3, 4, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     printArray(arr, n, 0);
//     cout << endl;
//     return 0;
// }

// 2. Printing in the reverse order 
// Approach is first call the function and then print the element

void printArray(int arr[],int n, int index) {
    if (index == n) {
        return;
    }

    printArray(arr, n, index + 1);
    cout << arr[index] << " ";
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n, 0);
    cout << endl;
    return 0;
}

// 3. Sum of all Element by using recursion 

int sumArr(int arr[], int n, int index) {
    if(n == index) {
        return;
    }
    return arr[index] + sumArr(arr, n, index + 1);  

}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Sum of all elements: " << sumArr(arr, n, 0) << endl;
    return 0;
}


// 4.  Finding the minimum element in an array using recursion

int findMin(int arr[], int n, int index) {
    if (index == n - 1) {
        return arr[index];
    }

    return min(arr[index], findMin(arr, n, index + 1));
}

int main() {
    int arr[] = {5, 2, 8, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum element: " << findMin(arr, n, 0) << endl;
    return 0;
}

// 5. Finding the maximum element in an array using recursion

int maxElement(int arr[], int n, int index) {
    if(index == n - 1) {
        return arr[index];
    }
    return max(arr[index], maxElement(arr, n, index + 1));
}

int main() {
    int arr[] = {5, 2, 8, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum element: " << maxElement(arr, n, 0) << endl;
    return 0;
}