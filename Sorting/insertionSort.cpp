/*Insertion sort is a simple sorting algorithm that works by iteratively inserting each element of an unsorted list into its correct position in a sorted portion of the list. It is like sorting playing cards in your hands. You split the cards into two groups: the sorted cards and the unsorted cards. Then, you pick a card from the unsorted group and put it in the right place in the sorted group.

We start with the second element of the array as the first element is assumed to be sorted.
Compare the second element with the first element if the second element is smaller then swap them.
Move to the third element, compare it with the first two elements, and put it in its correct position
Repeat until the entire array is sorted.

Complexity Analysis of Insertion Sort
Time Complexity

Best case: O(n), If the list is already sorted, where n is the number of elements in the list.
Average case: O(n2), If the list is randomly ordered
Worst case: O(n2), If the list is in reverse order
Space Complexity

Auxiliary Space: O(1), Insertion sort requires O(1) additional space, making it a space-efficient sorting algorithm.
*/



#include <iostream> 
using namespace std;

int main() {
    int arr[] = {10, 3, 4, 1, 5, 6, 3, 2, 11, 9}; // Sample array to be sorted
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    for(int i = 0; i < n; i++) {
        for(int j = i; j > 0; j--) {
            if(arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]); // Swap the elements if they are in the wrong order
            } 
            else {
                break; // If the current element is in the correct position, break out of the inner loop
            }
        }     
    }
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Print the sorted array
    }
    cout << endl; // Print a newline for better readability
}