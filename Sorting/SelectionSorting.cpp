/* What is Selection Sorting?
Selection Sort is a comparison-based sorting algorithm. It sorts an array by repeatedly
 selecting the smallest (or largest) element from the unsorted portion and swapping it with 
 the first unsorted element. This process continues until the entire array is sorted.

First we find the smallest element and swap it with the first element. This way we get the smallest element at its correct position.
Then we find the smallest among remaining elements (or second smallest) and move it to its correct position by swapping.
We keep doing this until we get all elements moved to correct position.

Note:-- If an array has n elements, then number of rounds will be (n - 1).
*/

// Return the index of smallest element.
// #include <iostream>
// using namespace std;

// int main() {
//     int arr[5] = {3,4,1,2,6};
//     int index = 0;
//      for(int i = 1; i < 5; i++) {
//         if(arr[i] < arr[index]) {
//             index = i;
//             cout << index << endl;

//         }
//     }
    
// }

// Selection sorting
#include <iostream>
using namespace std;

int main() {
    int arr[6] = {10, 4, 1, 3, 2, 7};

    // Outer loop iterates through each element
    for(int i = 0; i < 5; i++) {
        int index = i;

        // Inner loop finds the smallest element in the unsorted part of the array
        for(int j = i + 1; j < 6; j++) {
            if(arr[j] < arr[index]) {
                index = j;
            }
        }

        // Swap the smallest element with the first element of the unsorted part
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    } 

    // Print the sorted array
    for(int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
